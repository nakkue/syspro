#include <stdio.h>

/* 텍스트 파일 내용을 표준출력에 출력 */
int main(int argc, char *argv[]) {
    FILE *fp;
    int c;

    if (argc < 2)
        fp = stdin;                 // 인수가 없으면 표준입력 사용
    else
        fp = fopen(argv[1], "r");   // 읽기 전용으로 파일 열기

    c = getc(fp);                   // 문자 읽기
    while (c != EOF) {              // 파일 끝까지
        putc(c, stdout);            // 출력
        c = getc(fp);
    }

    fclose(fp);
    return 0;
}

