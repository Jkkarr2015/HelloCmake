//
// Created by jkarr on 12/29/2017.
//

#include "RGResult.h"


RGResult::RGResult()
{
    country = "";
    mState = "";
    county = "";
    city = "";
    neighborhood = "";
    street = "Unknown";
    altStreet = "";
    streetNum = "";
    zipCode = "";
    Coordinate2D r1;
    r1.latititude = 0;
    r1.longitude = 0;
    resolvedLocation = r1;

}