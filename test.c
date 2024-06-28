#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char* x,char* y){
    char buff = *x;
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

int main(void){
    // strcmp => "AA" < "AaA" => 数字が少ないほうが、辞書順手前
    char word[] = {-1,'A','A','\0','A','a','A','\0','K','a','k','O','\0'};
    int NumArr[] = {9,4,1};

    int len = sizeof NumArr / sizeof NumArr[0];
    word_quick_sort(word,NumArr,0,len);

    return 0;
}