#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define CHARBUFF 124
const int digitnum = 3;

typedef struct numbers {
    int digit[digitnum];
    int ansvalue;
};

struct numbers input(struct numbers predict) {
    int a;
    char input[256];
    bool inputflag = false;

    while (inputflag == false) {
        printf("%d桁の数字を入力：", digitnum);
        scanf_s("%s", input, CHARBUFF);
        inputflag = true;
        if (strlen(input) != digitnum) {
            fprintf_s(stdout, "桁数が違います\n");
            inputflag = false;
        }

        for (int i = 0; i < digitnum; i++) {
            if (!isdigit(input[i])) {
                fprintf_s(stdout, "数字以外が入力されています\n");
                inputflag = false;
            }
        }

    }

    predict.ansvalue = atoi(&input[0]);
    for (int i = 0; i < digitnum; i++) {
        predict.digit[i] = (int)(predict.ansvalue / pow(10, 2 - i)) % 10;
    }

    return predict;
}

bool isSame(struct numbers predict, struct numbers ans) {
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