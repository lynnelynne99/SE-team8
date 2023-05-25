#pragma once
#include <iostream>
#include "Apply.h"

using namespace std;

class ApplyUI {
private:
	int inputCompanyID = 0;
	Apply* control;
	FILE* in_fp, * out_fp;
	Info applyInfo;
public:
	ApplyUI(Apply* control, FILE* in_fp, FILE* out_fp) {
		this->control = control;
		this->in_fp = in_fp;
		this->out_fp = out_fp;
	}
	void doApply() {
		fscanf(in_fp, "%d", &inputCompanyID);

		applyInfo = control->addApplyInfo(inputCompanyID);

		fprintf(out_fp, "4.2. 채용 지원\n");
		fprintf(out_fp, "> ");
		fprintf(out_fp, "%s %d %s\n", applyInfo.getCompanyName().c_str(), applyInfo.getCompanyID(), applyInfo.getWork().c_str());
	}
};