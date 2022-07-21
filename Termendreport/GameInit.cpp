
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

struct numbers decideAnswer(struct numbers ans) {
    srand((unsigned int)time(NULL));
    ans.digit[0] = rand() % 10;
    do {
        ans.digit[1] = rand() % 10;
    } while (ans.digit[0] == ans.digit[1]);

    do {
        ans.digit[2] = rand() % 10;
    } while (ans.digit[2] == ans.digit[0] || ans.digit[2] == ans.digit[1]);

    ans.ansvalue = ans.digit[0] * 100 + ans.digit[1] * 10 + ans.digit[2];
    return ans;

}
int getPredictLimit() {
    char currentDirectory[CHARBUFF];
    getCurrentDirectory(currentDirectory);
    char settingFile[CHARBUFF];
    sprintf_s(settingFile, "%s\\setting.ini", currentDirectory);

    return  GetPrivateProfileInt("section1", "predict_limit", -1, settingFile);
}
