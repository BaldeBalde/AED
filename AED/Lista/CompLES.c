#include <stdio.h>
#include <stdlib.h>

struct Lista {
    int *info, quantidade, tamanho;
};

void criarLista(struct Lista*, int);
void inserir(struct Lista*, int);
void eliminar(struct Lista*, int);
int comparar(struct Lista, struct Lista);
void mostrar(struct Lista);
int repetido(struct Lista, int);

int main(void) {
    int q, r, a, c = 0, soma;
    char command;
    struct Lista L1,L2;
    scanf("%d %d", &q, &r);

    criarLista(&L1, q);
    criarLista(&L2, r);

    soma = q+r;

    while( c < soma && scanf("\n%c", &command) != EOF) {
        if ( c < q) {
            if (command == 'I') {
                scanf("%d", &a);
                inserir(&L1, a);
            } else if (command == 'E') {
                scanf("%d", &a);
                eliminar(&L1, a);
            }
        } else {
            if (command == 'I') {
                scanf("%d", &a);
                inserir(&L2, a);
            } else if (command == 'E') {
                scanf("%d", &a);
                eliminar(&L2, a);
            }
        }
        c++;
    }



    printf("%s\n", comparar(L1,L2)?"SIM":"NAO");

    return 0;
}

void criarLista(struct Lista* L, int n) {
    L->tamanho = n;
    L->quantidade = 0;
    L->info = (int*)malloc(n*sizeof(int));
}
void inserir(struct Lista* L, int info) {
    int i = 0, j, r;
    r = repetido(*L, info);
    if (L->quantidade != L->tamanho && r ==0) {
        while ( i < L->quantidade && info > L->info[i] ) {
            i++;
        }

        for (j = L->quantidade; j > i ; j --) {
            L->info[j] = L->info[j-1];
        }
        L->info[i] = info;
        L->quantidade = L->quantidade + 1;
    }
}

void eliminar(struct Lista* L, int info){
    int i = 0, j;
    while( i < L->quantidade && L->info[i] != info) {
        i++;
    }

    if (L->info[i] == info) {
        for ( j = i; j < L->quantidade - 1; j++) {
            L->info[j] = L->info[j+1];
        }
        L->quantidade = L->quantidade - 1;
    }
}

void mostrar(struct Lista L) {
    int i;
    for( i = 0 ; i < L.quantidade ; i++) {
        printf("%d%s", L.info[i], (i < L.quantidade -1)?" ":"\n");
    }
}

int repetido(struct Lista L, int info) {
    int i;
    for (i = 0; i < L.quantidade ; i++) {
        if (L.info[i] == info) {
            return 1;
        }
    }
    return 0;
}

int comparar(struct Lista L1, struct Lista L2) {
    int i, j, c = 0;
    if (L1.quantidade > 0 && L2.quantidade > 0) {
        if (L1.tamanho < L2.tamanho) {
            for (i = 0; i < L1.quantidade ; i ++) {
                for (j = 0; j < L2.quantidade ; j ++) {
                    if(L1.info[i] == L2.info[j]) {
                        c++;
                    }
                }
            }
            if (c == L1.quantidade) {
                return 1;
            } else {
                return 0;
            }
        } else {
            for (i = 0; i < L2.quantidade ; i ++) {
                for (j = 0; j < L1.quantidade ; j ++) {
                    if(L2.info[i] == L1.info[j]) {
                        c++;
                    }
                }
            }
            if (c == L1.quantidade) {
                return 1;
            } else {
                return 0;
            }
        }
    }
}