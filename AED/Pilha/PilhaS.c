#include <stdio.h>
#include <stdlib.h>

struct Pilha {
    int *info, topo, tamanho;
};

void criarPilha(struct Pilha*, int);
int vazia(struct Pilha);
int cheia(struct Pilha);
void empilhar(struct Pilha*, int);
void desempilhar(struct Pilha*);
void exibirtopobase(struct Pilha);
void exibirbasetopo(struct Pilha);

int main(void) {
    int n, a, v;
    char command;
    struct Pilha P;

    scanf("%d", &n);

    criarPilha(&P, n);

    while( scanf("\n%c", &command) != EOF) {
        if (command == 'E') {
            scanf("%d", &a);
            empilhar(&P, a);
        } else if ( command == 'D') {
            v = vazia(P);
            if (!v) {
                desempilhar(&P);
            } else {
                printf("Runtime Error: Pilha Vazia.\n");
            }
        } else if ( command == 'T') {
            v = vazia(P);
            if (!v) {
                exibirtopobase(P);
            } else {
                printf("Runtime Error: Pilha Vazia.\n");
            }
        } else if ( command == 'B') {
            v = vazia(P);
            if (!v) {
            exibirbasetopo(P);
            } else {
                printf("Runtime Error: Pilha Vazia.\n");
            }
        }
    }

    return 0;
}

void criarPilha(struct Pilha* P, int n) {
    P->tamanho = n;
    P->topo = -1;
    P->info = (int*)malloc(n*sizeof(int));
}

int vazia(struct Pilha P) {
    if (P.topo == -1) {
        return 1;
    }  else {
        return 0;
    }
}

int cheia(struct Pilha P) {
    if (P.topo == P.tamanho - 1) {
        return 1;
    } else {
        return 0;
    }
}


void empilhar(struct Pilha* P, int info) {
    int c;
    c = cheia(*P);
    if (!c) {
        P->topo = P->topo + 1;
        P->info[P->topo] = info;
    } else {
        printf("Runtime Error: Pilha Cheia.\n");
    }
}


void desempilhar(struct Pilha* P) {
    P->topo = P->topo - 1;
}

void exibirtopobase(struct Pilha P) {
    int i;
    for (i = P.topo ; i >= 0 ; i-- ) {
        printf("%d\n", P.info[i]);
    }
}

void exibirbasetopo(struct Pilha P) {
    int i;
    for (i = 0 ; i <= P.topo ; i++ ) {
        printf("%d\n", P.info[i]);
    }
}