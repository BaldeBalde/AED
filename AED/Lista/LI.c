#include <stdio.h>
#include <stdlib.h>

struct Item {
    int info;
    struct Item* prox;
};

struct Lista {
    struct Item* inicio;
};

struct ListaOrd {
    int *info,tamanho,quantidade;
};

void criarLista(struct Lista*);
void criarListaOrd(struct ListaOrd*, int);
void inserir(struct Lista*,int);
void inserirOrd(struct ListaOrd*, int);
struct Item* remover(struct Lista*,int);
void mostrar(struct Lista*);
int repetido(struct Lista*,int);
void mergeList(struct Lista*, struct Lista*);
void ordenarcrescente(struct Lista*);
void esvaziarLista(struct Lista*);

int main(void) {
    int n1, n2, N, r, a, i, j1, j2;
    char command;
    struct Lista L1,L2;
    struct Item I;

    criarLista(&L1);
    criarLista(&L2);
    scanf("%d", &N);

    for(i = 0 ; i < N ; i++) {
        scanf("%d", &n1);
        if(n1 > 0) {
            for(j1 = 0 ; j1 < n1 ; j1++) {
                scanf("%d", &a);
                inserir(&L1,a);
            }
        }
        scanf("%d", &n2);
        if(n2 > 0) {
            for(j2 = 0 ; j2 < n2 ; j2++) {
                scanf("%d", &a);
                inserir(&L2,a);
            }
        }
        mergeList(&L1,&L2);
        ordenarcrescente(&L1);
        mostrar(&L1);
        //esvaziarLista(&L1);
        //esvaziarLista(&L2);
        criarLista(&L1);
        criarLista(&L2);
    }



    return 0;
}

void criarLista(struct Lista* L) {
    //L = (struct Lista*)malloc(sizeof(struct Lista));
    L->inicio = NULL;
}

void criarListaOrd(struct ListaOrd *L, int n) {
    L->tamanho = n;
    L->quantidade = 0;
    L->info = (int*)malloc(n*sizeof(int));

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

void inserirOrd(struct ListaOrd *L, int a) {
    int i = 0, j, r;
    if ( L->quantidade != L->tamanho) {
    while (i < L->quantidade && a > L->info[i]) {
        i++;
    }
    for ( j = L->quantidade ; j > i ; j-- ) {
        L->info[j] = L->info [j-1];
    }
    L->info[i] = a;
    L->quantidade = L->quantidade + 1;
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

void mergeList(struct Lista *L1, struct Lista *L2) {
    struct Item* aux = L1->inicio;

    if(L1->inicio != NULL) {
        while(aux->prox != NULL) {
            aux = aux->prox;
        }
    aux->prox = L2->inicio;
    } else {
        L1->inicio = L2->inicio;
    }
}

void ordenarcrescente(struct Lista* L) {
    struct Item *aux = L->inicio;
    struct ListaOrd LO;
    int c = 0,n;

    while(aux != NULL) {
        aux = aux->prox;
        c++;
    }

    criarListaOrd(&LO,c);
    aux = L->inicio;
    n = c;
    c = 0;

    while(c < n) {
        inserirOrd(&LO, aux->info);
        aux = aux->prox;
        c++;
    }

    aux = L->inicio;
    c = 0;

    while(c < n) {
        aux->info = LO.info[c];
        aux = aux->prox;
        c++;
    }
}

void esvaziarLista(struct Lista* L) {
    struct Item* aux = L->inicio, *aux2;
    if(L->inicio != NULL) {
        while( aux->prox != NULL) {
            aux2 = aux;
            aux = aux->prox;
            free(aux2);
        }

        L->inicio = NULL;
    }
}