#include <stdio.h>
#include <stdlib.h>

void mostrar(int*,int);
int posicao(int*,int,int);

int main(void) {
    int *vetor,n,a,i,p,resultado;

    scanf("%d",&n);
    vetor = (int*)malloc(n*sizeof(int));

    for(i = 0 ; i < n ; i++) {
        scanf("%d",&a);
        vetor[i] = a;
    }

    scanf("%d",&p);

    resultado = posicao(vetor,n,p);
    printf("%d\n",resultado);

    return 0;
}


void mostrar(int* vetor, int n) {
    int i;
    for(i = 0 ; i < n ; i++) {
        printf("%d%s",vetor[i], i < n - 1?" ":"\n");
    }
}

int posicao(int* vetor, int n, int p) {
    int i,c = 0;
    for(i = 0 ; i < n ; i++) {
        if(p > vetor[i]) {
            c++;
        }
    }
    return c;
}
