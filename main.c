#include <stdio.h>
#include "ships.c"
#include "board.c"





int main() {

    firstInit();
    User1Running();
    User2Running();
    while (1){
        Fire1();
        if(CkeckWinner(1)== 1)break;
        Fire2();
        if(CkeckWinner(0)== 1)break;
    }

    return 0;
}
