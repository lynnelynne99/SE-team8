<<<<<<< HEAD
#pragma once
#include "MemberList.h"
#include "Member.h"
#include "NormalMember.h"
#include "CompanyMember.h"
#include "Info.h"
#include <map>

class statistic {
private:
	MemberList* list;
	map<string, int> count;
	int cnt = 0;
public:
	statistic(MemberList* list) {
		this->list = list;
	}
	void show() {
		// ���� �α��� �� ���(int)
		logined = list->getLoginedMember;
		
		// ȸ�� ȸ���� ���
		if (list[logined]->getType() == 1){
			//�ش� ȸ��ȸ���� ���ؼ�,
			CompanyMember cM = list[logined];
			// �̻���� COMPANYNAME == NormalMember�� Info.companyID�� ������,
			for (int i = 0; i < list.size(); i++) {
				if (list[i]->getType() == 2) {
					NormalMember nm = list[i];
					
					for (int j = 0; j < nm.getInfoList().size(); j++) {
						Info info = nm.getInfoList()[j];
						if (info.getCompanyName() == cM.getName()) {
							cnt++;
						}
					}

				}
			}
			cout << cM.getInfo().getWork() << " " << cnt << endl;
				
		}
		else {//�Ϲ� ȸ���� ���
			NormalMember nM = list[logined];
			vector<Info> info = nM.getInfoList();
			for (int i = 0; i < info.size(); i++) {
				if (count.find(info[i].getWork()) != count.end()) {
					count[info[i].getWork()]++;
				}
				else {//���� ���� ���
					count.insert(pair<string, int>(info[i], 1));
				}
			}
			
			for (auto entry : count) {
				cout << entry.first << " " << entry.second << endl;
			}

		}
	}
=======
#pragma once
#include "MemberList.h"
#include "Member.h"
#include "NormalMember.h"
#include "CompanyMember.h"
#include "Info.h"
#include <map>

class statistic {
private:
	MemberList* list;
	map<string, int> count;
	int cnt = 0;
public:
	statistic(MemberList* list) {
		this->list = list;
	}
	void show() {
		// ���� �α��� �� ���(int)
		logined = list->getLoginedMember;
		
		// ȸ�� ȸ���� ���
		if (list[logined]->getType() == 1){
			//�ش� ȸ��ȸ���� ���ؼ�,
			CompanyMember cM = list[logined];
			// �̻���� COMPANYNAME == NormalMember�� Info.companyID�� ������,
			for (int i = 0; i < list.size(); i++) {
				if (list[i]->getType() == 2) {
					NormalMember nm = list[i];
					
					for (int j = 0; j < nm.getInfoList().size(); j++) {
						Info info = nm.getInfoList()[j];
						if (info.getCompanyName() == cM.getName()) {
							cnt++;
						}
					}

				}
			}
			cout << cM.getInfo().getWork() << " " << cnt << endl;
				
		}
		else {//�Ϲ� ȸ���� ���
			NormalMember nM = list[logined];
			vector<Info> info = nM.getInfoList();
			for (int i = 0; i < info.size(); i++) {
				if (count.find(info[i].getWork()) != count.end()) {
					count[info[i].getWork()]++;
				}
				else {//���� ���� ���
					count.insert(pair<string, int>(info[i], 1));
				}
			}
			
			for (auto entry : count) {
				cout << entry.first << " " << entry.second << endl;
			}

		}
	}
>>>>>>> b3e37de235482e187a6f4f5410f21cc2a4048099
};