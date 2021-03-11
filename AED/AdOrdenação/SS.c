#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void selectionsort(int*,int);

int main(void) {
    srand(time(NULL));

    int *vetor, n, i;

    scanf("%d", &n);

    vetor = (int*)malloc(n*sizeof(int));

    for(i = 0 ; i < n ; i++) {
        vetor[i] = rand()%100;
    }

    for(i = 0 ; i < n ; i++) {
        printf("%d%s", vetor[i], i < n - 1?" ":"\n");
    }

    selectionsort(vetor,n);

    for(i = 0 ; i < n ; i++) {
        printf("%d%s", vetor[i], i < n - 1?" ":"\n");
    }

    return 0;
}

void selectionsort(int* vetor, int n) {
    int aux,i,j,menor;
    for(i = 0 ; i < n - 1; i++) {
        menor = i;
        for(j = i + 1 ; j < n ; j++) {
            if(vetor[j] < vetor[menor]) {
                menor = j;
            }
        }

        if ( menor != i) {
            aux = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = aux;
        }
    }

}