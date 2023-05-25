#pragma once
#include "MemberList.h"
#include "Info.h"
#include <string>
using namespace std;

class CheckRecruitInfo {
private:
	MemberList* list;
	Info recruitInfo;
public:
	CheckRecruitInfo(MemberList* list) {
		this->list = list;
	}

    Info showRegisteredRecruitInfo() {
		recruitInfo = list->getRecruitInfo();
		return recruitInfo;
    }

};