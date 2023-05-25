#pragma once
#include <iostream>
#include <string>
#include "DropOut.h"

class DropOutUI {
private:
	DropOut* control = nullptr;
	FILE* out_fp;
	string deletedID;
public:
	DropOutUI(DropOut* control,FILE *out_fp) {
		this->control = control;
		this->out_fp = out_fp;
	}

	void doDropOut() {

		deletedID = control->deleteMember();

		fprintf(out_fp, "1.2. È¸¿øÅ»Åð\n");
		fprintf(out_fp, "> ");
		fprintf(out_fp, "%s\n", deletedID.c_str());
	}
};