#include <stdio.h>
#include <stdlib.h>

void heapmax(int*,int);
void heapifymax(int*,int,int);
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

void heapmax(int* vetor, int n) {
    int i,c = 0;
    i = n/2 - 1;
    while(i >= 0) {
        if (c > 0 && i > 0) {
            i--;
        }
        c++;
        heapifymax(vetor,n,i);
        if(i == 0) {
            i--;
        }
    }
}

void heapifymax(int* vetor, int n, int i) {
    int pai = i, max, aux;
    int filhoEsq = i*2 + 1;
    int filhoDir = i*2 + 2;
        if(filhoEsq < n && vetor[filhoEsq] >= vetor[pai]) {
            max = filhoEsq;
        } else {
            max = pai;
        }

        if(filhoDir < n && vetor[filhoDir] >= vetor[max]) {
            max = filhoDir;
        }

        if(max != pai && max < n) {
            aux = vetor[pai];
            vetor[pai] = vetor[max];
            vetor[max] = aux;
            heapifymax(vetor,n,max);
        }
    }


void HeapSort(int* vetor,int n) {
    int i,aux;

    heapmax(vetor,n);

    for(i = n - 1 ; i >= 1 ; i--) {
        aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;
        heapifymax(vetor,n,i);
        mostrar(vetor,n);
    }
}

void mostrar(int* vetor, int n) {
    int i;
    for( i = 0 ; i < n ; i++) {
        printf("%d%s", vetor[i], i < n - 1?" ":"\n");
    }
}