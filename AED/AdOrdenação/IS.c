#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionsort(int*,int);

int main(void) {
    srand(time(NULL));

    int i, n, *vetor;

    scanf("%d", &n);

    vetor = (int*)malloc(n*sizeof(int));

    for(i = 0 ; i < n ; i++) {
        vetor[i] = rand()%100;
    }

    for(i = 0 ; i < n ; i++) {
        printf("%d%s", vetor[i],i < n - 1?" ":"\n");
    }

    insertionsort(vetor,n);

    for(i = 0 ; i < n ; i++) {
        printf("%d%s", vetor[i],i < n - 1?" ":"\n");
    }

    return 0;
}


void insertionsort(int* vetor, int n) {
    int i,j,aux;
    for(i = 1 ; i < n ; i++) {
        aux = vetor[i];
        for(j = i ; (j > 0) && (aux < vetor[j-1]) ; j--) {
            vetor[j] = vetor[j-1];
        }
        vetor[j] = aux;
    }
}