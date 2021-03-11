#include <stdio.h>
#include <stdlib.h>

void quicksort(int*,int,int,int);
int particiona(int*,int,int,int);
void mostrar(int*,int);

int main(void) {
    int *vetor,n,a,i;
    scanf("%d",&n);
    vetor = (int*)malloc(n*sizeof(int));

    for( i = 0 ; i < n ; i++) {
        scanf("%d", &a);
        vetor[i] = a;
    }

    mostrar(vetor,n);
    quicksort(vetor,0,n-1,n);
    mostrar(vetor,n);


    return 0;
}

void quicksort(int* vetor,int pinicial, int pfinal,int n) {
    int pivo;
    if(pfinal > pinicial) {
        mostrar(vetor,n);
        pivo = particiona(vetor,pinicial,pfinal,n);
        mostrar(vetor,n);
        quicksort(vetor,pinicial,pivo-1,n);
        quicksort(vetor,pivo+1,pfinal,n);
    }
}

int particiona(int* vetor,int pinicial, int pfinal,int n) {
    int esq,dir,pivo,aux;
    esq = pinicial;
    dir = pfinal;
    pivo = vetor[pinicial];
    while(esq < dir) {
        mostrar(vetor,n);
        while(esq <= pfinal && vetor[esq] <= pivo) {
            esq++;
        }
        while(dir >= 0 && vetor[dir] > pivo) {
            dir--;
        }
        if(esq < dir) {
            aux = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = aux;
        }
        mostrar(vetor,n);
    }
        vetor[pinicial] = vetor[dir];
        vetor[dir] = pivo;
        return dir;
}

void mostrar(int* vetor, int n) {
    int i;
    for(i = 0 ; i < n ; i++) {
        printf("%d%s",vetor[i], i < n - 1?" ":"\n");
    }
}