//
// Created by jkarr on 11/22/2017.
//
#pragma once
#include <string>
#include <vector>
#include "Location.h"
class Geopoint {
protected:
    std::string mName;
    double mDistance;
    double mBearing;
    Location mLocation;

public:
    //member functions
    Geopoint();//Default Constructor
    Geopoint(const Geopoint& point);//Copy Constructor
	std::string getName() {return mName;}
	double getDistance() {return mDistance;}
	double getBearing() {return mBearing;}
	Location getLocation() {return mLocation;}
	void setName(std::string newName) {mName = newName;}
	void setDistance(double newDistance) {mDistance = newDistance;}
	void setBearing(double newBearing) {mBearing = newBearing;}
	void setLocation(Location newLocation) {mLocation = newLocation;}
};
