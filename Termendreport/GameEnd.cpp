
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
}

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

        fprintf_s(stdout, "%d", fileCount);
        fprintf(fp, "%d\n", fileCount + 1);
        fclose(fp);
    }
    return fileCount;
}

void createResult(struct numbers predict[], struct numbers ans, int predictcount) {
    FILE* fp;
    char filename[CHARBUFF];
    int fileCount = countResult();
    int fc = 0;
    errno_t error;

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

    error = fopen_s(&fp, "ResultCount.txt", "w");
    if (error != 0)
        fprintf_s(stderr, "failed to open");
    else {

        fprintf(fp, "%d\n", fileCount + 1);
        fclose(fp);
    }
}