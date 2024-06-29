#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int str_comp_notUpLow(char* s1,char* s2){
    int i = 0;
    while(1){
        char a = s1[i], b = s2[i];
        if('A' <= a && 'Z' >= a){
            a += 32;
        }
        if('A' <= b && 'Z' >= b){
            b += 32;
        }
        if(a=='\0'){
            //一致した場合
            if(b=='\0'){
                return 0;
            }
            return -1;
        }
        else if(b=='\0'){
            return 1;
        }
        else if(a-b<0){
            return -1;
        }
        else if(a-b>0){
            return 1;
        }
        ++i;
    }
}

void swap(int* x,int* y){
    int buff = *x;
    *x = *y;
    *y = buff;
    return;
}
void word_quick_sort(char* word,int* NumArr,int left,int right){
    if(left+1>=right){
        return;
    }
    int pivotNum = NumArr[right-1];
    int cur_index = left;
    for(int i=left;i<right-1;++i){
        if(str_comp_notUpLow(&word[NumArr[i]],&word[pivotNum]) < 0){
            swap(&NumArr[cur_index],&NumArr[i]);
            cur_index++;
        }
    }
    swap(&NumArr[cur_index],&NumArr[right-1]);
    word_quick_sort(word,NumArr,left,cur_index);
    word_quick_sort(word,NumArr,cur_index+1,right);
}

int main() {
    int NumArr[50000] = {};
    int LenNumArr = 0;
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
            ++LenNumArr;
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

    //比較and並び替え//長さは単語分割時に同時カウント
    word_quick_sort(word,NumArr,0,LenNumArr);

    i = 0;
    while(1){
        // 配列の最初を―1で固定//数値の0が、文字に変換すると'\000'で、終端文字ではなく数値に反応している
        if(NumArr[i] == '\0'){
            break;
        }
        printf("%s",&word[NumArr[i]]);
        ++i;
    }

    return 0;
}