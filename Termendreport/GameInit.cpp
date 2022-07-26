
#include <Windows.h>
#include <stdio.h>
#include <time.h>
#define CHARBUFF 124
const int digitnum = 3;
typedef struct numbers {
    int digit[digitnum];
    int ansvalue;
};

void getCurrentDirectory(char* currentDirectory) {
    GetCurrentDirectory(CHARBUFF, currentDirectory);
}

//正解の3桁の数字を決定 構造体を引数にし、構造体を返す。
struct numbers decideAnswer(struct numbers ans) {
    srand((unsigned int)time(NULL));
    ans.digit[0] = rand() % 10; //一桁目
    do {
        ans.digit[1] = rand() % 10; //二桁目
    } while (ans.digit[0] == ans.digit[1]);

    do {
        ans.digit[2] = rand() % 10; //三桁目
    } while (ans.digit[2] == ans.digit[0] || ans.digit[2] == ans.digit[1]);

    ans.ansvalue = ans.digit[0] * 100 + ans.digit[1] * 10 + ans.digit[2];
    return ans;
}

/*
設定ファイルから入力できる回数を読み込み、その値を返す。
設定ファイルの値を変えることでゲームの難易度を変えられる。
*/
int getPredictLimit() {
    char currentDirectory[CHARBUFF];
    getCurrentDirectory(currentDirectory);
    char settingFile[CHARBUFF];
    sprintf_s(settingFile, "%s\\setting.ini", currentDirectory);

    return  GetPrivateProfileInt("section1", "predict_limit", -1, settingFile);
}
