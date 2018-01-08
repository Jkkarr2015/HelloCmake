//
// Created by jkkarr on 11/22/2017.
//
#pragma once
#include "Geopoint.h"

class POI: public Geopoint{
protected:
    long long mDbId;
    std::string mAddress;
    std::string mPhone;
    std::string mWebsite;
    std::string mId;
    std::vector <std::string> mTypes;
    std::string mPrimaryType;
    std::string mProvider;
    int mFloor;
    double mAlarmRadius;
    bool mIsNew;
    bool mFavorite;
    bool mTransitStop;
    long long mModTime;
    bool mFetchedDetails;
    std::string mScope;

public:
    POI();//Default Constructor
    POI(const POI& poi);//Copy Constructor

    //Member Functions
    std::string primaryType();
    std::string getDescription();
    bool isEqualToPOI(POI other);
    bool isEqual(POI other);
    void makeId();
	long long getDbId() {return mDbId;}
	std::string getAddress() {return mAddress;}
	std::string getPhone() {return mPhone;}
	std::string getWebsite() {return mWebsite;}
	std::string getId() {return mId;}
	std::vector<std::string> getTypes() {return mTypes;}
	std::string getPrimaryType() {return mPrimaryType;}
	std::string getProvider() {return mProvider;}
	int getFloor() {return mFloor;}
	double getAlarmRadius() {return mAlarmRadius;}
	bool getIsNew() {return mIsNew;}
	bool getFavorite() {return mFavorite;}
	bool getTransitStop() {return mTransitStop;}
	long long getModTime() {return mModTime;}
	bool getFetchDetails() {return mFetchedDetails;}
	std::string getScope() {return mScope;}
	const void setDbId(long newDbId) {mDbId = newDbId;}
	void setAddress(std::string newAddress) {mAddress = newAddress;}
	void setPhone(std::string newPhone) {mPhone = newPhone;}
	void setWebsite(std::string newWebsite) {mWebsite = newWebsite;}
	void setId(std::string newId) { mId = newId;}
	void setTypes(std::vector<std::string> newTypes) {mTypes = newTypes;}
	void setPrimaryType(std::string newPrimaryType) {mPrimaryType = newPrimaryType;}
	void setProvider(std::string newProvider) {mProvider = newProvider;}
	void setFloor(int newFloor) {mFloor = newFloor;}
	void setAlarmRadius(double newAlarmRadius) {mAlarmRadius = newAlarmRadius;}
	void setIsNew(bool newIsNew) {mIsNew = newIsNew;}
	void setFavorite(bool newFavorite) {mFavorite = newFavorite;}
	void setTransitStop(bool newTransitStop) {mTransitStop = newTransitStop;}
	void setModTime(long long newModTime) {mModTime  = newModTime;}
	void setFetchDetails(bool newFetchedDetails) {mFetchedDetails = newFetchedDetails;}
	void setScope(std::string newScope) {mScope = newScope;}
	
};


