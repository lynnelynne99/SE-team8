#pragma once
#include <iostream>
#include <string>
#include "Logout.h"

class LogoutUI {
private:
	Logout* control = nullptr;
	FILE* out_fp;
	string logoutedID;
public:
	LogoutUI(Logout* control, FILE* out_fp) {
		this->control = control;
		this->out_fp = out_fp;
	}

	void doLogout() {
		logoutedID = control->completeLogout();

		fprintf(out_fp, "2.2. ·Î±×¾Æ¿ô\n");
		fprintf(out_fp, "> ");
		fprintf(out_fp, "%s\n", logoutedID.c_str());
	}
};
