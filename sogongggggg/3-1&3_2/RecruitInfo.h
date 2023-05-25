//
//  RecruitInfo.h
//  SW3
//
//  Created by Jae hyeok Lee on 2023/05/22.
//

#ifndef RecruitInfo_h
#define RecruitInfo_h


#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;


class RecruitInfo{
private:
    char work;
    int numOfPeople;
    char DeadLine;
    
public:
    RecruitInfo(char recruitWork, int recruitnumOfPeople, char RecruitDeadLine){
        work = recruitWork;
        numOfPeople = recruitnumOfPeople;
        DeadLine = RecruitDeadLine;
    }
    int getNumberOfApplicants();
    void getRecruitInfo();
    void getRecruitInfoDetails();
    
    char getWork(){
        return work;
    }
    int getRecruitNumOfPeople(){
        return numOfPeople;
    }
    char getRecruitDeadLine(){
        return DeadLine;
    }
};


#endif /* RecruitInfo_h */

