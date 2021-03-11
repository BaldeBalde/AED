#include <stdio.h>
#include <stdlib.h>

void insertionsort(int*,int);

int main(void) {
    int *vetor, n, a, i;

    scanf("%d", &n);

    vetor = (int*)malloc(n*sizeof(int));

    for(i = 0 ; i < n ; i++) {
        scanf("%d", &a);
        vetor[i] = a;
    }
    insertionsort(vetor, n);


    return 0;
}

void insertionsort(int* vetor, int n) {
    int i, j, aux, k = 0;
    for(i = 1 ; i < n ; i++) {
        aux = vetor[i];
        for(j = i ; (j > 0) && (aux < vetor[j-1]) ; j--) {
            vetor[j] = vetor[j-1];
        }
        vetor[j] = aux;

        for( k = 0 ; k < n ; k++) {
            printf("%d%s", vetor[k], k < n-1?" ":"\n");
        }
    }
}