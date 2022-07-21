#pragma once
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>
#define CHARBUFF 124
const int digitnum = 3;

typedef struct numbers {
    int digit[digitnum];
    int ansvalue;
};

struct numbers ans;

void decideAnswer();
bool isSame(struct numbers);
struct numbers input(struct numbers predict);
void gameclear();
void gameover();
//struct numbers input(struct numbers predict) {
//    char input[CHARBUFF];
//    bool inputflag = false;
//    while (1) {
//        scanf_s("%s", &input);
//        inputflag = true;
//
//        if (strlen(input) != digitnum) {
//            fprintf_s(stdout, "%dŒ…“ü—Í", digitnum);
//            continue;
//        }
//
//        for (int i = 0; i < digitnum; i++) {
//            if (!isdigit(input[i])) {
//                continue;
//                fprintf_s(stdout, "”Žš‚ð“ü—Í\n");
//            }
//        }
//        break;
//    }
//    scanf_s("%s", &input, CHARBUFF);
//
//    for (int i = 0; i < digitnum; i++) {
//        predict.digit[i] = atoi(&input[i]);
//    }
//    predict.ansvalue = 0;
//    predict.ansvalue = predict.digit[0] * 100 + predict.digit[1] * 10 + predict.digit[2];
//    for (int i = 0; i < digitnum; i++) {
//        predict.ansvalue += predict.digit[i] * pow(10, 2 - i);
//    }
//    fprintf_s(stdout, "%d\n", predict.ansvalue);
//    for (int i = 0; i < digitnum; i++) {
//        fprintf_s(stdout, "%d\n", predict.digit[i]);
//    }
//    return predict;
//}