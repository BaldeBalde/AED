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
int repetido(struct Lista*,int);

int main(void) {
    int r, a;
    char command;
    struct Lista L;
    struct Item I, *R;

    criarLista(&L);

    while( scanf("\n%c",&command) != EOF) {
        if (command == 'I') {
            scanf("%d",&a);
            inserir(&L,a);
        } else if (command == 'R') {
            scanf("%d",&a);
            R = remover(&L,a);
            if(R != NULL) {
                free(R);
            }
        } else if (command == 'B') {
            scanf("%d",&a);
            r = repetido(&L,a);
            printf("%s\n", r?"SIM":"NAO");
        } else if (command == 'L') {
            mostrar(&L);
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