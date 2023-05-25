#pragma once
#include <iostream>

using namespace std;

class Info {
private:
    string companyName;
    int companyID;
    string work;
    int numOfPeople = 0;
    string deadLine;
public:
    Info() {}

    Info(string Work, int numOfPeople, string deadLine) {
        this->work = Work;
        this->numOfPeople = numOfPeople;
        this->deadLine = deadLine;
    }

    Info(string companyName, int companyID, string Work, int numOfPeople, string deadLine) {
        this->companyName = companyName;
        this->companyID = companyID;
        this->work = Work;
        this->numOfPeople = numOfPeople;
        this->deadLine = deadLine;
    }

    string getWork() {
        return work;
    }
    int getNumOfPeople() {
        return numOfPeople;
    }
    string getDeadline() {
        return deadLine;
    }

    //  사업자 번호
    void setCompanyID(int companyID) {
        this->companyID = companyID;
    }

    int getCompanyID() {
        return companyID;
    }

    //회사이름
    void setCompanyName(string companyName) {
        this->companyName = companyName;
    }

    string getCompanyName() {
        return companyName;
    }


};