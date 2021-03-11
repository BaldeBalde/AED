#include <stdio.h>
#include <stdlib.h>

void selectionsort(int*,int);
int notacorte(int*,int,int);

int main(void) {
    int *vetor, n, a, k, i, nota;

    scanf("%d", &n);
    scanf("%d", &k);

    vetor = (int*)malloc(n*sizeof(int));

    for(i = 0; i < n ; i++) {
        scanf("%d", &a);
        vetor[i] = a;
    }

    selectionsort(vetor,n);
    nota = notacorte(vetor,k,n);
    printf("%d\n", nota);


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

int notacorte(int* vetor, int k, int n) {
    int i,soma = 0;
    for(i = n - 1 ; i > (n - k - 1) ; i--) {
        soma = soma + vetor[i];
    }
    soma = soma/k;

    return soma;
}