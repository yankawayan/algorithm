#include <stdio.h>
#include <stdlib.h>

int main() {
    int N,Q,input,a,b;
    int *heap;

    scanf("%d %d",&N,&Q);
    // !:type(int) -2,147,483,647 ~ 2,147,483,647
    heap = (int*)calloc(N*N,sizeof(int));
    if (heap == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < Q; ++i){
        scanf("%d",&input);
        if(input==1){
            scanf("%d %d",&a,&b);
            heap[(a-1)*N+b-1] = 1;
        }
        else if(input==2){
            scanf("%d",&a);
            for(int i=0;i<N;++i){
                if(heap[a-1+N*i] == 1){
                    heap[(a-1)*N+i] = 1;
                }
            }
        }
        else if(input==3){
            scanf("%d",&a);
            int buff[101] = {};
            buff[N] = -1;
            for(int i=0;i<N;++i){
                if(heap[(a-1)*N+i]==1){
                    //反映直後に、反映した値が条件を通過している、
                    for(int j=0;j<N;++j){
                        // 
                        //printf("%d",heap[i*N+j]);
                        if(heap[i*N+j] == 1 && j != (a-1)){
                            //heap[(a-1)*N+j] = 1;
                            buff[j] = 1;
                        }
                    }
                }
            }
            for(int i=0;i<N;++i){
                if(buff[i]==1){
                    heap[(a-1)*N+i] = 1;
                }
            }
        }
    }
    
    for(int i = 0;i<N*N;++i){
        if(heap[i] == 0){
            printf("N");
        }
        else if(heap[i] == 1){
            printf("Y");
        }
        
        if((i+1)%N==0){
            printf("\n");
        }
    }

    free(heap);
    return 0;
}