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
int quantnos(ArvBin*);
int quantnosrecursivo(struct Node*);

int main(void) {
    ArvBin* raiz = criarArvore();
    int a,n,i,quant = 0;

    scanf("%d",&n);

    for(i = 0 ; i < n ; i++) {
        scanf("%d",&a);
        inserir(raiz,a);
    }

    struct Node* atual = *raiz;
    quant = quantnosrecursivo(atual);

    printf("%d\n", quant);
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



int quantnos(ArvBin* raiz) {
    if(raiz == NULL) {
        return 0;
    }
    int cont = 0;
    struct Node* atual = *raiz;
    struct Node* direitaD;
    struct Node* direitaE;
    struct Node *esquerdaD;
    struct Node *esquerdaE;
    direitaD = atual->dir;
    direitaE = atual->dir;
    esquerdaD = atual->esq;
    esquerdaE = atual->esq;

    while(direitaD != NULL) {
        if(direitaD->esq == NULL && direitaD->dir == NULL) {
            cont = cont + 1;
        }
            if(direitaD->dir == NULL && direitaD->esq != NULL) {
                direitaD = direitaD->esq;
            } else {
                direitaD = direitaD->dir;
            }
    }

    while(direitaE != NULL) {
        if(direitaE->esq == NULL && direitaE->dir == NULL) {
            cont = cont + 1;
        }
            direitaE = direitaE->esq;
    }

    while(esquerdaD != NULL) {
        if(esquerdaD->esq == NULL && esquerdaD->dir == NULL) {
            cont = cont + 1;
        }
            esquerdaD = esquerdaD->dir;
    }

     while(esquerdaE != NULL) {
        if(esquerdaE->esq == NULL && esquerdaE->dir == NULL) {
            cont = cont + 1;
        }
        if(esquerdaE->esq == NULL && esquerdaE->dir != NULL) {
            esquerdaE = esquerdaE->dir;
        } else {
            esquerdaE = esquerdaE->esq;
        }
    }

    if(cont == 0) {
        cont = 1;
    }

    return cont;
}


int quantnosrecursivo(struct Node* no) {
    struct Node* atual = no;
    if(atual == NULL) {
        return 0;
    }

    int noesq = quantnosrecursivo(atual->esq);
    int nodir = quantnosrecursivo(atual->dir);
    if(atual->dir == NULL && atual->esq == NULL) {
        return (noesq + nodir + 1);
    }
    return noesq + nodir;

}
