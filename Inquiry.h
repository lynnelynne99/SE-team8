
#pragma once
#include "Info.h"
#include "MemberList.h"

class Inquiry {
private:
	MemberList* list;
	Info recruitInfo;
public:
	Inquiry(MemberList* list) {
		this->list = list;
	}

	Info showRecruitInfo(string inputCompanyName) {
		recruitInfo = list->getRecruitInfo(inputCompanyName);
		return recruitInfo;
	}
};