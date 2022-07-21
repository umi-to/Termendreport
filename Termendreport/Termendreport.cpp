// Termendreport.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//
#include "Termendreport.h"
struct numbers ans;

struct numbers input(struct numbers predict) {
    int a;
    char input[256];
    bool inputflag = false;
    printf("%d桁の数字を入力", digitnum);
    while (inputflag == false) {

        scanf_s("%s", input, CHARBUFF);
        inputflag = true;
        if (strlen(input) != digitnum) {
            fprintf_s(stdout, "%d桁入力", digitnum);
            inputflag = false;
        }

        for (int i = 0; i < digitnum; i++) {
            if (!isdigit(input[i])) {
                fprintf_s(stdout, "数字を入力\n");
                inputflag = false;
            }
        }
        
    }
    for (int i = 0; i < digitnum; i++) {
            predict.digit[i] = atoi(&input[i]);
        }
    
    predict.ansvalue = atoi(&input[0]);
    for (int i = 0; i < digitnum; i++) {
        predict.digit[i] = (int)(predict.ansvalue / pow(10, 2 - i)) % 10;
    }
    
    
    return predict;
}

bool isSame(struct numbers predict) {
    int hitcount = 0;
    int blowcount = 0;
    
    for (int i = 0; i < digitnum; i++) {
        for (int j = 0; j < digitnum; j++) {
            if (i == j) {
                if (predict.digit[i] == ans.digit[j]) {
                    hitcount++;
                }
            }
            else {
                if (predict.digit[i] == ans.digit[j]) {
                    blowcount++;
                }
            }
        }
    }
    fprintf_s(stdout, "%dヒット、%dブロー\n", hitcount, blowcount);
    if (hitcount == digitnum) {
        return true;
    }
    return false;
}



int main(){

    int predcictLimit = getPredictLimit();

   ans =  decideAnswer(ans);
    struct numbers predict[10];

    bool clearflag = false;
    int predictcount = 0;
    
    while (clearflag == false && predictcount < predcictLimit) {
       predict[predictcount] = input(predict[predictcount]);
       clearflag = isSame(predict[predictcount]);
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


}