#include <stdio.h>
#include <string.h>

#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"


// 함수 선언
void doTask();
void join();
void program_exit();


FILE* in_fp, *out_fp;


int main(){
    FILE* in_fp = fopen(INPUT_FILE_NAME, "r+");
    FILE* out_fp = fopen(OUTPUT_FILE_NAME, "w+");


    doTask();
    return 0;
}




void doTask() {
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;
    
    while(!is_program_exit){
        
    }
}
