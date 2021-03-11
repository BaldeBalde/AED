#include <stdio.h>
#include <stdlib.h>


int selectionsort(int*,int);

int main(void) {
    int *vetor, n, a, i, nt = 0;

    scanf("%d", &n);

    vetor = (int*)malloc(n*sizeof(int));

    for(i = 0 ; i < n ; i++) {
        scanf("%d",&a);
        vetor[i] = a;
    }

    for(i = 0 ; i < n ; i++) {
        printf("%d%s", vetor[i], i < n-1?" ":"\n");
    }

    nt = nt + selectionsort(vetor, n);

    for(i = 0 ; i < n ; i++) {
        printf("%d%s", vetor[i], i < n-1?" ":"\n");
    }

    printf("%d\n", nt);



    return 0;
}

int selectionsort(int* vetor, int n) {
    int aux,i,j,menor, troca = 0, k = 0;
    for(i = 0 ; i < n - 1; i++) {
        menor = i;
        for(j = i + 1 ; j < n ; j++) {
            if(vetor[j] < vetor[menor]) {
                menor = j;
                troca = troca + 1;
            }
        }

        if ( menor != i) {
            aux = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = aux;
        }
        for(k = 0 ; k < n ; k++) {
                printf("%d%s", vetor[k], k < n-1?" ":"\n");
            }
    }
        return troca;

}