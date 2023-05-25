#pragma once
// ��� ����
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

// ��� ����
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// �Լ� ����
void doTask();
void program_exit();

// ���� ����
FILE* in_fp, * out_fp;

int main()
{
    // ���� ������� ���� �ʱ�ȭ
    in_fp = fopen(INPUT_FILE_NAME, "r+");
    out_fp = fopen(OUTPUT_FILE_NAME, "w+");

    doTask();

    return 0;
}



void doTask()
{
    // �޴� �Ľ��� ���� level ������ ���� ����
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;

    //ȸ�� ������ ���� ȸ�� ����Ʈ Ŭ����
    MemberList members;

    //ȸ�� ������ ���� Boundary, Control Ŭ���� ����
    Join join(&members);
    JoinUI joinUI(&join, in_fp, out_fp);
    //ȸ�� Ż�� ���� Boundary, Control Ŭ���� ����
    DropOut dropout(&members);
    DropOutUI dropoutUI(&dropout, out_fp);
    //�α����� ���� Boundary, Control Ŭ���� ����
    Login login(&members);
    LoginUI loginUI(&login, in_fp, out_fp);
    //�α׾ƿ��� ���� Boundary, Control Ŭ���� ����
    Logout logout(&members);
    LogoutUI logoutUI(&logout, out_fp);
    //ä�� ���� ����� ���� Boundary, Control Ŭ���� ����
    RecruitRegister rr(&members);
    RecruitRegisterUI rrUI(&rr, in_fp, out_fp);
    //��ε� ä�� ���� ��ȸ�� ���� Boundary, Control Ŭ���� ����
    CheckRecruitInfo cri(&members);
    CheckRecruitInfoUI criUI(&cri, out_fp);
    //ä�� ���� �˻��� ���� Boundary, Control Ŭ���� ����
    Inquiry inquiry(&members);
    InquiryUI inquiryUI(&inquiry,in_fp , out_fp);
    //ä�� ������ ���� Boundary, Control Ŭ���� ����
    Apply apply(&members);
    ApplyUI applyUI(&apply, in_fp, out_fp);
    //���� ���� ��ȸ�� ���� Boundary, Control Ŭ���� ����
    CheckApplyInfo cai(&members);
    CheckApplyInfoUI caiUI(&cai, out_fp);

    while (!is_program_exit)
    {
        // �Է����Ͽ��� �޴� ���� 2���� �б�
        fscanf(in_fp, "%d %d ", &menu_level_1, &menu_level_2);

        // �޴� ���� �� �ش� ���� ����
        switch (menu_level_1)
        {
        case 1:
        {
            switch (menu_level_2)
            {
            case 1:   // "1.1. ȸ�����ԡ� �޴� �κ�
            {        
                joinUI.createMember();
                break;
            }
            case 2:   // "1.2. ȸ��Ż�� " �޴� �κ�
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
            case 1:   // "2.1. �α��Ρ� �޴� �κ�
            {
                loginUI.doLogin();
                break;
            }
            case 2:   // "2.2. �α׾ƿ� " �޴� �κ�
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
            case 1:   // "3.1. ä�� ���� ��ϡ� �޴� �κ�
            {
                rrUI.createRecruit();
                break;
            }
            case 2:   // "3.1. ��ϵ� ä�� ���� ��ȸ " �޴� �κ�
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
            case 1:   // "4.1. ä�� ���� �˻��� �޴� �κ�
            {
                inquiryUI.searchRecruitInfo();
                break;
            }
            case 2:   // "4.2. ä�� ���� " �޴� �κ�
            {
                applyUI.doApply();
                break;
            }
            case 3:   // "4.3. ���� ���� ��ȸ�� �޴� �κ�
            {
                caiUI.checkApplyInfo();
                break;
            }
            case 4:   // "4.4. ���� ��� " �޴� �κ�
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
            case 1:   // "5.1. ���� ���� ��衰 �޴� �κ�
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
            case 1:   // "6.1. ���ᡰ �޴� �κ�
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
    fprintf(out_fp, "6.1. ����\n");
    fclose(in_fp);
    fclose(out_fp);
}