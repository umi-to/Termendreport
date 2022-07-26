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

    //入力内容が正しくなるまで入力を繰り返す。
    while (inputflag == false) {
        printf("%d桁の数字を入力：", digitnum);
        scanf_s("%s", input, CHARBUFF);
        inputflag = true;

        //入力されたものの桁数が正しいか判定
        if (strlen(input) != digitnum) {
            fprintf_s(stdout, "桁数が違います\n");
            inputflag = false;
        }

        //数字以外が入力されていないかを判定
        for (int i = 0; i < digitnum; i++) {
            if (!isdigit(input[i])) {
                fprintf_s(stdout, "数字以外が入力されています\n");
                inputflag = false;
            }
        }

    }

    //文字列型を整数型に変換
    predict.ansvalue = atoi(&input[0]);

    //一桁ずつ配列に格納
    for (int i = 0; i < digitnum; i++) {
        predict.digit[i] = (int)(predict.ansvalue / pow(10, 2 - i)) % 10;
    }

    return predict;
}

bool isSame(struct numbers predict, struct numbers ans) {
    int hitcount = 0;
    int blowcount = 0;
    /*
    入力された数字が、最初に生成した数字と一致するか判定。
    同じ桁で、かつその桁同士の数が同じならばhitcountを1増やす。
    違う桁で、その桁が同じ数字ならばblowcountを1増やす。
    */
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

   // hitcountがdigitnum、今回では3であればtrueを返す。そうでなければfalseを返す。
    fprintf_s(stdout, "%dヒット、%dブロー\n", hitcount, blowcount);
    if (hitcount == digitnum) {
        return true;
    }
    return false;
}