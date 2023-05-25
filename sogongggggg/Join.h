#pragma once
#include <iostream>
#include <string>
#include "MemberList.h"
#include "CompanyMember.h"
#include "NormalMember.h"
using namespace std;


class Join {
private:
	MemberList* list;
public:
	Join(MemberList* list) {
		this->list = list;
	}

	void addMember(int memberType,string inputName, int inputNum, string inputID, string inputPassword ) {
		if (memberType == 1) {
			list->addMember(new CompanyMember(memberType, inputName, inputNum, inputID, inputPassword));
		}
		else {
			list->addMember(new NormalMember(memberType, inputName, inputNum, inputID, inputPassword));
		}
	}
};

