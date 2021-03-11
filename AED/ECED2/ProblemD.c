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
    int i,j,aux, k;
    for(i = 1 ; i < n ; i++) {
        printf("Sublista Ordenada: ");
        for(k = 0 ; k < i ; k++) {
            printf("%d%s", vetor[k], k < i - 1?" ":"");
        }
        printf("\n");
        printf("Sublista Desordenada: ");
        for(k = i ; k < n ; k++) {
            printf("%d%s", vetor[k], k < n - 1?" ":"");
        }
        printf("\n");
        aux = vetor[i];
        for(j = i ; (j > 0) && (aux < vetor[j-1]) ; j--) {
            vetor[j] = vetor[j-1];
        }
        vetor[j] = aux;
    }
        printf("Sublista Ordenada: ");
        for(k = 0 ; k < i ; k++) {
            printf("%d%s", vetor[k], k < i - 1?" ":"");
        }
        printf("\n");
        printf("Sublista Desordenada:");
        for(k = i ; k < n ; k++) {
            printf("%d%s", vetor[k], k < n - 1?" ":"");
        }
        printf("\n");

}