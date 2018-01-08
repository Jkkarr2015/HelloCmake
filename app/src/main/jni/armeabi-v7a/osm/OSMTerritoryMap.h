//
// Created by jkarr on 12/28/2017.
//

#include <iostream>
#include <fstream>
#include <sstream>
#import <string>
#include <vector>
#include "osmformat.pb.h"
#include "fileformat.pb.h"

class OSMTerritoryMap{

    //Member Functions

    int gridIndexForLatLon(::google::protobuf::int64 lat, ::google::protobuf::int64 lon);
};