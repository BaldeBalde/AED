#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int info,nivel;
    struct Node *esq,*dir;
};

typedef struct Node* ArvBin;

ArvBin* criarArvore();
void inserir(ArvBin*,int);
void imprimirnivel(struct Node*,int);
int altura(ArvBin*);

int main(void) {
    ArvBin* raiz = criarArvore();
    int a,n,i,alt,j;

    scanf("%d",&n);

    for(i = 0 ; i < n ; i++) {
        scanf("%d",&a);
        inserir(raiz,a);
    }

    alt = altura(raiz);
    struct Node* atual = *raiz;

    for(j = 0 ; j < alt ; j++) {
        imprimirnivel(atual,j);
    }

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
    int nivel = 0;
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
         novo->nivel = nivel;
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
                nivel = nivel + 1;
            } else {
                atual = atual->esq;
                nivel = nivel + 1;
            }
        }
        novo->nivel = nivel;
        if(a > anterior->info) {
            anterior->dir = novo;
        } else {
            anterior->esq = novo;
        }
            novo->nivel = nivel;
    }
}

void imprimirnivel(struct Node* no,int niv) {
    int nivel;
    struct Node* atual = no;
    if(atual == NULL) {
        return;
    }
    imprimirnivel(atual->esq,niv);
    imprimirnivel(atual->dir,niv);
    if(atual->nivel == niv) {
        printf("%d\n",atual->info);
    }
    return;
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