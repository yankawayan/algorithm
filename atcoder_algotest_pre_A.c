#include <stdio.h>
#include <stdlib.h>

void main() {
    char s[4];  // 3文字+終端文字'\0'のためにサイズ4を確保
    scanf("%3s", s);  // 最大3文字の入力を受け取る

    for (int i = 0; i < 3; ++i) {
        if (!(s[i] >= '0' && s[i] <= '9')) {
            printf("error");
            return;
        }

        if (s[i + 1] == '\0' || i == 2) {
            int num = atoi(s) * 2;  // 文字列を整数に変換して2倍する
            printf("%d", num);
            return;
        }
    }
}
