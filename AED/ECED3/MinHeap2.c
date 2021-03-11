#include <stdio.h>
#include <stdlib.h>

void heapmin(int*,int);
void heapifymin(int*,int,int);
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

        heapmin(vetor,n);
        mostrar(vetor,n);

    }while(n != 0);

    return 0;
}

void heapmin(int* vetor, int n) {
    int i,c = 0;
    i = n/2 - 1;
    while(i >= 0) {
        if (c > 0 && i > 0) {
            i--;
        }
        c++;
        heapifymin(vetor,n,i);
        if(i == 0) {
            i--;
        }
    }
}

void heapifymin(int* vetor, int n, int i) {
    int pai = i, min, aux;
    int filhoEsq = i*2 + 1;
    int filhoDir = i*2 + 2;
        if(filhoEsq < n && vetor[filhoEsq] <= vetor[pai]) {
            min = filhoEsq;
        } else {
            min = pai;
        }

        if(filhoDir < n && vetor[filhoDir] <= vetor[min]) {
            min = filhoDir;
        }

        if(min != pai && min < n) {
            aux = vetor[pai];
            vetor[pai] = vetor[min];
            vetor[min] = aux;
            heapifymin(vetor,n,min);
        }
    }


void mostrar(int* vetor, int n) {
    int i;
    for( i = 0 ; i < n ; i++) {
        printf("%d%s", vetor[i], i < n - 1?" ":"\n");
    }
}