#include <stdio.h>
#include <stdlib.h>

void minheap(int*,int);
void minheapify(int*,int,int);
void menorelemento(int*,int);
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
        menorelemento(vetor,n);
        minheap(vetor,n);
        mostrar(vetor,n);
        scanf("%d", &n);
    }
    printf("\n");

    return 0;
}

void minheap(int* vetor,int n) {
    int i;
    i = n/2;
    while(i > 0) {
        i--;
        minheapify(vetor,n,i);
    }
}

void minheapify(int* vetor,int n, int i) {
    int e,d,max,aux;
    e = 2*i + 1;
    d = 2*i + 2;

    if (e <= n && vetor[e] <= vetor [i]) {
        max = e;
    } else {
        max = i;
    }

    if (d <= n && vetor[d] <= vetor[max]) {
        max = d;
    }

    if (max != i && max < n) {
        aux = vetor[i];
        vetor[i] = vetor[max];
        vetor[max] = aux;
        minheapify(vetor,n,max);
    }

}

void menorelemento(int* vetor,int n) {
    int i, aux = n-1, c = 0;
    for(i = 0 ; i < n - 1 ; i++) {
        if(vetor[i] < vetor[aux]) {
            c = 1;
        }
    }

    if(c == 0) {
        aux = vetor[n-2];
        vetor[n-2] = vetor[n-1];
        vetor[n-1] = aux;
    }

}

void mostrar(int* vetor,int n) {
    int i;
    for(i = 0 ; i < n ; i++) {
        printf("%d%s", vetor[i], i < n - 1?" ":"\n");
    }
}