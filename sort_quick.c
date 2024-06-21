#include <stdio.h>
#include <stdlib.h>
//参考 https://paiza.jp/works/mondai/sort_efficient/sort_efficient__quick?language_uid=r#:~:text=%E3%82%AF%E3%82%A4%E3%83%83%E3%82%AF%E3%82%BD%E3%83%BC%E3%83%88%E3%81%AF%E3%80%81%20%E3%83%94%E3%83%9C%E3%83%83%E3%83%88%E3%81%A8,%E7%9A%84%E3%81%AB%E8%A1%8C%E3%81%86%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0%E3%81%A7%E3%81%99%E3%80%82
void swap(int* x,int* y){
    int buff = *x;
    *x = *y;
    *y = buff;
    return;
}
void quick_sort(int* arr,int left,int right){
    if(left+1>=right){
        return;
    }
    int pivot = arr[right-1];
    int cur_index = left;
    for(int i=left;i<right-1;++i){
        if(arr[i]<pivot){
            swap(&arr[cur_index],&arr[i]);
            cur_index++;
        }
    }
    swap(&arr[cur_index],&arr[right-1]);
    quick_sort(arr,left,cur_index);
    quick_sort(arr,cur_index+1,right);
}