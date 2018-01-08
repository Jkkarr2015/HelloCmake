//
// Created by jkarr on 12/28/2017.
//

#include "OSMTerritoryMap.h"

using namespace std;

//a map to the territory to load based on lon,lat
vector<vector<int>> vvlTerritory;

//a map to the territory to load based on a compressed lon,lat map
vector<vector<int>> vvlcTerritory;


//the bottom right corner, width and height covered
::google::protobuf::int64 iLonMin;
::google::protobuf::int64 iLatMin;
::google::protobuf::int64 iWidth;
::google::protobuf::int64 iHeight;
::google::protobuf::int64 iResolution;
::google::protobuf::int64 iLineLength;
::google::protobuf::int64 iHeaderLength;


void OpenTerritoryMap3 () {
    string path; //Don't know what to do with this yet

    if(path.empty()){
        return;//no file
    }

    fstream input (path, ios::in | ios::binary );

    if(!input.is_open()){
        return;
    }

    input.seekg(0,std::ios::end);

    input.seekg(0, std::ios::beg);

    long lCountDown=1024*1024;
    long iLineNum=0;
    std::string line;
    while (std::getline(input, line))
    {
        stringstream as(line);



        if(iLineNum==0)
            as >> iLonMin;
        if(iLineNum==1)
            as >> iLatMin;
        if(iLineNum==2)
            as >> iWidth;
        if(iLineNum==3)
            as >> iHeight;
        if(iLineNum==4)
        {
            //long lfp = input.tellg();
            as >> iResolution;
        }
        if(iLineNum==5)
        {
            long lfp = input.tellg();
            as >> iLineLength;
            iHeaderLength = lfp;
        }
        if(iLineNum>5)
        {
            //long lfp = input.tellg();
            //long ldebug1=0;
            break;
        }

        /*
        if(iLineNum>4)
        {
            std::istringstream is( line );
            //vvlTerritory.push_back(std::vector<int>( std::istream_iterator<int>(is),std::istream_iterator<int>() ) );
            vvlcTerritory.insert(vvlcTerritory.begin(), std::vector<int>( std::istream_iterator<int>(is),std::istream_iterator<int>() ) );
        }
         */

        iLineNum++;
        lCountDown--;
        if(lCountDown<=0){
            // cout << iLineNum << endl;
            lCountDown=1024*1024;
        }
    }

    input.close();

}//end OpenTerritoryMap3

int OSMTerritoryMap::gridIndexForLatLon(::google::protobuf::int64 lat,
                                        ::google::protobuf::int64 lon) {
    string path;

    if(path.empty())
        return 0;

    fstream input(path, ios::in | ios::binary);

    if(!input.is_open())
        return -1; //no grid file

    long long iX = (lon - iLonMin ) / iResolution + 1;
    long long iY = (lat - iLatMin ) / iResolution + 1;

    //error out of range
    long lFilePos = iY*iLineLength+iHeaderLength;
    input.seekg(0, std::ios::end);
    long fileSize2 = input.tellg();

    if(lFilePos>fileSize2)
        return -1;

    input.seekg(lFilePos, std::ios::beg);
    string as;
    std::getline(input, as);
    stringstream al(as);
    vector <int> viline = std::vector<int>( std::istream_iterator<int>(al),std::istream_iterator<int>() );
    int iTerritoryIndex=0;
    for(int x=0;(x+1)<viline.size();x+=2)
    {
        //>= or > ?
        if(iX>=viline.at(x))
            iTerritoryIndex=viline.at(x+1);
        else
            break;
    }

    return iTerritoryIndex;

}//end gridIndexForLatLon