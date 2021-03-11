#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Lista {
    int *info, quantidade, tamanho;
};

struct Pilha {
    int *info, topo, tamanho;
};

struct Fila {
    int *info, inicio, fim, tamanho;
};

struct Circular {
    int *info, inicio, fim, tamanho, quantidade;
};

int designar(int*, int);
void criarLista(struct Lista*, int);
void criarPilha(struct Pilha*,int);
void criarFila(struct Fila*,int);
void criarCircular(struct Circular*, int);
void inserir(struct Lista*,int);
void empilhar(struct Pilha*,int);
void enfileirar(struct Fila*,int);
void enfileirarCircular(struct Circular*,int);
void remover(struct Lista*,int);
void desempilhar(struct Pilha*);
void desenfileirar(struct Fila*);
void desenfileirarCircular(struct Circular*);
void mostrarLista(struct Lista);
void mostrarPilha(struct Pilha);
void mostrarFila(struct Fila);
void mostrarCircular(struct Circular);
void esvaziarFila(struct Fila*);
void esvaziarCircular(struct Circular*);
int repetidoLista(struct Lista,int);

int main(void) {
    int n, a, N, i = 0, *Y, action, j;
    struct Lista L;
    struct Pilha P;
    struct Fila F;
    struct Circular C;
    char ED[9],command, lista[4] = "LES\0", fila[5] = "FILA\0", pilha[6] = "PILHA\0", circular[9] = "CIRCULAR\0";

    scanf("%d\n", &N);

    Y = (int*)malloc(N*sizeof(int));

    while( i < N ) {
        scanf("%s", ED);
        if(!strcmp(lista,ED)) {
            scanf("%d",&n);
            Y[i] = 10;
            criarLista(&L,n);
        } else if (!strcmp(fila,ED)) {
            scanf("%d",&n);
            Y[i] = 20;
            criarFila(&F,n);
        } else if (!strcmp(pilha,ED)) {
            scanf("%d",&n);
            Y[i] = 30;
            criarPilha(&P,n);
        } else if (!strcmp(circular,ED)) {
            scanf("%d",&n);
            Y[i] = 40;
            criarCircular(&C,n);
        }
        i++;
    }




    while(scanf("%d",&action)!= EOF) {
        scanf("\n%c", &command);
        j = designar(Y, action);
            if(j == 10) {
                    if(command == 'I') {
                        scanf("%d", &a);
                        inserir(&L,a);
                    } else if (command == 'R') {
                        scanf("%d", &a);
                        remover(&L,a);
                    } else if (command == 'M') {
                        mostrarLista(L);
                    }
            } else if (j == 20) {
                if(command == 'I') {
                    scanf("%d", &a);
                    enfileirar(&F,a);
                    } else if (command == 'R') {
                    desenfileirar(&F);
                    } else if (command == 'M') {
                    mostrarFila(F);
                    }
            } else if (j == 30) {
                if(command == 'I') {
                    scanf("%d", &a);
                    empilhar(&P,a);
                    } else if (command == 'R') {
                    desempilhar(&P);
                    } else if (command == 'M') {
                    mostrarPilha(P);
                    }
            } else if (j == 40) {
                if(command == 'I') {
                    scanf("%d", &a);
                    enfileirarCircular(&C,a);
                    } else if (command == 'R') {
                    desenfileirarCircular(&C);
                    } else if (command == 'M') {
                    mostrarCircular(C);
                    }
            }
        }


    return 0;
}

int designar(int* Y, int a) {
    return Y[a];
}

void criarLista(struct Lista* L, int n) {
    L->info =(int*)malloc(n*sizeof(int));
    L->quantidade = 0;
    L->tamanho = n;
}
void criarPilha(struct Pilha* P,int n) {
    P->info = (int*)malloc(n*sizeof(int));
    P->topo = -1;
    P->tamanho = n;
}

void criarFila(struct Fila* F,int n) {
    F->info = (int*)malloc(n*sizeof(int));
    F->inicio = -1;
    F->fim = -1;
    F->tamanho = n;
}

void criarCircular(struct Circular *C, int n) {
    C->info = (int*)malloc(n*sizeof(int));
    C->inicio = 0;
    C->fim = 0;
    C->tamanho = n;
    C->quantidade = 0;
}

