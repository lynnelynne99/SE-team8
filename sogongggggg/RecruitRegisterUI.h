#pragma once
#include <iostream>
#include <string>
#include "RecruitRegister.h"
using namespace std;

#define MAX_STRING 32

class RecruitRegisterUI {
private:
	char work[MAX_STRING], deadline[MAX_STRING];
	int numOfPeople = 0;
	RecruitRegister* control = nullptr;
	FILE* in_fp, * out_fp;
public:
	RecruitRegisterUI(RecruitRegister* control, FILE* in_fp, FILE* out_fp) {
		this->control = control;
		this->in_fp = in_fp;
		this->out_fp = out_fp;
	}

	void createRecruit() {
		fscanf(in_fp, "%s %d %s", work, &numOfPeople, deadline);

		control->addRecruit(string(work), numOfPeople, string(deadline));

		fprintf(out_fp, "3.1. 채용 정보 등록\n");
		fprintf(out_fp, "> ");
		fprintf(out_fp, "%s %d %s\n", work, numOfPeople, deadline);
	}
};