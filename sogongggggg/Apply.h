#pragma once
#include "MemberList.h"
#include "Info.h"


using namespace std;

class Apply {
private:
	MemberList* list;
	Info applyInfo;
public:
	Apply(MemberList* list) {
		this->list = list;
	}

	Info addApplyInfo(int inputCompanyID) {
		applyInfo = list->addApplyInfo(inputCompanyID);
		return applyInfo;
	}
};