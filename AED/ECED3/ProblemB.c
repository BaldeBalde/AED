#include <stdio.h>
#include <stdlib.h>

void mergeSort(int*,int,int);
void mergeTwoArrays(int*,int,int,int);
void mostrar(int*,int);

int main(void) {
    int *v,n1,n2,n,a,i, j = 0;

    scanf("%d",&n1);
    scanf("%d",&n2);
    n = n1 + n2;

    v = (int*)malloc(n*sizeof(int));

    for(i = 0 ; i < n1 ; i++) {
        scanf("%d", &a);
        v[i] = a;
    }
    for(i = n1 ; i < n ; i++) {
        scanf("%d",&a);
        v[i] = a;
    }

    mergeSort(v,0,n-1);
    mostrar(v,n);

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
        printf("%d\n", vetor[i]);
    }
}