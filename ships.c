#include "ships.h"
#include <stdio.h>
#include "board.c"

static int fireCountUser1 = 0;
static int fireCountUser2 = 0;

int CheckTargetsUser(int pInt[2], int i);

int CheckValidlyUser2Mokhta(int i, int i1, int i2);

void User1Running(){
    printf("> user1:put your ships in table:");
    scanf("%d,%d %d,%d %d,%d",&user1.pointA[0],&user1.pointA[1],&user1.pointB[0],&user1.pointB[1],&user1.pointC[0],&user1.pointC[1]);
    InitMokhtasat(user1.pointA[0],user1.pointA[1],4);
    InitMokhtasat(user1.pointB[0],user1.pointB[1],3);
    InitMokhtasat(user1.pointC[0],user1.pointC[1],2);
}

void User2Running(){
    printf("> user2:put your ships in table:");
    scanf("%d,%d %d,%d %d,%d",&user2.pointA[0],&user2.pointA[1],&user2.pointB[0],&user2.pointB[1],&user2.pointC[0],&user2.pointC[1]);
    while (1){
        if(CheckValidlyUser2Mokhta(user2.pointA[0],user2.pointA[1],4) == 1 && CheckValidlyUser2Mokhta(user2.pointB[0],user2.pointB[1],3) == 1 &&
                CheckValidlyUser2Mokhta(user2.pointC[0],user2.pointC[1],2) == 1){
            break;
        } else{
            printf("please enter again");
            scanf("%d,%d %d,%d %d,%d",&user2.pointA[0],&user2.pointA[1],&user2.pointB[0],&user2.pointB[1],&user2.pointC[0],&user2.pointC[1]);
        }
    }
    InitMokhtasat(user2.pointA[0],user2.pointA[1],4);
    InitMokhtasat(user2.pointB[0],user2.pointB[1],3);
    InitMokhtasat(user2.pointC[0],user2.pointC[1],2);
}

void Fire1(){
    int fire[2];
    printf("> user1:fire");
    scanf("%d,%d",&fire[0],&fire[1]);
    while (CheckTargetsUser(fire,1)){
        printf("Please Enter Again fire:");
        scanf("%d,%d",&fire[0],&fire[1]);
    }
    DoFire(fire[0],fire[1]);
    fireCountUser1++;
}

void Fire2(){
    int fire[2];
    printf("> user2:fire");
    scanf("%d,%d",&fire[0],&fire[1]);
    while (CheckTargetsUser(fire,0)){
        printf("Please Enter Again fire:");
        scanf("%d,%d",&fire[0],&fire[1]);
    }
    fireCountUser2++;
}

int CheckValidlyUser2Mokhta(int satr,int stoon,int count){
    int *ptr = &boardGame[satr][stoon];
    for (int i = 0; i < count; ++i) {
        if(*ptr == 11){
            return 0;
        }
        ptr++;
    }

    return 1;
}

void DoFire(int satr,int stoon){
    int *ptr = &boardGame[satr][stoon];
    for (int i = 0; i < count; ++i) {
        *ptr = 0;
        ptr++;
    }
}

int CkeckWinner(int isUser1orUser2){
    if(isUser1orUser2 == 1){

    } else{

    }
}


int CheckTargetsUser(int fire[],int isUser1orUser2){
    if(isUser1orUser2 == 1)
    {
        for (int i = 0; i < fireCountUser1; ++i) {
            if(fire[0] == lastTargetsUser1[0] && fire[1] == lastTargetsUser1[1])
            {
                return 1;
            }
        }
    }
    else{
        for (int i = 0; i < fireCountUser2; ++i) {
            if(fire[0] == lastTargetsUser2[0] && fire[1] == lastTargetsUser2[1])
            {
                return 1;
            }
        }
    }

    return 0;
}

