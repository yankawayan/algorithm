#include <stdio.h>
#include <stdlib.h>

int main() {
    int N,input,x,y;
    int *heap;

    scanf("%d",&N);
    // !:type(int) -2,147,483,647 ~ 2,147,483,647
    // T: calloc と　malloc　について
    heap = (int*)calloc(N,sizeof(int));
    for (int i = 0; i < N; ++i) {
        scanf("%d",&input);
        //printf("%d\n",heap[input-1]);
        if(heap[input-1] == 0){
            heap[input-1] = 1;
        }
        else if(heap[input-1] == 1){
            heap[input-1] = -1;
        }
    }

    printf("\n");
    x = 0,y = 0;
    for (int i = 0; i < N; ++i) {
        if (heap[i] == 0){
            x = i+1;
        }
        if (heap[i] == -1){
            y = i+1;
        }
    }
    if(x==0||y==0){
        printf("Correct");
    }
    else{
        printf("%d %d",y,x);
    }
    
    free(heap);
    return 0;
}