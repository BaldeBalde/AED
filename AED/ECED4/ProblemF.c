#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int info;
    struct Node *esq,*dir;
};

typedef struct Node* ArvBin;

ArvBin* criarArvore();
void inserir(ArvBin*,int);
int ArvoreMax(struct Node*);

int main(void) {
    ArvBin* raiz = criarArvore();
    int a,n,i,max;

    scanf("%d",&n);

    for(i = 0 ; i < n ; i++) {
        scanf("%d",&a);
        inserir(raiz,a);
    }

    struct Node* atual = *raiz;
    max = ArvoreMax(atual);

    printf("%d\n", max);
    return 0;

}

ArvBin* criarArvore() {
    ArvBin* raiz = (ArvBin*)malloc(sizeof(ArvBin));
    if(raiz != NULL) {
        *raiz = NULL;
    }
    return raiz;
}

void inserir(ArvBin* raiz, int a) {
    if(raiz == NULL) {
        return;
    }
    struct Node* novo;
    novo = (struct Node*)malloc(sizeof(struct Node));
    if(novo == NULL) {
        return;
    }
    novo->info = a;
    novo->esq = NULL;
    novo->dir = NULL;

    if(*raiz == NULL) {
        *raiz = novo;
    } else {
        struct Node* atual = *raiz;
        struct Node* anterior = NULL;
        while(atual != NULL) {
            anterior = atual;
            if(a == atual->info) {
                free(novo);
                return;
            }
            if(a > atual->info) {
                atual = atual->dir;
            } else {
                atual = atual->esq;
            }
        }
        if(a > anterior->info) {
            anterior->dir = novo;
        } else {
            anterior->esq = novo;
        }
    }
}

int ArvoreMax(struct Node* no) {
    struct Node* atual = no;
    if(atual == NULL) {
        return 0;
    }

    int nodir = ArvoreMax(atual->dir);
    if(atual->dir == NULL) {
        return atual->info;
    }

    return nodir;
}
