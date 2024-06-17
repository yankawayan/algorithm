#include <stdio.h>
#include <stdlib.h>

int main() {
    int N,oneBefore,diff,i;
    int *heap;

    // N を整数として読み込む
    scanf("%d", &N);

    heap = (int*)malloc(N * sizeof(int));

    i = 0;
    scanf("%d", &heap[i]);
    oneBefore = heap[i];
    // N 個の整数を配列 a に読み込む
    for (int i = 1; i < N; ++i) {
        scanf("%d", &heap[i]);
        diff = heap[i]-oneBefore;
        if(diff>0){
            printf("up %d\n",diff);
        }
        else if(diff<0){
            printf("down %d\n",-1*diff);
        }
        else{
            printf("stay\n");
        }
        oneBefore=heap[i];
    }

    // // 配列 a の中身を出力する
    // printf("Contents of array heap:\n");
    // for (int i = 0; i < N; ++i) {
    //     printf("%d\n", heap[i]);
    // }

    free(heap);

    return 0;
}