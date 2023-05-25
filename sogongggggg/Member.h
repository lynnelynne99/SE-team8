#pragma once
#include <string>
#include <vector>
#include "Info.h"

using namespace std;


class Member {
protected:
	int Type;
	string ID;
	string Password;
	int State = 0;
public:
	void setState(int state) {
		State = state;
	}
	int getState() {
		return State;
	}
	string getID() {
		return ID;
	}
	string getPassword() {
		return Password;
	}
	virtual void setInfo(string Work, int numOfPeople, string Date) {}

	virtual void setInfo(string companyName, int companyID, string Work, int numOfPeople, string Date) {}

	virtual Info getInfo() { 
		Info Info;
		return Info; 
	}
	virtual Info getInfo(int inputCompanyID) {
		Info Info;
		return Info;
	}
	
	virtual string getName() {
		string Name;
		return Name;
	}
	virtual int getNum() {
		int Num = 0;
		return Num;
	}
	virtual vector<Info> getInfoList() {
		vector<Info> InfoList;
		return InfoList;
	}
	int getType() {
		return this->Type;
	}
};

