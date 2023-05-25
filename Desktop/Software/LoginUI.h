#pragma once
#include <iostream>
#include <string>
#include "Login.h"

#define MAX_STRING 32

class LoginUI {
private:
	char inputID[MAX_STRING], inputPassword[MAX_STRING];
	Login* control = nullptr;
	FILE* in_fp, * out_fp;
public:
	LoginUI(Login* control, FILE* in_fp, FILE* out_fp) {
		this->control = control;
		this->in_fp = in_fp;
		this->out_fp = out_fp;
	}
	void doLogin() {
		fscanf(in_fp, "%s %s", inputID, inputPassword);

		control->completeLogin(string(inputID), string(inputPassword));

		fprintf(out_fp, "2.1. ·Î±×ÀÎ\n");
		fprintf(out_fp, "> ");
		fprintf(out_fp, "%s %s\n", inputID, inputPassword);
	}
};
