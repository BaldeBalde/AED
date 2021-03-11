#include <stdio.h>
#include <stdlib.h>

void HeapMax(int*,int,int);
void HeapSort(int*,int);
void mostrar(int*,int);

int main(void) {
    int *vetor,n,a,i;

    scanf("%d",&n);

    vetor = (int*)malloc(n*sizeof(int));

    for(i = 0 ; i < n ; i++) {
        scanf("%d",&a);
        vetor[i] = a;
    }

    mostrar(vetor,n);
    HeapSort(vetor,n);
    mostrar(vetor,n);

    return 0;
}


void HeapMax(int* vetor,int i, int f) {
    int aux = vetor[i];
    int k = i*2 + 1;
    while(k <= f) {
        if(k < f) {
            if(vetor[k] < vetor[k+1]) {
                k = k + 1;
            }
        }
        if (aux < vetor[k]) {
            vetor[i] = vetor[k];
            i = k;
            k = 2*i + 1;
        } else {
            k = f + 1;
        }
    }
    vetor[i] = aux;
}

void HeapSort(int* vetor,int n) {
    int i,aux;
    for( i = (n - 1)/2; i >= 0 ; i--) {
        HeapMax(vetor,i,n-1);
    }
        mostrar(vetor,n);
    for(i = n - 1 ; i >= 0 ; i--) {
        aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;
        HeapMax(vetor,0,i - 1);
        mostrar(vetor,i);
    }
}

void mostrar(int* vetor, int n) {
    int i;
    for( i = 0 ; i < n ; i++) {
        printf("%d%s", vetor[i], i < n - 1?" ":"\n");
    }
}