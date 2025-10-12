#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int ch;

    if (argc == 1) { // 인수가 없으면 표준 입력 사용
        while ((ch = getchar()) != EOF)
            putchar(ch);
    } else {
        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            perror("파일 열기 오류");
            return 1;
        }
        while ((ch = fgetc(fp)) != EOF)
            putchar(ch);
        fclose(fp);
    }
    return 0;
}

