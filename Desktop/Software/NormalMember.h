#pragma once
#include <vector>
#include "Member.h"
#include "Info.h"


class NormalMember : public Member {
private:
	string Name;
	int Identity;
	vector<Info> applyList;
public:
	NormalMember(int inputType, string inputName, int inputNum, string inputID, string inputPassword) {
		Type = inputType;
		Name = inputName;
		Identity = inputNum;
		ID = inputID;
		Password = inputPassword;
	}

	virtual void setInfo(string companyName, int companyID, string Work, int numOfPeople, string Date) {
		applyList.push_back(Info(companyName, companyID, Work, numOfPeople, Date));
	}

	virtual Info getInfo(int inputCompanyID) {
		for (int i = 0;i < applyList.size();i++) {
			if (applyList[i].getCompanyID() == inputCompanyID) {
				return applyList[i];
			}
		}
	}
	virtual vector<Info> getInfoList() {
		return applyList;
	}

};