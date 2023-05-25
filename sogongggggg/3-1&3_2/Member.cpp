//
//  Member.cpp
//  SW3
//
//  Created by Jae hyeok Lee on 2023/05/22.
//

#include "Member.h"
#include "RecruitInfo.h"

Member::Member(char memberID, char memberPassWord){
    ID = memberID;
    PassWord = memberPassWord;
}

// 안쓸거같음
bool Member::checkIDandPassword(){
    return false;
}


CompanyMember::CompanyMember(char memberID, char memberPassWord, char memberCompanyName, int memberCompanyID): Member(memberID, memberPassWord){
    CompanyName = memberCompanyName;
    CompanyID = memberCompanyID;
}


void CompanyMember::getRecruitInfo(){
    // 해당 채용 정보에 대한 List 내용을 다 출력
    return ;
}


void CompanyMember::addRecruitRegister(char work, int numOfPeople, char date){
    RecruitInfo recruitInfo(work, numOfPeople, date);
    RecruitInfoList.push_back(recruitInfo);
}


void CompanyMember::getRecruitInfo(){
    for (const RecruitInfo& recruitInfo : RecruitInfoList){
        cout << recruitInfo.getWork();
        cout << " " << recruitInfo.getRecruitNumOfPeople() ;
        cout << " " << recruitInfo.getRecruitDeadLine() ;
        cout << endl;
    }
}

NormalMember::NormalMember(char memberID, char memberPassWord, char memberName, int memberIdentity):Member(memberID, memberPassWord){
    name = memberName;
    Identity = memberIdentity;
}



