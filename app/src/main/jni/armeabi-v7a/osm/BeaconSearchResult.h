//
// Created by jkarr on 12/11/2017.
//

#include <string>


struct Beacon{
protected:
    std::string UUID;
    unsigned short major;
    unsigned short minor;
    double lat;
    double lon;
    std::string name;
    std::string type;
    float level;
    double distance;

public:
	std::string getUUID() {return UUID;}
	unsigned short getMajor() {return major;}
	unsigned short getMinor() {return minor;}
	double getLat() {return lat;}
	double getLon() {return lon;}
	std::string getName() {return name;}
	std::string getType() {return type;}
	float getLevel() {return level;}
	double getDistance() {return distance;}
	
	void setUUID(std::string newUUID) {UUID = newUUID;}
	void setMajor(unsigned short newMajor) {major = newMajor;}
	void setMinor(unsigned short newMinor) {minor = newMinor;}
	void setLat(double newLat) {lat = newLat;}
	void setLon(double newLon) {lon = newLon;}
	void setName(std::string newName) {name = newName;}
	void setType(std::string newType) {type = newType;}
	void setLevel(float newLevel) {level = newLevel;}
	void setDistance(double newDistance) {distance = newDistance;}
	
	
};
