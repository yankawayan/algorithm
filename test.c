#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int str_comp(char* s1,char* s2){
    int i = 0;
    while(1){
        if(s1[i]=='\0'){
            //一致した場合
            if(s2[i]=='\0'){
                return 0;
            }
            return -1;
        }
        else if(s2[i]=='\0'){
            return 1;
        }
        else if(s1[i]-s2[i]<0){
            return -1;
        }
        else if(s1[i]-s2[i]>0){
            return 1;
        }
        ++i;
    }
}

int main(void){
    // strcmp => "AA" < "AaA" => 数字が少ないほうが、辞書順手前
    char word[] = {-1,'A','A','\0','A','C','\0','A','a','C','\0'};
    // 1 4 7
    printf("%d %d %d %d",'C','c','A','a');


    return 0;
}