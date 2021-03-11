#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void bubblesort(int*,int);

int main(void){
    int *vetor, n, i;

    srand(time(NULL));

    scanf("%d", &n);

    vetor = (int*)malloc(n*sizeof(int));

    for(i = 0 ; i < n ; i++) {
        vetor[i] = rand()%100;
    }

    for(i = 0 ; i < n ; i++) {
        printf("%d%s", vetor[i], i < n - 1?" ":"\n");
    }

    bubblesort(vetor,n);

     for(i = 0 ; i < n ; i++) {
        printf("%d%s", vetor[i], i < n - 1?" ":"\n");
    }

    return 0;
}

void bubblesort(int* vetor, int n) {
    int i, cont, aux;
    for(cont = 1 ; cont < n ; cont++) {
        for(i = 0 ; i < n - 1 ; i++) {
            if(vetor[i] < vetor[i+1]) {
                aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
            }
        }
    }
}
