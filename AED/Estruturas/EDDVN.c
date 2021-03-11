#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct ItemLista {
    int info;
    struct ItemLista* prox;
};

struct Lista {
    struct ItemLista* inicio;
};

struct ItemFila {
    int info;
    struct ItemFila *prox;
};

struct Fila {
    struct ItemFila *inicio, *fim;
};

struct ItemPilha {
    int info;
    struct ItemPilha *prox, *ant;
};

struct Pilha {
    struct ItemPilha *topo, *base;
};

int designar(int*,int);
void criarLista(struct Lista*);
void inserir(struct Lista*,int);
void remover(struct Lista*,int);
void mostrarLista(struct Lista*);
int repetido(struct Lista*,int);
void criarFila(struct Fila*);
void enfileirar(struct Fila*, int);
void desenfileirar(struct Fila*);
void mostrarFila(struct Fila*);
void criarPilha(struct Pilha*);
void empilhar(struct Pilha*, int);
void desempilhar(struct Pilha*);
void mostrarPilha(struct Pilha*);





int main(void) {
    int N,a,*y,i,j, action;
    char lista[4]="LDE", command,fila[5]="FILA",pilha[6]="PILHA", s[6];
    struct Lista L;
    struct Fila F;
    struct Pilha P;

    scanf("%d", &N);
    y = (int*)malloc(N*sizeof(int));


    for(i = 0 ; i < N ; i++) {
        scanf("%s", s);
        if(!strcmp(lista,s)) {
            y[i] = 10;
            criarLista(&L);
        } else if (!strcmp(fila,s)) {
            y[i] = 20;
            criarFila(&F);
        } else if (!strcmp(pilha,s)) {
            y[i] = 30;
            criarPilha(&P);
        }
    }

    while(N > 0 && scanf("%d", &action) != EOF) {
        scanf("\n%c", &command);
        j = designar(y,action);
        if (j == 10) {
            if (command == 'I') {
                scanf("%d", &a);
                if (a > 0) {
                    inserir(&L,a);
                }
            } else if (command == 'R') {
                scanf("%d", &a);
                remover(&L,a);
                printf("\n");
            } else if (command == 'M') {
                mostrarLista(&L);
                printf("\n");
            }
        } else if (j == 20) {
            if (command == 'I') {
                scanf("%d", &a);
                if (a > 0) {
                    enfileirar(&F,a);
                }
            } else if (command == 'R') {
                desenfileirar(&F);
                printf("\n");
            } else if (command == 'M') {
                mostrarFila(&F);
                printf("\n");
            }
        } else if (j == 30) {
            if (command == 'I') {
                scanf("%d", &a);
                if (a > 0) {
                    empilhar(&P,a);
                }
            } else if (command == 'R') {
                desempilhar(&P);
                printf("\n");
            } else if (command == 'M') {
                mostrarPilha(&P);
                printf("\n");
            }
        }
    }




    return 0;
}




int designar(int* y, int a) {
    return y[a];
}

void criarLista(struct Lista* L) {
    L->inicio = NULL;
}


void inserir(struct Lista* L, int a) {
    int r;
    struct ItemLista *novo,*anterior,*atual;
    novo =(struct ItemLista*)malloc(sizeof(struct ItemLista));
    novo->info = a;
    novo->prox = NULL;
    anterior = NULL;
    atual = L->inicio;
    r = repetido(L,a);
    if(!r) {
        while(atual != NULL && atual->info < a) {
            anterior = atual;
            atual = atual->prox;
        }

        if(anterior == NULL) {
            L->inicio = novo;
        } else {
            anterior->prox = novo;
        }
        novo->prox = atual;
    }
}

void remover(struct Lista* L, int a) {
    struct ItemLista *anterior, *atual;
    anterior = NULL;
    atual = L->inicio;

    if(L->inicio != NULL) {
        while(atual->prox != NULL && atual->info != a) {
            anterior = atual;
            atual = atual->prox;
        }

        if(atual->info == a) {
            printf("REMOVIDO: %d", atual->info);
            if(anterior == NULL) {
                L->inicio = atual->prox;
            } else {
                atual = atual->prox;
                anterior->prox = atual;
            }
        }
    }
}
void mostrarLista(struct Lista* L){
    struct ItemLista *aux = L->inicio;

    while(aux != NULL) {
        printf("%d%s", aux->info, aux->prox != NULL?" ":"");
        aux = aux->prox;
    }
}

int repetido(struct Lista *L, int a) {
    struct ItemLista *aux = L->inicio;
    while(aux != NULL) {
        if(aux->info == a) {
            return 1;
        } else {
            aux = aux->prox;
        }
    }
    return 0;
}

void criarFila(struct Fila* F) {
    F->inicio = NULL;
    F->fim = NULL;
}

void enfileirar(struct Fila* F, int a) {
    struct ItemFila* novo;
    novo = (struct ItemFila*)malloc(sizeof(struct ItemFila));
    novo->info = a;
    novo->prox = NULL;

    if(F->inicio == NULL) {
        F->inicio = novo;
    } else {
        struct ItemFila *aux = F->inicio;
        while(aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    F->fim = novo;
}

void desenfileirar(struct Fila* F) {
    struct ItemFila *aux = F->inicio;
        if ( F->inicio != NULL && F->fim != NULL) {
            printf("REMOVIDO: %d", aux->info);
            F->inicio = aux->prox;
        } else if (F->inicio != NULL && F->inicio == F->fim) {
            printf("REMOVIDO: %d", aux->info);
            F->inicio = NULL;
            F->fim = NULL;
        }
}

void mostrarFila(struct Fila* F) {
    struct ItemFila *aux = F->inicio, *aux2 = F->fim;
    while(aux != NULL) {
        printf("%d%s", aux->info, aux != F->fim?" ":"");
        aux = aux->prox;
    }
}

void criarPilha(struct Pilha *P) {
    P->topo = NULL;
    P->base = NULL;
}

void empilhar(struct Pilha* P, int a) {
    struct ItemPilha *novo, *aux = P->topo;
    novo = (struct ItemPilha*)malloc(sizeof(struct ItemPilha));
    novo->info = a;
    novo->prox = NULL;
    novo->ant = NULL;

    if(P->topo != NULL) {
        novo->prox = P->topo;
        aux->ant = novo;
    }

    P->topo = novo;
    aux = P->topo;

    while(aux->prox != NULL) {
        aux = aux->prox;
    }
    P->base = aux;

}

void desempilhar(struct Pilha* P) {
    struct ItemPilha* aux = P->topo;

    if (P->topo == P->base) {
        if (P->topo != NULL) {
            printf("REMOVIDO: %d", aux->info);
        }
        P->topo = NULL;
        P->base = NULL;
    } else if (P->topo != NULL) {
        printf("REMOVIDO: %d", aux->info);
        aux = aux->prox;
        aux->ant = NULL;
        P->topo = aux;
    }
}

void mostrarPilha(struct Pilha* P) {
    struct ItemPilha *aux = P->base;
    while(aux != NULL) {
        printf("%d%s", aux->info, aux->ant != NULL?" ":"");
        aux = aux->ant;
    }
}