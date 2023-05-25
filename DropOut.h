#pragma once
#include "MemberList.h"

class DropOut {
private:
	MemberList* list;
public:
	DropOut(MemberList* list) {
		this->list = list;
	}
	string deleteMember() {
		return list->deleteMember();
	}
};