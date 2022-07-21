// Termendreport.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//
#include "Termendreport.h"

void getCurrentDirectory(char* currentDirectory) {
    GetCurrentDirectory(CHARBUFF, currentDirectory);
}

void decideAnswer() {
    srand((unsigned int)time(NULL));
    ans.digit[0] = rand() % 10;
    do {
        ans.digit[1] = rand() % 10;
    } while (ans.digit[0] == ans.digit[1]);

    do {
        ans.digit[2] = rand() % 10;
    } while (ans.digit[2] == ans.digit[0] || ans.digit[2] == ans.digit[1]);

    ans.ansvalue = ans.digit[0] * 100 + ans.digit[1] * 10 + ans.digit[2];
}
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

void gameclear() {
    fprintf_s(stdout, "ゲームクリア！！！！\n");
}

void gameover() {
    fprintf_s(stdout, "ゲームオーバー...\n正解は");
    for (int i = 0; i < digitnum; i++) {
        fprintf_s(stdout, "%d", ans.digit[i]);
    }
}

int main(){
    char currentDirectory[CHARBUFF];
    getCurrentDirectory(currentDirectory);
    char settingFile[CHARBUFF];
    sprintf_s(settingFile, "%s\\setting.ini", currentDirectory);

    int predcict_limit = GetPrivateProfileInt("section1", "predict_limit", -1, settingFile);

    decideAnswer();
    struct numbers predict[10];

    bool clearflag = false;
    int predictcount = 0;
    
    while (clearflag == false && predictcount < predcict_limit) {
       predict[predictcount] = input(predict[predictcount]);
       clearflag = isSame(predict[predictcount]);
       predictcount++;
       fprintf_s(stdout, "%d\n", predictcount);
    }

    if (clearflag == true) {
        gameclear();
    }
    else {
        gameover();
    }

}