#include <stdio.h>
#include <stdlib.h>

void particiona(int*,int,int);
void mostrar(int*,int);
int ultimaposicao(int*,int,int);

int main(void) {
    int *vetor,n,a,i,p;

    scanf("%d",&n);
    scanf("%d",&p);

    vetor = (int*)malloc(n*sizeof(int));

    for(i = 0 ; i < n ; i++) {
        scanf("%d",&a);
        vetor[i] = a;
    }

    particiona(vetor,n,p);
    mostrar(vetor,n);

    return 0;
}

void particiona(int *vetor, int n, int p) {
    int i = 0, pm = -1,aux;

    p = ultimaposicao(vetor,n,p);

    while(i < n - 1) {
        if(vetor[i] <= vetor[p]) {
            pm = pm + 1;
            aux = vetor[i];
            vetor[i] = vetor[pm];
            vetor[pm] = aux;
        }
        i = i + 1;
    }

    if(i >= n - 1) {
        pm = pm + 1;
        aux = vetor[p];
        vetor[p] = vetor[pm];
        vetor[pm] = aux;
    }
}



void mostrar(int* vetor, int n) {
    int i;
    for( i = 0 ; i < n ; i++) {
        printf("%d\n", vetor[i]);
    }
}

int ultimaposicao(int* vetor,int n, int p) {
    int aux;
    aux = vetor[n-1];
    vetor[n-1] = vetor[p];
    vetor[p] = aux;

    return n-1;
}