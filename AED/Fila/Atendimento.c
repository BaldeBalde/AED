#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct String {
    char string[20];
};

struct Fila {
    int *info, inicio, fim, tamanho;
    struct String *nome;
};

struct FilaSt {
    int info;
    char nome[20];
};

void criarfila(struct Fila*, int);
int vazia(struct Fila);
void incluir(struct Fila*, int, char*);
struct FilaSt deletar(struct Fila*);
void esvaziar(struct Fila*);
void mostrar(struct Fila);
void mostrarR(struct Fila);
int cheia(struct Fila);
int quantidade(struct Fila);

int main(void) {

    int n, RA, v;
    char command, name[20];
    struct Fila F;
    struct FilaSt R;
    scanf("%d", &n);

    criarfila(&F, n);

    while(scanf("\n%c", &command) != EOF) {
        if ( command == 'I') {
            scanf("%d %s", &RA, name);
            incluir(&F, RA, name);
        } else if( command == 'M' ) {
            mostrar(F);
        } else if( command == 'R' ) {
            mostrarR(F);
        } else if ( command == 'A' ) {
            v = vazia(F);
            if (!v) {
                R = deletar(&F);
                printf("[%d] %s\n", R.info, R.nome);
            }
        } else if ( command == 'Q' ) {
            printf("Quantidade: %d\n", quantidade(F));
        }
    }

    return 0;
}

void criarfila(struct Fila* F, int n) {
    F->tamanho = n;
    F->inicio = -1;
    F->fim = -1;
    F->info = (int*)malloc(n*sizeof(int));
    F->nome = (struct String*)malloc(n*sizeof(struct String));
}

int vazia(struct Fila F) {
    if ( F.inicio == -1 && F.fim == -1) {
        return 1;
    } else {
        return 0;
    }
}

void incluir(struct Fila* F, int info, char *a) {
    int i, c, v;
    c = cheia(*F);
    v = vazia(*F);
    if(!c) {
        if (v) {
            F->inicio = F->inicio + 1;
        }
            F->fim = F->fim + 1;
            F->info[F->fim] = info;
            strcpy(F->nome[F->fim].string, a);
    }
}

struct FilaSt deletar(struct Fila* F) {
    struct FilaSt R;
        R.info = F->info[F->inicio];
        strcpy(R.nome, F->nome[F->inicio].string);
        F->inicio = F->inicio + 1;
        if (F->inicio > F->fim) {
            esvaziar(F);
        }
        return R;
    }


void esvaziar(struct Fila* F) {
    F->inicio = -1;
    F->fim = -1;
}

void mostrar(struct Fila F) {
    int i, v;
    v = vazia(F);
    if (!v) {
        for(i = F.inicio ; i <= F.fim ; i ++) {
            printf("[%d] %s\n", F.info[i], F.nome[i].string);
        }
    }
}

void mostrarR(struct Fila F) {
    int i, v;
    v = vazia(F);
    if (!v) {
        for(i = F.fim ; i >= F.inicio ; i --) {
            printf("[%d] %s\n", F.info[i], F.nome[i].string);
        }
    }
}

int cheia(struct Fila F) {
    if (F.fim == F.tamanho - 1) {
        return 1;
    } else {
        return 0;
    }
}

int quantidade(struct Fila F) {
    int q = 1, v = vazia(F);
    if (v) {
        q = 0;
    } else {
        q =  q + (F.fim - F.inicio);
    }
    return q;
}