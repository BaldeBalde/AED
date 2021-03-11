#include <stdio.h>
#include <stdlib.h>

struct Item {
    int info;
    struct Item* prox, *ant;
};

struct Lista {
    struct Item* inicio, *final;
};

void criarLista(struct Lista*);
void inserir(struct Lista*,int);
void remover(struct Lista*,int);
void mostrar(struct Lista*);
void mostrarReverso(struct Lista*);
int repetido(struct Lista*,int);

int main(void) {
    int r, a;
    char command;
    struct Lista L;
    struct Item I, *R;

    criarLista(&L);

    while(scanf("\n%c",&command) != EOF) {
        if (command == 'I') {
            scanf("%d",&a);
            inserir(&L,a);
        } else if (command == 'E') {
            scanf("%d",&a);
            remover(&L,a);
        } else if (command == 'M') {
            mostrar(&L);
        } else if (command == 'R') {
            mostrarReverso(&L);
        }
    }


    return 0;
}

void criarLista(struct Lista* L) {
    //L = (struct Lista*)malloc(sizeof(struct Lista));
    L->inicio = NULL;
    L->final = NULL;
}


void inserir(struct Lista* L, int a) {
    int r;
    struct Item *novo,*anterior,*atual, *aux;
    novo =(struct Item*)malloc(sizeof(struct Item));
    novo->info = a;
    novo->prox = NULL;
    novo->ant = NULL;
    anterior = NULL;
    atual = L->inicio;
    r = repetido(L,a);
    if(!r) {
        while(atual != NULL && atual->info < a) {
            anterior = atual;
            atual = atual->prox;
        }

        if(anterior == NULL && atual == NULL) {
            L->inicio = novo;
        } else if(anterior == NULL && atual != NULL) {
            L->inicio = novo;
            atual->ant = novo;
        } else if (anterior != NULL && atual != NULL) {
            anterior->prox = novo;
            atual->ant = novo;
        } else if (anterior != NULL && atual == NULL) {
            anterior->prox = novo;
        }
        novo->ant = anterior;
        novo->prox = atual;
    }
    aux = L->inicio;
    while(aux->prox != NULL) {
        aux = aux->prox;
    }
    L->final = aux;
}

void remover(struct Lista* L, int a) {
    struct Item *anterior,*atual, *aux, *aux2;
    anterior = NULL;
    atual = L->inicio;

    if(L->inicio != NULL) {
        while(atual->prox != NULL && atual->info != a) {
            anterior = atual;
            atual = atual->prox;
        }

        if(atual->info == a) {
            if (L->inicio == L->final) {
                L->inicio = NULL;
                L->final = NULL;
            } else if(anterior == NULL && atual != NULL) {
                L->inicio = atual->prox;
                aux = L->inicio;
                aux->ant = NULL;
            } else if (anterior != NULL && atual != NULL)  {
                atual = atual->prox;
                anterior->prox = atual;
                if(atual != NULL) {
                    atual->ant = anterior;
                }
                aux2 = L->inicio;
            while(aux2->prox != NULL) {
                aux2 = aux2->prox;
            }
            L->final = aux2;
            }
        }
    }
}

void mostrar(struct Lista* L){
    struct Item *aux = L->inicio;

    while(aux != NULL) {
        printf("%d ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}

void mostrarReverso(struct Lista* L) {
    struct Item *aux = L->final;

    while( aux != NULL) {
        printf("%d ", aux->info);
        aux = aux->ant;
    }
    printf("\n");
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