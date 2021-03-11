#include <stdio.h>
#include <stdlib.h>

int insertionsort(int*,int);

int main(void) {
    int *vetor, n, a, i, trocas;

    scanf("%d", &n);

    vetor = (int*)malloc(n*sizeof(int));

    for(i = 0 ; i < n ; i++) {
        scanf("%d", &a);
        vetor[i] = a;
    }

    trocas = insertionsort(vetor, n);
    printf("%d\n", trocas);

    return 0;
}

int insertionsort(int* vetor, int n) {
    int i,j,aux, cont = 0;
    for(i = 1 ; i < n ; i++) {
        aux = vetor[i];
        for(j = i ; (j > 0) && (aux < vetor[j-1]) ; j--) {
            if(aux < vetor[j-1]) {
                cont++;
            }
            vetor[j] = vetor[j-1];
        }
        vetor[j] = aux;
    }
    return cont;
}