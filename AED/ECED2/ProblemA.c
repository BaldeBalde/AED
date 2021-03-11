#include <stdio.h>
#include <stdlib.h>


int bubblesort(int*,int);

int main(void) {
    int *vet, n, a, i, nt;
    scanf("%d", &n);

    vet = (int*)malloc(n*sizeof(int));

    for(i = 0 ; i < n ; i++) {
        scanf("%d",&a);
        vet[i] = a;
    }

    for(i = 0 ; i < n ; i++) {
        printf("%d%s", vet[i], i < n-1?" ":"\n");
    }

    nt = bubblesort(vet,n);

    for(i = 0 ; i < n ; i++) {
        printf("%d%s", vet[i], i < n-1?" ":"\n");
    }

    printf("Trocas: %d\n", nt);


    return 0;
}

int bubblesort(int* vetor, int n) {
    int i, cont, aux, troca = 0, j;
    for(cont = 1 ; cont < n ; cont++) {
        for(i = 0 ; i < n - 1 ; i++) {
            if(vetor[i] > vetor[i+1]) {
                aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
                for(j = 0 ; j < n ; j++) {
                    printf("%d%s", vetor[j], j < n-1?" ":"\n");
                }
                troca = troca + 1;
            }

        }
    }

    return troca;
}