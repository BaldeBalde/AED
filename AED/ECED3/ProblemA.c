#include <stdio.h>
#include <stdlib.h>

void intercalarvetor(int*,int*,int,int);
void mergeSort(int*,int,int);
void mergeTwoArrays(int*,int,int,int);
void mostrar(int*,int);

int main(void) {
    int *v1,*v2,n1,n2,a,i;

    scanf("%d",&n1);
    scanf("%d",&n2);

    v1 = (int*)malloc(n1*sizeof(int));
    v2 = (int*)malloc(n2*sizeof(int));

    for(i = 0 ; i < n1 ; i++) {
        scanf("%d",&a);
        v1[i] = a;
    }

    for(i = 0 ; i < n2 ; i++) {
        scanf("%d",&a);
        v2[i] = a;
    }

    intercalarvetor(v1,v2,n1,n2);

    return 0;
}

void intercalarvetor(int* v1,int* v2, int n1, int n2) {
    int *v,n,i,j = 0;
    n = n1+n2;
    v = (int*)malloc(n*sizeof(int));

    for(i = 0 ; i < n1 ; i++) {
        v[i] = v1[i];
    }
    for(i = n1 ; i < n ; i++) {
        v[i] = v2[j];
        j++;
    }

    mergeSort(v,0,n-1);
    mostrar(v,n);
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