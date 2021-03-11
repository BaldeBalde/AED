#include <stdio.h>
#include <stdlib.h>

void heapmax(int*,int);
void heapifymax(int*,int,int);
void mostrar(int*,int);

int main(void) {
    int *vetor,n,a,i;
    do {
        scanf("%d",&n);
        vetor = (int*)malloc(n*sizeof(int));

        for(i = 0; i < n ; i++) {
            scanf("%d",&a);
            vetor[i] = a;
        }

        heapmax(vetor,n);
        mostrar(vetor,n);

    }while(n != 0);

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


void mostrar(int* vetor, int n) {
    int i;
    for( i = 0 ; i < n ; i++) {
        printf("%d%s", vetor[i], i < n - 1?" ":"\n");
    }
}