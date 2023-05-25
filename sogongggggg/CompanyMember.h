#pragma once
#include "Member.h"
#include "Info.h"


class CompanyMember : public Member {
private:
	string companyName;
	int companyID;
	Info recruitInfo;
public:
	CompanyMember(int inputType, string inputName, int inputNum, string inputID, string inputPassword) {
		Type = inputType;
		companyName = inputName;
		companyID = inputNum;
		ID = inputID;
		Password = inputPassword;
	}
	virtual void setInfo(string Work, int numOfPeople, string Date) {
		recruitInfo = Info(Work, numOfPeople, Date);
		recruitInfo.setCompanyID(companyID);
		recruitInfo.setCompanyName(companyName);
	}

    virtual Info getInfo() {
		return recruitInfo;
	}
	virtual string getName() {
		return companyName;
	}
	virtual int getNum() {
		return companyID;
	}

};
