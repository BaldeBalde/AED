#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *vetor, n, a, i, aux, j, c;

    scanf("%d", &n);

    vetor = (int*)malloc(n*sizeof(int));

    for(i = 0 ; i < n ; i++) {
        scanf("%d", &a);
        vetor[i] = a;
    }



    for(j = n - 1 ; j > 0 ; j--) {
        if(vetor[j] < vetor[j-1]) {
            aux = vetor[j];
            vetor[j] = vetor[j-1];
            for( i = 0 ; i < n ; i++) {
                printf("%d%s", vetor[i], i < n-1?" ":"\n");
            }
            vetor[j-1] = aux;
        }
    }

    for( i = 0 ; i < n ; i++) {
        printf("%d%s", vetor[i], i < n-1?" ":"\n");
    }


    return 0;
}