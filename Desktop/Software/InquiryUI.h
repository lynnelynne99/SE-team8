#pragma once
#include <iostream>
#include <string>
#include "Inquiry.h"
using namespace std;

#define MAX_STRING 32

class InquiryUI {
private:
	char companyName[MAX_STRING];
	Inquiry* control = nullptr;
	FILE* in_fp, * out_fp;
	Info recruitInfo;
public:
	InquiryUI(Inquiry* control, FILE* in_fp, FILE* out_fp) {
		this->control = control;
		this->in_fp = in_fp;
		this->out_fp = out_fp;
	}

	void searchRecruitInfo() {
		fscanf(in_fp, "%s", companyName);

		recruitInfo = control->showRecruitInfo(string(companyName));

		fprintf(out_fp, "4.1. 채용 정보 검색\n");
		fprintf(out_fp, "> ");
		fprintf(out_fp, "%s %d %s %d %s\n", recruitInfo.getCompanyName().c_str(), recruitInfo.getCompanyID(), 
			recruitInfo.getWork().c_str(), recruitInfo.getNumOfPeople(), recruitInfo.getDeadline().c_str() );
	}
};