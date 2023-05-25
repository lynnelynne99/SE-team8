//
//  Member.h
//  SW3
//
//  Created by Jae hyeok Lee on 2023/05/22.
//

#ifndef Actor_h
#define Actor_h
#include <vector>
#include <iostream>
#include <string>
#include "RecruitInfo.h"
#using namespace std;

/*
 회원가입시,
 맨 앞 값이 1이면 CompanyMemeber
 맨 앞 값이 2이면 NormalMember
 if else로 쪼개면 되겠지?
 
 */

class Member {
protected:
    char ID;
    char PassWord;
    
public:
    Member(char memberID, char MemberPassWord);
    bool checkIDandPassword();
};


class CompanyMember : public Member{
private:
    vector<RecruitInfo> RecruitInfoList();
    char CompanyName;
    int CompanyID;

public:
    CompanyMember(char memberID, char MemberPassWord, char memberCompanyName, int memberCompanyID);
    void getRecruitInfo();
};


class NormalMember : public Member {
private:
    vector<RecruitInfo> ApplyInfoList();
    char name;
    int Identity;

public:
    void listApplyInfo();
    void cancelApply();
    void addNewApplyInfo();
};


#endif /* Actor_h */
