#pragma once
#include <iostream>
#include "CheckApplyInfo.h"

using namespace std;

class CheckApplyInfoUI {
private:
	CheckApplyInfo* control;
	FILE* out_fp;
	vector<Info> applyList;
public:
	CheckApplyInfoUI(CheckApplyInfo* control, FILE* out_fp) {
		this->control = control;
		this->out_fp = out_fp;
	}

	void checkApplyInfo() {
		applyList = control->showApplyInfo();

		fprintf(out_fp, "4.3. 지원 정보 조회\n");
		fprintf(out_fp, "> ");
		for (int i = 0; i<applyList.size();i++) {
			fprintf(out_fp, "%s %d %s %d %s\n", applyList[i].getCompanyName().c_str(), applyList[i].getCompanyID()
				,applyList[i].getWork().c_str(), applyList[i].getNumOfPeople(), applyList[i].getDeadline().c_str());
		}
	}
};