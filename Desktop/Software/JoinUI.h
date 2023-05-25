#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
#include "Join.h"
using namespace std;

#define MAX_STRING 32

class JoinUI {
private:
	int memberType = 0;
	int Num = 0;
	char name[MAX_STRING], ID[MAX_STRING], password[MAX_STRING];

	Join* control = nullptr;
	FILE* in_fp, * out_fp;
public:
	JoinUI(Join* control, FILE* in_fp, FILE* out_fp) {
		this->control = control;
		this->in_fp = in_fp;
		this->out_fp = out_fp;
	}

	void createMember() {
		fscanf(in_fp, "%d %s %d %s %s", &memberType, name, &Num, ID, password);

		control->addMember(memberType, string(name), Num, string(ID), string(password));

		fprintf(out_fp, "1.1. 회원가입\n");
		fprintf(out_fp, "> ");
		fprintf(out_fp, "%d %s %d %s %s\n", memberType, name, Num, ID, password);
	}
};