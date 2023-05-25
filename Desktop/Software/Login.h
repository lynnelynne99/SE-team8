#pragma once
#include "MemberList.h"

class Login {
private:
	MemberList *list;
public:
	Login(MemberList* list) {
		this->list = list;
	}
	void completeLogin(string inputID, string inputPassword) {
		list->login(inputID, inputPassword);
	}
};