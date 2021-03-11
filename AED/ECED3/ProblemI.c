#include <stdio.h>
#include <stdlib.h>

void heapmin(int*,int);
void heapifymin(int*,int,int);
void inserir(int*,int,int,int);
void remover(int*,int,int,int);
void mostrarmin(int*,int);
void mostrar(int*,int);

int main(void) {
    int *vetor,n,a,i,command,quant = 0, c;

    scanf("%d",&n);
    c = n;
    vetor = (int*)malloc(n*sizeof(int));

    while(c > 0) {
        scanf("%d",&command);
        if(command == 1) {
            scanf("%d",&a);
            inserir(vetor,n,a,quant);
            if( quant < n) {
                quant = quant + 1;
            }
            heapmin(vetor,quant);
        } else if (command == 2) {
            scanf("%d",&a);
            remover(vetor,n,a,quant);
            if(quant > 0) {
                quant = quant - 1;
            }
            heapmin(vetor,quant);
        } else if (command == 3) {
            mostrarmin(vetor,quant);
        }
        c--;
    }

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

void inserir(int* vetor, int n, int a, int quant) {
    if(quant < n) {
        vetor[quant] = a;
    }
}

void remover(int* vetor, int n, int a, int quant) {
    int i,aux,j;
    for(i = quant - 1 ; i >= 0 ; i--) {
        if(vetor[i] == a) {
            for( j = i ; j < quant - 1 ; j++) {
                vetor[j] = vetor[j + 1];
            }
        }
    }
}

void mostrarmin(int* vetor, int quant) {
    int i,menor = 0;
    for( i = 0 ; i < quant ; i++) {
        if(vetor[menor] > vetor[i]) {
            menor = i;
        }
    }
    printf("%d\n",vetor[menor]);
}

void mostrar(int* vetor, int quant) {
    int i;
    for( i = 0 ; i < quant ; i++) {
        printf("%d%s", vetor[i], i < quant - 1?" ":"\n");
    }
}