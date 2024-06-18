#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    int *heap;

    // N を整数として読み込む
    scanf("%d", &N);
    // 要素サイズintで動的に作成
    heap = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; ++i) {
        scanf("%d", &heap[i]);
    }

    free(heap);

    return 0;
}