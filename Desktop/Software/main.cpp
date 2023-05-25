#pragma once
// 헤더 선언
#include <stdio.h>
#include <string.h>
#include "MemberList.h"
#include "JoinUI.h"
#include "DropOutUI.h"
#include "LoginUI.h"
#include "LogoutUI.h"
#include "RecruitRegisterUI.h"
#include "CheckRecruitInfoUI.h"
#include "InquiryUI.h"
#include "ApplyUI.h"
#include "CheckApplyInfoUI.h"

// 상수 선언
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// 함수 선언
void doTask();
void program_exit();

// 변수 선언
FILE* in_fp, * out_fp;

int main()
{
    // 파일 입출력을 위한 초기화
    in_fp = fopen(INPUT_FILE_NAME, "r+");
    out_fp = fopen(OUTPUT_FILE_NAME, "w+");

    doTask();

    return 0;
}



void doTask()
{
    // 메뉴 파싱을 위한 level 구분을 위한 변수
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;

    //회원 관리를 위한 회원 리스트 클래스
    MemberList members;

    //회원 가입을 위한 Boundary, Control 클래스 생성
    Join join(&members);
    JoinUI joinUI(&join, in_fp, out_fp);
    //회원 탈퇴를 위한 Boundary, Control 클래스 생성
    DropOut dropout(&members);
    DropOutUI dropoutUI(&dropout, out_fp);
    //로그인을 위한 Boundary, Control 클래스 생성
    Login login(&members);
    LoginUI loginUI(&login, in_fp, out_fp);
    //로그아웃을 위한 Boundary, Control 클래스 생성
    Logout logout(&members);
    LogoutUI logoutUI(&logout, out_fp);
    //채용 정보 등록을 위한 Boundary, Control 클래스 생성
    RecruitRegister rr(&members);
    RecruitRegisterUI rrUI(&rr, in_fp, out_fp);
    //등로된 채용 정보 조회를 위한 Boundary, Control 클래스 생성
    CheckRecruitInfo cri(&members);
    CheckRecruitInfoUI criUI(&cri, out_fp);
    //채용 정보 검색를 위한 Boundary, Control 클래스 생성
    Inquiry inquiry(&members);
    InquiryUI inquiryUI(&inquiry,in_fp , out_fp);
    //채용 지원를 위한 Boundary, Control 클래스 생성
    Apply apply(&members);
    ApplyUI applyUI(&apply, in_fp, out_fp);
    //지원 정보 조회를 위한 Boundary, Control 클래스 생성
    CheckApplyInfo cai(&members);
    CheckApplyInfoUI caiUI(&cai, out_fp);

    while (!is_program_exit)
    {
        // 입력파일에서 메뉴 숫자 2개를 읽기
        fscanf(in_fp, "%d %d ", &menu_level_1, &menu_level_2);

        // 메뉴 구분 및 해당 연산 수행
        switch (menu_level_1)
        {
        case 1:
        {
            switch (menu_level_2)
            {
            case 1:   // "1.1. 회원가입“ 메뉴 부분
            {        
                joinUI.createMember();
                break;
            }
            case 2:   // "1.2. 회원탈퇴 " 메뉴 부분
            {          
                dropoutUI.doDropOut();
                break;
            }
            }
            break;
        }
        case 2:
        {
            switch (menu_level_2)
            {
            case 1:   // "2.1. 로그인“ 메뉴 부분
            {
                loginUI.doLogin();
                break;
            }
            case 2:   // "2.2. 로그아웃 " 메뉴 부분
            {
                logoutUI.doLogout();
                break;
            }
            }
            break;
        }
        case 3:
        {
            switch (menu_level_2)
            {
            case 1:   // "3.1. 채용 정보 등록“ 메뉴 부분
            {
                rrUI.createRecruit();
                break;
            }
            case 2:   // "3.1. 등록된 채용 정보 조회 " 메뉴 부분
            {
                criUI.checkRecruitInfo();
                break;
            }
            }
            break;
        }
        case 4:
        {
            switch (menu_level_2)
            {
            case 1:   // "4.1. 채용 정보 검색“ 메뉴 부분
            {
                inquiryUI.searchRecruitInfo();
                break;
            }
            case 2:   // "4.2. 채용 지원 " 메뉴 부분
            {
                applyUI.doApply();
                break;
            }
            case 3:   // "4.3. 지원 정보 조회“ 메뉴 부분
            {
                caiUI.checkApplyInfo();
                break;
            }
            case 4:   // "4.4. 지원 취소 " 메뉴 부분
            {

                break;
            }
            }
            break;
        }
        case 5:
        {
            switch (menu_level_2)
            {
            case 1:   // "5.1. 지원 정보 통계“ 메뉴 부분
            {

                break;
            }
            }
            break;
        }
        case 6:
        {
            switch (menu_level_2)
            {
            case 1:   // "6.1. 종료“ 메뉴 부분
            {
                program_exit();
                is_program_exit = 1;
                break;
            }
            }
            return;
        }
        }
    }
}


void program_exit()
{
    fprintf(out_fp, "6.1. 종료\n");
    fclose(in_fp);
    fclose(out_fp);
}