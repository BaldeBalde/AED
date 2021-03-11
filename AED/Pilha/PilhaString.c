#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Pilha {
    int topo, tamanho;
    struct String *nome;
};

struct String {
    char string[40];
};

void criarPilha(struct Pilha*, int);
int vazia(struct Pilha);
int cheia(struct Pilha);
void empilhar(struct Pilha*, char*);
void desempilhar(struct Pilha*);
void exibirtopobase(struct Pilha);
void exibirbasetopo(struct Pilha);
void exibirtopo(struct Pilha);

int main(void) {
    int n, v;
    char command, a[40];
    struct Pilha P;

    scanf("%d", &n);

    criarPilha(&P, n);

    while( scanf("\n%c", &command) != EOF) {
        if (command == 'E') {
            scanf("%s", a);
            empilhar(&P, a);
        } else if (command == 'D') {
            v = vazia(P);
            if(!v) {
                desempilhar(&P);
            }
        } else if (command == 'T') {
            v = vazia(P);
            if(!v) {
                exibirtopo(P);
            }
        } else if (command == 'X') {
            exibirtopobase(P);
        } else if (command == 'B') {
            exibirbasetopo(P);
        }
    }


    return 0;
}

void criarPilha(struct Pilha* P, int n) {
    P->tamanho = n;
    P->topo = -1;
    P->nome = (struct String*)malloc(n*sizeof(struct String));
}

int vazia(struct Pilha P) {
    if (P.topo == -1) {
        return 1;
    } else {
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

void empilhar(struct Pilha* P, char *a) {
    int c;
    c = cheia(*P);
    if (!c) {
        P->topo = P->topo + 1;
        strcpy(P->nome[P->topo].string, a);
    }
}

void desempilhar(struct Pilha* P) {
    P->topo = P->topo - 1;
}

void exibirtopobase(struct Pilha P) {
    int i;
    for( i = P.topo; i >= 0 ; i--) {
        printf("%s%s", P.nome[i].string, (i>0?" ":"\n"));
    }
}

void exibirbasetopo(struct Pilha P) {
    int i;
    for( i = 0; i <= P.topo ; i++) {
        printf("%s%s", P.nome[i].string, (i < P.topo?" ":"\n"));
    }
}

void exibirtopo(struct Pilha P) {
    printf("%s\n", P.nome[P.topo].string);
}