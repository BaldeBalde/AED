#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct Lista {
    float *info;
    int tamanho,quantidade;
};



void criarlista(struct Lista*, int);
void inserir(struct Lista*, float);
void mostrar(struct Lista);
void remover(struct Lista*, float);
int repetido(struct Lista*, float);


int main(void) {
    int n;
    float a;
    char command;
    struct Lista L;

    scanf("%d", &n);

    criarlista(&L, n);


    while( scanf("\n%c", &command) != EOF) {
        if ( command == 'I') {
            scanf("%f", &a);
            inserir(&L,a);
        } else if ( command == 'R') {
            scanf("%f", &a);
            remover(&L,a);
        } else if ( command == 'B') {
            scanf("%f", &a);
            printf("%s\n", repetido(&L,a)?"SIM":"NAO");
        } else if (command == 'M') {
            mostrar(L);
        }
    }


    return 0;
}

void criarlista(struct Lista *L, int n) {
    L->tamanho = n;
    L->quantidade = 0;
    L->info = (float*)malloc(n*sizeof(float));

}

void inserir(struct Lista *L, float a) {
    int i = 0, j, r;
    r = repetido( L,a);
    if ( L->quantidade != L->tamanho && r == 0) {
    while (i < L->quantidade && a > L->info[i]) {
        i++;
    }
    for ( j = L->quantidade ; j > i ; j-- ) {
        L->info[j] = L->info [j-1];
    }
    L->info[i] = a;
    L->quantidade = L->quantidade + 1;
    }
}

void mostrar(struct Lista L) {
    int i;
    for (i = 0; i < L.quantidade; i++) {
        if (L.info[i] == round(L.info[i]) ) {
            printf("%.0f%s", L.info[i], (i < L.quantidade - 1?" ":"\n"));
        } else {
            printf("%.1f%s", L.info[i], (i < L.quantidade - 1?" ":"\n"));
        }
    }
}

int repetido (struct Lista *L, float a) {
    int i;
    for (i = 0 ; i < L->quantidade; i ++) {
        if (L->info[i] == a) {
            return 1;
        }
    }
    return 0;
}

void remover(struct Lista *L, float a) {
    int i = 0, j;
    while(i < L->quantidade && L->info[i] != a) {
        i++;
    }

    if (L->info [i] == a) {
        for(j = i ; j < L->quantidade - 1 ; j ++) {
        L->info[j] = L->info[j+1];
        }
    L->quantidade = L->quantidade - 1;
    }
}