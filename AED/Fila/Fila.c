#include <stdio.h>
#include <stdlib.h>

struct Fila {
    int *info, inicio, fim, tamanho;
};

void criarfila(struct Fila*, int);
int vazia(struct Fila);
void entrar(struct Fila*, int);
int deletar(struct Fila*);
void esvaziar(struct Fila*);
void mostrar(struct Fila);
int cheia(struct Fila);

int main(void) {

    int n, a, v;
    char command;
    struct Fila F;
    scanf("%d", &n);

    criarfila(&F, n);

    while(scanf("\n%c", &command) != EOF) {
        if (command == 'E') {
            scanf("%d", &a);
            entrar(&F, a);
        } else if (command == 'D') {
            v = vazia(F);
            if (!v) {
                printf("%d\n", deletar(&F));
            } else {
                printf("Runtime Error: Fila Vazia.\n");
            }
        }
    }

    return 0;
}

void criarfila(struct Fila* F, int n) {
    F->tamanho = n;
    F->inicio = -1;
    F->fim = -1;
    F->info = (int*)malloc(n*sizeof(int));
}

int vazia(struct Fila F) {
    if ( F.inicio == -1 && F.fim == -1) {
        return 1;
    } else {
        return 0;
    }
}

void entrar(struct Fila* F, int info) {
    int i, c, v;
    c = cheia(*F);
    v = vazia(*F);
    if(!c) {
        if (v) {
            F->inicio = F->inicio + 1;
        }
            F->fim = F->fim + 1;
            F->info[F->fim] = info;
    } else {
        printf("Runtime Error: Fila Cheia.\n");
    }
}

int deletar(struct Fila* F) {
    int p;
        p = F->info[F->inicio];
        F->inicio = F->inicio + 1;
        if (F->inicio > F->fim) {
            esvaziar(F);
        }
        return p;
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
            printf("%d%s", F.info[i], (i < F.fim?" ":"\n"));
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