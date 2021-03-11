#include <stdio.h>
#include <stdlib.h>

struct Circular {
    int *info, inicio, fim, tamanho;
};

void criarCircular(struct Circular*, int);
void enfileirar(struct Circular*,int);
void desenfileirar(struct Circular*);
void mostrar(struct Circular);

int main(void) {
    int n, a, d;
    char command;
    struct Circular C;

    scanf("%d", &n);
    criarCircular(&C,n);

    while(scanf("\n%c", &command) != EOF) {
        if (command == 'E') {
            scanf("%d", &a);
            enfileirar(&C,a);
        } else if (command == 'D') {
            desenfileirar(&C);
        }
    }
    return 0;
}

void criarCircular(struct Circular* C, int n) {
    C->info = (int*)malloc(n*sizeof(int));
    C->inicio = 0;
    C->fim = 0;
    C->tamanho = n;
}

void enfileirar(struct Circular* C,int a) {
    if((C->fim + 1)%C->tamanho != C->inicio) {
        C->info[C->fim] = a;
        C->fim = (C->fim + 1)%C->tamanho;
    }
}

void desenfileirar(struct Circular* C) {
    if(C->inicio != C->fim) {
        printf("%d\n", C->info[C->inicio]);
        C->inicio = (C->inicio + 1)%C->tamanho;
    }
}

void mostrar(struct Circular C) {
    int i;
    for( i = C.inicio; i < C.fim ; i++) {
        printf("%d%s", C.info[i], i < C.fim - 1?" ":"\n");
    }
}