void inserir(struct Lista* L,int a) {
    int i = 0, j, r;
    r = repetidoLista(*L,a);
    if(L->quantidade!= L->tamanho && r == 0) {
        while( i < L->quantidade && L->info[i] < a) {
            i++;
        }

        for( j = L->quantidade; j > i ; j--) {
            L->info[j] = L->info[j-1];
        }
        L->info[i] = a;
        L->quantidade = L->quantidade + 1;
    }
}

void empilhar(struct Pilha* P,int a) {
    if (P->topo < P->tamanho - 1){
        P->topo = P->topo + 1;
        P->info[P->topo] = a;
    }
}

void enfileirar(struct Fila* F,int a) {
    if (F->fim != F->tamanho - 1) {
        if (F->inicio == -1) {
            F->inicio = F->inicio + 1;
        }
        F->fim = F->fim + 1;
        F->info[F->fim] = a;
    }
}

void enfileirarCircular(struct Circular* C, int a) {
    if( (C->fim + 1)%C->tamanho != C->inicio) {
            C->info[C->fim] = a;
            C->fim = (C->fim + 1)%C->tamanho;
            C->quantidade = C->quantidade + 1;
        }
    }

void remover(struct Lista* L,int a) {
    int i = 0, j;
    if(L->quantidade != 0) {
        while( i < L->quantidade && L->info[i] != a) {
            i++;
        }

        if(L->info[i] == a) {
            printf("REMOVIDO: %d\n", L->info[i]);
            for( j = i; j < L->quantidade - 1 ; j++) {
                L->info[j] = L->info[j+1];
            }
            L->quantidade = L->quantidade - 1;
        }
    }
}

void desempilhar(struct Pilha* P) {
    if (P->topo != -1) {
        printf("REMOVIDO: %d\n", P->info[P->topo]);
        P->topo = P->topo - 1;
    }
}

void desenfileirar(struct Fila* F) {
    if(F->inicio != -1) {
        printf("REMOVIDO: %d\n", F->info[F->inicio]);
        F->inicio = F->inicio + 1;
    }
    esvaziarFila(F);
}

void desenfileirarCircular(struct Circular* C) {
     if(C->inicio != C->fim) {
        printf("REMOVIDO: %d\n", C->info[C->inicio]);
        C->inicio = (C->inicio + 1)%C->tamanho;
        C->quantidade = C->quantidade - 1;
        esvaziarCircular(C);
    }
}

void mostrarLista(struct Lista L) {
    int i;
    for(i = 0; i < L.quantidade ; i++) {
        printf("%d%s",L.info[i], i < L.quantidade - 1?" ":"\n");
    }
}

void mostrarPilha(struct Pilha P) {
    int i;
    for (i = 0; i <= P.topo ; i++) {
        printf("%d%s", P.info[i], i < P.topo?" ":"\n");
    }
}

void mostrarFila(struct Fila F) {
    int i;
    if (F.inicio != -1) {
        for(i = F.inicio; i <= F.fim ; i++) {
            printf("%d%s", F.info[i], i < F.fim?" ":"\n");
        }
    }
}

void mostrarCircular(struct Circular C) {
    int cont, i, j;
    if (C.inicio < C.fim) {
        for(i = C.inicio ; i < C.fim ; i++) {
            printf("%d%s", C.info[i], i < C.fim - 1?" ":"\n");
        }
    } else if ( C.inicio > C.fim) {
        for(cont = 0,j = C.inicio ; cont < C.quantidade ; cont++) {
            if ( j == C.quantidade) {
                printf("%d%s", C.info[j], cont < C.quantidade - 1?" ":"\n");
                j = 0;
                while( j == C.fim) {
                    j++;
                }
            } else {
                printf("%d%s", C.info[j], cont < C.quantidade - 1?" ":"\n");
                j++;
            }
        }
    }
}

void esvaziarFila(struct Fila *F) {
    if(F->inicio > F->fim) {
        F->inicio = -1;
        F->fim = -1;
    }
}

void esvaziarCircular(struct Circular *C) {
    if (C->inicio == C->fim) {
        C->inicio = 0;
        C->fim = 0;
        C->quantidade = 0;
    }
}


int repetidoLista(struct Lista L, int a) {
    int i;
    for(i = 0 ; i < L.quantidade ; i++) {
        if(L.info[i] == a) {
            return 1;
        }
    }
    return 0;
}

