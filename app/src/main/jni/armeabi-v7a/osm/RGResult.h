//
// Created by jkarr on 12/29/2017.
//

#import<string>
#import<vector>


using namespace std;

class RGResult{
    //Member Variables
    string country;
    int countryId;
    string countryTitle;
    string countryCode;
    string mState;
    int stateId;
    string stateTitle;
    string county;
    int countyId;
    string countyTitle;
    string city;
    int cityId;
    string cityTitle;
    string neighborhood;
    int neighborhoodId;
    string neighborhoodTitle;
    string street;
    string altStreet;
    int streetId;
    string streetTitle;
    string streetNum;
    string streetNumTitle;
    string zipCode;
    int zipcodeId;

    struct Coordinate2D {
        double longitude;
        double latititude;
    };

    Coordinate2D resolvedLocation;
    vector<int> levelIds;

    //Member Functions
    RGResult();
};