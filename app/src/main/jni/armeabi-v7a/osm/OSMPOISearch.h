//
// Created by jkkarr on 11/22/2017.
//

#include "Location.h"
#include <regex>
#include "POI.h"
using namespace std;

class OSMPOISearch {
protected:
    bool filterUndesirables;
    bool isRunning;
    double radius;
    int limit;
    bool searchResult;
    std::regex rgx;
    


public:
    //Member Functions
    OSMPOISearch();
    bool isLevelinRange(double level, string strRange);
    bool isPOISimilarToPOI(POI a, POI b);
    vector<POI> searchPOIpreproc (Location loc ,string searchString ,double radius, int limit ,double level ,bool sortResults);
    void search(Location loc, string searchString, double radius, int limit, double level, bool sortResults);
    void beaconSearch(Location *loc, double radius, int limit, bool sortResults);
	bool getFilterUndesirables() {return filterUndesirables;}
	bool getIsRunning() {return isRunning;}
	double getRadius() { return radius;}
	int getLimit() {return limit;}
	bool getSearchResult() {return searchResult;}
	std::regex getRegex() {return rgx;}
	void setFilterUndesirables(bool filter) {filterUndesirables = filter;}
	void setIsRunning(bool running) {isRunning = running;}
	void setRadius(double newRad) { radius = newRad;}
	void setLimit(int newLimit) {limit = newLimit;}
	void setSearchResult(bool newSearchResult) {searchResult = newSearchResult;}
	void setRegex(std::regex newRgx) {rgx = newRgx;}
	

};