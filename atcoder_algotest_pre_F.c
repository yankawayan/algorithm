#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int* x,int* y){
    int buff = *x;
    *x = *y;
    *y = buff;
    return;
}
void word_quick_sort(int* word,int* NumArr,int left,int right){
    if(left+1>=right){
        return;
    }
    int pivotNum = NumArr[right-1];
    int cur_index = left;
    for(int i=left;i<right-1;++i){
        if((strcmp(&word[NumArr[i]],&word[pivotNum]))>0){
            swap(&NumArr[cur_index],&NumArr[i]);
            cur_index++;
        }
    }
    swap(&NumArr[cur_index],&NumArr[right-1]);
    word_quick_sort(word,NumArr,left,cur_index);
    word_quick_sort(word,NumArr,cur_index+1,right);
}

int main() {
    char NumArr[50000] = {};
    //NULL終端？ '\0' で単語を区切って、文字列に保存、頭の配列文字をNumArrに保存
    //NULL:ポインタ '\0':終端文字
    int i = 1,j = 0;
    char word[150001] = {};
    word[0] = -1;
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
    // i = 0;
    // while(1){
    //     printf("%d ",NumArr[i]);
    //     j = NumArr[i];
    //     while(1){
    //         printf("%c",word[j]);
    //         ++j;
    //         if(word[j] == '\0'){
    //             break;
    //         }
    //     }
    //     ++i;
    //     printf("\n");
    //     if(NumArr[i] == '\0'){
    //         break;
    //     }
    // }
    int len = sizeof NumArr / sizeof NumArr[0];
    //比較and並び替え
    word_quick_sort(word,NumArr,0,len);

    i = 0;
    while(1){
        // 配列の最初を―1で固定//数値の0が、文字に変換すると'\000'で、終端文字ではなく数値に反応している
        if(NumArr[i] == '\0'){
            break;
        }
        printf("%s\n",&word[NumArr[i]]);
        ++i;
    }

    return 0;
}