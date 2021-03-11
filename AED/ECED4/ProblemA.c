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
struct Node* removerNode(struct Node*);
int remover(ArvBin*,int);
void preordem(ArvBin*);
void emordem(ArvBin*);
void posordem(ArvBin*);

int main(void) {
    ArvBin* raiz = criarArvore();
    int a,r;
    char command[15];

    while(scanf("%s", command) != EOF) {
        if(!strcmp(command,"insert")) {
            scanf("%d",&a);
            inserir(raiz,a);
        } else if(!strcmp(command,"delete")) {
            scanf("%d",&a);
            r = remover(raiz,a);
            if(r) {
                //printf("%d\n",a);
            }
        } else if(!strcmp(command,"pre-order")) {
            preordem(raiz);
            printf("\n");
        } else if(!strcmp(command,"in-order")) {
            emordem(raiz);
            printf("\n");
        } else if(!strcmp(command,"post-order")) {
            posordem(raiz);
            printf("\n");
        }
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

struct Node* removerNode(struct Node* atual) {
    struct Node *n1,*n2;
    if(atual->dir == NULL) {
        n2 = atual->esq;
        free(atual);
        return n2;
    } else if(atual->esq == NULL) {
        n2 = atual->dir;
        free(atual);
        return n2;
    }

    n1 = atual;
    n2 = atual->dir;
    while(n2->esq != NULL) {
        n1 = n2;
        n2 = n2->esq;
    }

    if(n1 != atual && n2->esq == NULL && n2->dir == NULL) {
        n1->esq = n2->esq;
        n2->esq = atual->esq;
        n2->dir = atual->dir;
    } else if(n2->dir != NULL) {
        n2->esq = atual->esq;
    }
    free(atual);
    return n2;
}

int remover(ArvBin* raiz, int a) {
    if(raiz == NULL) {
        return 0;
    }
    struct Node* anterior = NULL;
    struct Node* atual = *raiz;

    while(atual != NULL) {
        if(a == atual->info) {
            if(atual == *raiz) {
                printf("%d\n",a);
                *raiz = removerNode(atual);
            } else {
                if(anterior->dir == atual) {
                    printf("%d\n",a);
                    anterior->dir = removerNode(atual);
                } else {
                    printf("%d\n",a);
                    anterior->esq = removerNode(atual);
                }
                return 1;
            }
        }
        anterior = atual;
        if(a < atual->info) {
            atual = atual->esq;
        } else {
            atual = atual->dir;
        }
    }
    return 0;
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