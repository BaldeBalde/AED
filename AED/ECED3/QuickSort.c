#include <stdio.h>
#include <stdlib.h>

int particiona(int*,int,int);
void quicksort(int*,int,int,int);
void mostrar(int*,int);

int main(void) {
    int *vetor,n,a,i,p;

    scanf("%d",&n);

    vetor = (int*)malloc(n*sizeof(int));

    for(i = 0 ; i < n ; i++) {
        scanf("%d",&a);
        vetor[i] = a;
    }

    mostrar(vetor,n);
    quicksort(vetor,n,1,n-1);
    mostrar(vetor,n);

    return 0;
}

int particiona(int *vetor, int n, int p) {
    int i = 0, pm = -1,aux;

    while(i < n - 1) {
        if(vetor[i] <= vetor[p]) {
            pm = pm + 1;
            aux = vetor[i];
            vetor[i] = vetor[pm];
            vetor[pm] = aux;
        }
        i = i + 1;
    }

    if(i == n - 1) {
        pm = pm + 1;
        aux = vetor[p];
        vetor[p] = vetor[pm];
        vetor[pm] = aux;
    }

    return pm;
}

void quicksort(int* vetor,int n,int esq,int dir) {
    int p;
    if (dir > esq) {
        p = particiona(vetor,esq,dir);
        quicksort(vetor,n,esq,p-1);
        quicksort(vetor,n,p+1,dir);
    }
}

void mostrar(int* vetor, int n) {
    int i;
    for( i = 0 ; i < n ; i++) {
        printf("%d%s", vetor[i], i < n - 1?" ":"\n");
    }
}
