#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int*,int,int);
int particiona(int*,int,int);
void mostrar(int*,int);


int main(void) {
    srand(time(NULL));
    int *vetor,n,i;

    scanf("%d",&n);
    vetor = (int*)malloc(n*sizeof(int));

    for(i = 0 ; i < n ; i++) {
        vetor[i] = rand()%1000;
    }

    mostrar(vetor,n);
    quicksort(vetor,0,n-1);
    mostrar(vetor,n);

    return 0;
}

void quicksort(int* vetor,int pinicial, int pfinal) {
    int pivo;
    if(pfinal > pinicial) {
        pivo = particiona(vetor,pinicial,pfinal);
        quicksort(vetor,pinicial,pivo-1);
        quicksort(vetor,pivo+1,pfinal);
    }
}

int particiona(int* vetor,int pinicial, int pfinal) {
    int esq,dir,pivo,aux;
    esq = pinicial;
    dir = pfinal;
    pivo = vetor[pinicial];
    while(esq < dir) {
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
    }
        vetor[pinicial] = vetor[dir];
        vetor[dir] = pivo;
        return dir;
}

void mostrar(int* vetor, int n) {
    int i;
    for(i = 0 ; i < n ; i++) {
        printf("%d%s",vetor[i], i%10 != 9?" ":"\n");
    }
    printf("--------------------------------------\n");
}