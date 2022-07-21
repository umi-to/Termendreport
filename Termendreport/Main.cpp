﻿// Main.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//
#include "Termendreport.h"
struct numbers ans;
int main(){
    while (1) {
        int predcictLimit = getPredictLimit();

        ans = decideAnswer(ans);
        struct numbers predict[10];

        bool clearflag = false;
        int predictcount = 0;

        while (clearflag == false && predictcount < predcictLimit) {
            predict[predictcount] = input(predict[predictcount]);
            clearflag = isSame(predict[predictcount], ans);
            predictcount++;
            fprintf_s(stdout, "%d\n", predictcount);
        }

        if (clearflag == true) {
            gameclear();
        }
        else {
            gameover(ans);
        }
        createResult(predict, ans, predictcount);

        char input[CHARBUFF];
        fprintf_s(stdout, "もう一度プレイする場合はrを入力してください：");
        scanf_s("%s", input, CHARBUFF);
        
        if (*input != 'r')break; 

    }
    return 0;


}