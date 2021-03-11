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
int altura(ArvBin*);
void preordem(ArvBin*);
void emordem(ArvBin*);
void posordem(ArvBin*);

int main(void) {
    ArvBin* raiz = criarArvore();
    int a,alt,n,i;
    char command[15];

    scanf("%d",&n);

    for(i = 0 ; i < n ; i++) {
        scanf("%d",&a);
        inserir(raiz,a);
    }

    alt = altura(raiz);
    alt = alt - 1;

    printf("%d\n",alt);

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
            if(a == atual->info || a > atual->info) {
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

int altura(ArvBin* raiz) {
    if(raiz == NULL) {
        return 0;
    } else if (*raiz == NULL) {
        return 0;
    }
    int altesq = altura(&((*raiz)->esq));
    int altdir = altura(&((*raiz)->dir));
    if(altesq > altdir) {
        return (altesq + 1);
    } else {
        return (altdir + 1);
    }
}

void preordem(ArvBin* raiz) {
    if(raiz == NULL) {
        return;
    } else if(*raiz != NULL) {
        printf("%d ",(*raiz)->info);
        preordem(&((*raiz)->esq));
        preordem(&((*raiz)->dir));
    }
}

void emordem(ArvBin* raiz) {
    if(raiz == NULL) {
        return;
    } else if(*raiz != NULL) {
        emordem(&((*raiz)->esq));
        printf("%d ",(*raiz)->info);
        emordem(&((*raiz)->dir));
    }
}

void posordem(ArvBin* raiz) {
    if (raiz == NULL) {
        return;
    } else if (*raiz != NULL) {
        posordem(&((*raiz)->esq));
        posordem(&((*raiz)->dir));
        printf("%d ",(*raiz)->info);
    }
}