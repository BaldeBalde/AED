#include <stdio.h>
#include <stdlib.h>

int bubblesortcrescente(int*,int);
int bubblesortdecrescente(int*,int);

int main(void) {
    int *vetor1,*vetor2, n, a, i, check;

    while(scanf("%d",&n) != EOF) {
        vetor1 = (int*)malloc(n*sizeof(int));
        vetor2 = (int*)malloc(n*sizeof(int));

        for(i = 0 ; i < n ; i++) {
            scanf("%d", &a);
            vetor1[i] = a;
            vetor2[i] = a;
        }
        if (n == 0) {
            printf("S\n");
        } else {
            check = bubblesortcrescente(vetor1, n);
            if(check) {
                printf("S\n");
            } else {
                check = bubblesortdecrescente(vetor2, n);
                if(check) {
                    printf("S\n");
                } else {
                    printf("N\n");
                }
            }
        }
    }


    return 0;
}


int bubblesortcrescente(int* vetor, int n) {
    int i, cont, aux, check = 1;
    for(cont = 1 ; cont < n ; cont++) {
        for(i = 0 ; i < n - 1 ; i++) {
            if(vetor[i] > vetor[i+1]) {
                aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
                check = 0;
            }
        }
    }
    return check;
}
int bubblesortdecrescente(int* vetor, int n) {
    int i, cont, aux, check = 1;
    for(cont = 1 ; cont < n ; cont++) {
        for(i = 0 ; i < n - 1 ; i++) {
            if(vetor[i] < vetor[i+1]) {
                aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
                check = 0;
            }
        }
    }
    return check;
}
