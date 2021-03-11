#include <stdio.h>
#include <stdlib.h>

void maxheap(int*,int);
void maxheapify(int*,int,int);
void mostrar(int*,int);


int main(void) {
    int *vetor,n,a,i;

    scanf("%d",&n);
    while(n != 0) {
        vetor = (int*)malloc(n*sizeof(int));
        for (i = 0 ; i < n ; i++) {
            scanf("%d", &a);
            vetor[i] = a;
        }
        maxheap(vetor,n);
        mostrar(vetor,n);
        scanf("%d", &n);
    }

    return 0;
}

void maxheap(int* vetor,int n) {
    int i, c = 0;
    i = n/2 - 1;
    do{
        if(c > 0) {
            i--;
        }
        maxheapify(vetor,n,i);
        c++;
    }while(i>0);
}

void maxheapify(int* vetor,int n, int i) {
    int e,d,max,aux;
    e = 2*i + 1;
    d = 2*i + 2;

    if (e <= n && vetor[e] >= vetor [i]) {
        max = e;
    } else {
        max = i;
    }

    if (d <= n && vetor[d] >= vetor[max]) {
        max = d;
    }

    if (max != i && max < n) {
        aux = vetor[i];
        vetor[i] = vetor[max];
        vetor[max] = aux;
        maxheapify(vetor,n,max);
    }

}

void mostrar(int* vetor,int n) {
    int i;
    for(i = 0 ; i < n ; i++) {
        printf("%d%s", vetor[i], i < n - 1?" ":"\n");
    }
}