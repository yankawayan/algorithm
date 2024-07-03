#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_MAX 150001

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
        if(strcmp(&word[NumArr[i]],&word[pivotNum]) < 0){
            swap(&NumArr[cur_index],&NumArr[i]);
            cur_index++;
        }
    }
    swap(&NumArr[cur_index],&NumArr[right-1]);
    word_quick_sort(word,NumArr,left,cur_index);
    word_quick_sort(word,NumArr,cur_index+1,right);
}

int main() {
    int i = 1,j = 0,NumArr[50000] = {};
    char input,word[STR_MAX] = {};
    word[0] = -1;
    while(1){
        scanf("%c",&input);
        if(input == '\n'){
            break;
        }
        word[i] = input+32;
        NumArr[j] = i;
        ++j;
        ++i;
        scanf("%c",&input);
        //単語の終わり
        while(input >= 'a' && input <= 'z'){
            word[i] = input;
            ++i;
            scanf("%c",&input);
        }
        word[i] = input+32;
        ++i;
        word[i] = '\0';
        ++i;
    }
    //並び替え
    word_quick_sort(word,NumArr,0,j);
    i = 0;
    char* lett;
    while(1){
        if(NumArr[i] == '\0'){
            break;
        }
        j = 0;
        lett = &word[NumArr[i]];
        *lett-=32;
        printf("%c",*lett);
        while(1){
            lett++;
            if(*(lett+1) == '\0'){
                break;
            }
            printf("%c",*lett);
        }
        *lett-=32;
        printf("%c",*lett);
        ++i;
    }

    return 0;
}