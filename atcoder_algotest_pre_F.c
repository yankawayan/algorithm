#include <stdio.h>
#include <stdlib.h>

int main() {
    char NumArr[50000] = {};
    //NULL終端？ '\0' で単語を区切って、文字列に保存、頭の配列文字をNumArrに保存
    int i = 0,j = 0;
    char word[150000] = {};
    while(1){
        scanf("%c",&word[i]);
        //単語の初め
        if(word[i] >= 'A' && word[i] <= 'Z'){
            //単語初めの位置を保存
            NumArr[j] = i;
            ++j;
            ++i;
            scanf("%c",&word[i]);
            //単語の終わり
            while(!(word[i] >= 'A' && word[i] <= 'Z')){
                ++i;
                scanf("%c",&word[i]);
            }
            ++i;
            word[i] = '\0';
            ++i;
        }
        else if(word[i] == '\n'){
            break;
        }
    }
    i = 0;
    while(1){
        printf("%d ",NumArr[i]);
        j = NumArr[i];
        while(1){
            printf("%c",word[j]);
            ++j;
            if(word[j] == '\0'){
                break;
            }
        }
        ++i;
        printf("\n");
        if(NumArr[i] == '\0'){
            break;
        }
    }
    printf("%s",&word[5]);
    return 0;
}