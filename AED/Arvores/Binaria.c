#include <stdio.h>
#include <stdlib.h>


struct Node {
    int info;
    struct Node *esq,*dir;
};

typedef struct Node* ArvBin;

ArvBin* criarArvore();
int vazia(ArvBin*);
void libera(struct Node*);
void inserir(ArvBin*,int);
struct Node* removerNode(struct Node*);
int remover(ArvBin*,int);
int busca(ArvBin*,int);
void preordem(ArvBin*);
void emordem(ArvBin*);
void posordem(ArvBin*);
int altura(ArvBin*);
int quantnos(ArvBin*);
void destruirArvore(ArvBin*);


int main(void) {
    int a,alt;
    ArvBin* raiz = criarArvore();

    a = vazia(raiz);

    if(a) {
        printf("A arvore esta vazia.\n");
    } else {
        printf("A arvore nao esta vazia.\n");
    }

    alt = altura(raiz);

    printf("Altura da arvore: %d\n", alt);

    destruirArvore(raiz);

    return 0;
}

ArvBin* criarArvore() {
    ArvBin* raiz = (ArvBin*)malloc(sizeof(ArvBin));
    if(raiz != NULL) {
        *raiz = NULL;
    }
    return raiz;
}

int vazia(ArvBin* raiz) {
    if(raiz == NULL) {
        return 1;
    } else if (*raiz == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void libera(struct Node* no) {
    if(no == NULL) {
        return;
    }
    libera(no->esq);
    libera(no->dir);
    free(no);
    no = NULL;
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

struct Node* removerNode(struct Node* atual) {
    struct Node *n1,*n2;

    if(atual->esq == NULL) {
        n2 = atual->dir;
        free(atual);
        return n2;
    }
    n1 = atual;
    n2 = atual->esq;
    while(n2->dir != NULL) {
        n1 = n2;
        n2 = n2->dir;
    }

    if(n1 != atual) {
        n1->dir = n2->esq;
        n2->esq = atual->esq;
    }
    n2->dir = atual->dir;
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
                *raiz = removerNode(atual);
            } else {
                if(anterior->dir == atual) {
                    anterior->dir = removerNode(atual);
                } else {
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

int busca(ArvBin* raiz, int a) {
    if(raiz == NULL) {
        return 0;
    }
    struct Node* atual = *raiz;
    while(atual != NULL) {
        if(a == atual->info) {
            return atual->info;
        }
        if(a > atual->info) {
            atual = atual->dir;
        } else {
            atual = atual->esq;
        }
    }
    return 0;
}

void preordem(ArvBin* raiz) {
    if(raiz == NULL) {
        return;
    } else if(*raiz != NULL) {
        printf("%d\n",(*raiz)->info);
        preordem(&((*raiz)->esq));
        preordem(&((*raiz)->dir));
    }
}

void emordem(ArvBin* raiz) {
    if(raiz == NULL) {
        return;
    } else if(*raiz != NULL) {
        emordem(&((*raiz)->esq));
        printf("%d\n",(*raiz)->info);
        emordem(&((*raiz)->dir));
    }
}

void posordem(ArvBin* raiz) {
    if (raiz == NULL) {
        return;
    } else if (*raiz != NULL) {
        posordem(&((*raiz)->esq));
        posordem(&((*raiz)->dir));
        printf("%d\n",(*raiz)->info);
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

int quantnos(ArvBin* raiz) {
    if(raiz == NULL) {
        return 0;
    } else if (*raiz == NULL) {
        return 0;
    }
    int noesq = quantnos(&((*raiz)->esq));
    int nodir = quantnos(&((*raiz)->esq));
    return (noesq + nodir + 1);
}

void destruirArvore(ArvBin* raiz) {
    if(raiz == NULL) {
        return;
    }
    libera(*raiz);
    free(raiz);
}