#include <stdio.h>
#include <stdlib.h>

void bubblesort(int*,int);
float mediana(int*,int);

int main(void) {
    float med;
    int *vetor, n, a, i;

    scanf("%d", &n);

    vetor = (int*)malloc(n*sizeof(int));

    for(i = 0 ; i < n ; i++) {
        scanf("%d", &a);
        vetor[i] = a;
    }

    bubblesort(vetor,n);

    med = mediana(vetor,n);
    printf("%.2f\n", med);

    return 0;
}

void bubblesort(int* vetor, int n) {
    int aux, i, j;

    for(i = 1 ; i < n ; i++) {
        for(j = 0 ; j < n - 1 ; j++) {
            if(vetor[j] > vetor[j+1]) {
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
}

float mediana(int* vetor, int n) {
    float m;
    int p;
    if(n%2 != 0) {
        p = (n-1)/2;
        m = vetor[p];
    } else {
        p = n/2 - 1;
        m = m + vetor[p];
        p = n/2;
        m = m + vetor[p];
        m = m/2;
    }
        return m;
}