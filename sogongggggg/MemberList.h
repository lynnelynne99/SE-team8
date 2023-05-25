#pragma once
#include "Member.h"
#include "vector"

class MemberList {
private:
	vector<Member*> memberList;
	int numMember = 0;
	int loginedMember = 0;
public:
	MemberList() {}

	int getNumMember() {
		return numMember;
	}

	int getLoginedMember() {
		return loginedMember;
	}

	void addMember(Member *member) {
		memberList.push_back(member);
		numMember++;
	}
	
	string deleteMember() {
		string ID = memberList[loginedMember]->getID();
		memberList.erase(memberList.begin()+loginedMember);
		numMember--;
		return ID;
	}

	void login(string ID, string Password) {
		for (int i = 0;i < numMember;i++) {
			if (memberList.at(i)->getID() == ID && memberList[i]->getPassword() == Password) {
				memberList[i]->setState(1);
				loginedMember = i;
			}
		}
	}
	string logout() {
		memberList.at(loginedMember)->setState(0);
		return memberList.at(loginedMember)->getID();
	}

	void addRecruitInfo(string work, int numOfPeople, string deadLine) {
		memberList[loginedMember]->setInfo(work, numOfPeople, deadLine);
	}

	Info getRecruitInfo() {
		return memberList[loginedMember]->getInfo();
	}

	Info getRecruitInfo(string inputCompanyName) {
		for (int i = 0;i < numMember;i++) {
			if (memberList[i]->getName() == inputCompanyName) {
				return memberList[i]->getInfo();
			}
		}
	}
	Info addApplyInfo(int inputCompanyID) {
		for (int i = 0;i < numMember;i++) {
			if (memberList[i]->getNum() == inputCompanyID) {
				Info recruitInfo = memberList[i]->getInfo();
				memberList[loginedMember]->setInfo(memberList[i]->getName(), memberList[i]->getNum(),
					recruitInfo.getWork(), recruitInfo.getNumOfPeople(), recruitInfo.getDeadline());
				return memberList[loginedMember]->getInfo(inputCompanyID);
			}
		}
	}
	vector<Info> checkApplyInfo() {
		return memberList[loginedMember]->getInfoList();
	}
};