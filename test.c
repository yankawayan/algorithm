#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    // strcmp => "AA" < "AaA" => 数字が少ないほうが、辞書順手前
    char word[] = {-1,'A','A','\0','A','C','\0','A','a','C','\0'};
    // 1 4 7
    printf("%s",*(&word[1]+4));

    return 0;
}