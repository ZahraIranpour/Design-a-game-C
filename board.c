#include "board.h"

void firstInit(){
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            boardGame[i][j] = 0;
        }
    }
}

void InitMokhtasat(int satr,int ston,int count){
    int* ptr = &boardGame[satr][ston];
    for (int i = 0; i < count; ++i) {
        //code 11 means this is full
        *ptr = 11;
        ptr++;
    }
}