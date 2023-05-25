#pragma once
#include <string>
#include <iostream>
#include "MemberList.h"
using namespace std;

class RecruitRegister {
private:
	MemberList* list;
public:
	RecruitRegister(MemberList* list) {
		this->list = list;
	}

	void addRecruit(string work, int numOfPeople, string deadLine) {
		list->addRecruitInfo(work, numOfPeople, deadLine);
	}
};
