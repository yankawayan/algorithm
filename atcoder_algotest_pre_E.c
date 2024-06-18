#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    int *heap;

    scanf("%d", &N);
    // !:type(int) -2,147,483,647 ~ 2,147,483,647
    heap = (int*)malloc(N * sizeof(int));
    // ?:同じサイズの配列をもう一つ用意して比較する場合と、一つの配列で並び替えた後、一つずつ確認する方法はどちらが早いか？
    for (int i = 0; i < N; ++i) {
        scanf("%d", &heap[i]);
    }
    // T:クイックソート

    free(heap);
    return 0;
}