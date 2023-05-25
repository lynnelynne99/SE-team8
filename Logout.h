#pragma once
#include "MemberList.h"

class Logout {
private:
	MemberList* list;
public:
	Logout(MemberList* list) {
		this->list = list;
	}

	string completeLogout() {
		return list->logout();
	}
};