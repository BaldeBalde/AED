#include <stdio.h>
#include <stdlib.h>

void particiona(int*,int,int,int);
void mostrar(int*,int);
int buscalinear(int *, int, int);

int main(void) {
    int *vetor,n,a,i,p,q,resultado;

    scanf("%d",&n);
    vetor = (int*)malloc(n*sizeof(int));

    for(i = 0 ; i < n ; i++) {
        scanf("%d",&a);
        vetor[i] = a;
    }

    scanf("%d",&p);

    printf("p = %d\n", p);
    particiona(vetor,0,n-1,p);
    mostrar(vetor,n);
    resultado = buscalinear(vetor,n,p);

    printf("%d\n",resultado);
}

void particiona(int* vetor,int pinicial, int pfinal, int p) {
    int esq,dir,pivo,aux;
    esq = pinicial;
    dir = pfinal;
    pivo = p;

    while(esq < dir) {
        esq = pinicial;
        dir = pfinal;
        while(esq <= pfinal && vetor[esq] < pivo) {
            esq++;
        }
        while(dir >= 0 && vetor[dir] > pivo) {
            dir --;
        }
        if (esq < dir) {
            aux = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = aux;
        }
    }
}

void mostrar(int* vetor, int n) {
    int i;
    for(i = 0 ; i < n ; i++) {
        printf("%d%s",vetor[i], i < n - 1?" ":"\n");
    }
}


int buscalinear(int *vetor, int n, int vi) {
    int i;
    for (i = 0 ; i < n ; i++) {
        if(vi == vetor[i] ) {
            return i;
        } else if (i == n - 1) {
            return -1;
        }
    }
}