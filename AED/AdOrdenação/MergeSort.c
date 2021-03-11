#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergeSort(int*,int,int);
void mergeTwoArrays(int*,int,int,int);
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

    mergeSort(vetor,0,n-1);

    mostrar(vetor,n);

    return 0;
}


void mergeSort(int* vetor, int pinicial, int pfinal) {
    if (pfinal <= pinicial) {
        return;
    } else {
        int pmeio = pinicial + (pfinal - pinicial)/2;
        mergeSort(vetor,pinicial,pmeio);
        mergeSort(vetor,pmeio+1,pfinal);
        mergeTwoArrays(vetor,pinicial,pmeio,pfinal);
    }
}

void mergeTwoArrays(int* vetor, int pinicial , int pmeio, int pfinal) {
    int *vetortemp,k;
    vetortemp = (int*)malloc((pfinal+1)*sizeof(int));
    int indexprimeirapartevetor = pinicial;
    int indexsegundapartevetor = pmeio + 1;

    for(k = pinicial ; k <= pfinal ; k++) {
        vetortemp[k] = vetor[k];
    }

    for(k = pinicial ; k <= pfinal ; k++) {
        if(indexprimeirapartevetor > pmeio) {
            vetor[k] = vetortemp[indexsegundapartevetor];
            indexsegundapartevetor++;
        } else if (indexsegundapartevetor > pfinal) {
            vetor[k] = vetortemp[indexprimeirapartevetor];
            indexprimeirapartevetor++;
        } else if (vetortemp[indexprimeirapartevetor] < vetortemp[indexsegundapartevetor]) {
            vetor[k] = vetortemp[indexprimeirapartevetor];
            indexprimeirapartevetor++;
        } else {
            vetor[k] = vetortemp[indexsegundapartevetor];
            indexsegundapartevetor++;
        }
    }
}

void mostrar(int* vetor, int n) {
    int i;
    for(i = 0 ; i < n ; i++) {
        printf("%d%s", vetor[i], i%10 !=9?" ":"\n");
    }
    printf("---------------------\n");
}