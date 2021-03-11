#include <stdio.h>
#include <stdlib.h>

struct Item {
    int info;
    struct Item* prox;
};

struct Lista {
    struct Item* inicio;
};


void criarLista(struct Lista*);
void inserir(struct Lista*,int);
struct Item* remover(struct Lista*,int);
void mostrar(struct Lista*);
void mostrarReverso(struct Lista*);
int repetido(struct Lista*,int);

int main(void) {
    int n, N, a, i, j;
    struct Lista L;
    struct Item I;

    criarLista(&L);
    scanf("%d", &N);

    for(i = 0 ; i < N ; i++) {
            scanf("%d", &n);
            if(n > 0) {
                for(j = 0 ; j < n ; j++) {
                    scanf("%d", &a);
                    inserir(&L,a);
                }
            mostrarReverso(&L);
        }
    }



    return 0;
}

void criarLista(struct Lista* L) {
    //L = (struct Lista*)malloc(sizeof(struct Lista));
    L->inicio = NULL;
}


void inserir(struct Lista* L, int a) {
    int r;
    struct Item *novo,*anterior,*atual;
    novo =(struct Item*)malloc(sizeof(struct Item));
    novo->info = a;
    novo->prox = NULL;
    anterior = NULL;
    atual = L->inicio;
    r = repetido(L,a);
    if(!r) {
        while(atual != NULL) {
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

struct Item* remover(struct Lista* L, int a) {
    struct Item *anterior,*atual, *aux;
    anterior = NULL;
    atual = L->inicio;

    if(L->inicio != NULL) {
        while(atual->prox != NULL && atual->info != a) {
            anterior = atual;
            atual = atual->prox;
        }

        if(atual->info == a) {
            aux = atual;
            if(anterior == NULL) {
                L->inicio = atual->prox;
            } else {
                atual = atual->prox;
                anterior->prox = atual;
            }
            return aux;
        }
    }
        return NULL;
}

void mostrar(struct Lista* L){
    struct Item *aux = L->inicio;

    while(aux != NULL) {
        printf("%d%s", aux->info, aux->prox != NULL?" ":"\n");
        aux = aux->prox;
    }
}

void mostrarReverso(struct Lista *L) {
    struct Item *anterior, *atual;
    while(L->inicio != NULL) {
        anterior = NULL;
        atual = L->inicio;
         while(atual->prox != NULL) {
            anterior = atual;
            atual = atual->prox;
        }

        printf("%d\n", atual->info);
            if(anterior == NULL) {
                L->inicio = atual->prox;
            } else {
                atual = atual->prox;
                anterior->prox = atual;
            }
        }
    }

int repetido(struct Lista *L, int a) {
    struct Item *aux = L->inicio;
    while(aux != NULL) {
        if(aux->info == a) {
            return 1;
        } else {
            aux = aux->prox;
        }
    }
    return 0;
}


