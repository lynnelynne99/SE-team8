#pragma once
#include "CheckRecruitInfo.h"

class CheckRecruitInfoUI {
private:
	Info recruitInfo;
	CheckRecruitInfo* control = nullptr;
	FILE* out_fp;
public:
	CheckRecruitInfoUI(CheckRecruitInfo* control, FILE* out_fp) {
		this->control = control;
		this->out_fp = out_fp;
	}

	void checkRecruitInfo() {

		recruitInfo = control->showRegisteredRecruitInfo();

		fprintf(out_fp, "3.2. ��ϵ� ä�� ���� ��ȸ\n");
		fprintf(out_fp, "> ");
		fprintf(out_fp, "%s %d %s\n", recruitInfo.getWork().c_str(), recruitInfo.getNumOfPeople(), recruitInfo.getDeadline().c_str());
	}
};