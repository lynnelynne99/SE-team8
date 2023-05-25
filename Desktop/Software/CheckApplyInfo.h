#pragma once
#include "MemberList.h"
#include "Info.h"

using namespace std;

class CheckApplyInfo {
private:
	MemberList* list;
	vector<Info> applyList;
public:
	CheckApplyInfo(MemberList* list) {
		this->list = list;
	}

	vector<Info> showApplyInfo() {
		applyList = list->checkApplyInfo();
		return applyList;
	}
};