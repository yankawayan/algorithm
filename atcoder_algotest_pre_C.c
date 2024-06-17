#include <stdio.h>
#include <stdlib.h>

int main() {
    int a[7],max=0,maxArrN=0;

    for(int i=0;i<6;++i){
        scanf("%d", &a[i]);
    }
    // T:バブルソート
    for(int i=0;i<3;++i){
        for(int j=i;j<6;++j){
            if(max < a[j]){
                max = a[j];
                maxArrN = j;
            }
        }
        a[maxArrN] = a[i];
        a[i] = max;
        max = 0;
    }
    printf("%d",a[2]);

    return 0;
}