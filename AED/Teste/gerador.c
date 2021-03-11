#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    int *vetor,n,i,a;

    n = 10;

    vetor = (int*)malloc(n*sizeof(int));

    for(i = 0; i < n ; i++) {
        vetor[i] = rand()%100;
    }

    a = rand()%10;


    printf("%d\n",n);
    for(i = 0; i < n ; i++) {
        printf("%d%s",vetor[i], i < n - 1?" ":"\n");
    }
    printf("%d",vetor[a]);


}