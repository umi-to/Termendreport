
#include <stdio.h>
#define CHARBUFF 124

const int digitnum = 3;
typedef struct numbers {
    int digit[digitnum];
    int ansvalue;
};

void gameclear() {
    fprintf_s(stdout, "ゲームクリア！！！！\n");
}

void gameover(struct numbers ans) {
    fprintf_s(stdout, "ゲームオーバー...\n正解は");
    for (int i = 0; i < digitnum; i++) {
        fprintf_s(stdout, "%d", ans.digit[i]);
    }
    fprintf_s(stdout, "\n");
}
/*
プログラムを行う度に新しく結果ファイルを生成する。すでにある結果ファイルの上書きを防ぐ。
このゲームの結果ファイルがいくつ存在するかを管理している。
今ある結果ファイルの個数を管理するテキストファイルを作成し、その値を読み込む
ResultCount.txtが存在すればそこに書かれている値を読み取りそこに書かれている値を返す。
存在しなければ新しくこのファイルを作成し0を返す。
*/
int countResult() {
    int fileCount = 0;
    FILE* fp;
    char filename[CHARBUFF];
    int fc = 0;
    errno_t error;
    error = fopen_s(&fp, "ResultCount.txt", "a+");
    if (error != 0)
        fprintf_s(stderr, "failed to open");
    else {

        while (fscanf_s(fp, "%d", &fc) != EOF) {
            fileCount = fc;
            fprintf_s(stdout, "%d", fc);
        };

        fprintf(fp, "%d\n", fileCount + 1);
        fclose(fp);
    }
    return fileCount;
}

void createResult(struct numbers predict[], struct numbers ans, int predictcount) {
    FILE* fp;
    char filename[CHARBUFF];
    int fileCount = countResult();  //結果ファイルがいくつ存在しているかを数える。
    int fc = 0;
    errno_t error;

    //ファイル名は「Hit&BlowResult_ファイル番号」
    sprintf_s(filename, "Hit&BlowResult_%d.csv", fileCount + 1);

    error = fopen_s(&fp, filename, "w");
    if (error != 0)
        fprintf_s(stderr, "failed to open");
    else {

        fprintf(fp, "%s,", "答え");
        for (int i = 0; i < digitnum; i++) {
            fprintf(fp, "%d,", ans.digit[i]);
        }
        fprintf(fp, "\n");
        for (int i = 0; i < predictcount; i++) {
            fprintf(fp, "%d回目の入力,", i + 1);
            for (int j = 0; j < digitnum; j++) {
                fprintf(fp, "%d,", predict[i].digit[j]);
            }
            fprintf(fp, "\n");
        }

        fclose(fp);
    }

    //ResultCount.txt１に新しくファイルの個数を書き込む
    error = fopen_s(&fp, "ResultCount.txt", "w");
    if (error != 0)
        fprintf_s(stderr, "failed to open");
    else {

        fprintf(fp, "%d\n", fileCount + 1);
        fclose(fp);
    }
}