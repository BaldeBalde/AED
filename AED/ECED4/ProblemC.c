#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int info;
    char chave[50];
    struct Node *esq,*dir;
};

typedef struct Node* ArvBin;

ArvBin* criarArvore();
int valorcaracter(char);
void inserir(ArvBin*,int,char);
struct Node* removerNode(struct Node*);
int remover(ArvBin*,int);
void preordem(ArvBin*);
void emordem(ArvBin*);
void posordem(ArvBin*);

int main(void) {
    ArvBin* raiz = criarArvore();
    int a,r,c;
    char command[15],string[50];

    while(scanf("%s", command) != EOF) {
        if(!strcmp(command,"insert")) {
            scanf("\n%s",string);
            c = valorcaracter(caracter);
            inserir(raiz,c,caracter);
        } else if(!strcmp(command,"delete")) {
            scanf("\n%s", string);
            c = valorcaracter(caracter);
            r = remover(raiz,c);
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

void inserir(ArvBin* raiz, int a, char caracter) {
    if(raiz == NULL) {
        return;
    }
    struct Node* novo;
    novo = (struct Node*)malloc(sizeof(struct Node));
    if(novo == NULL) {
        return;
    }
    novo->info = a;
    novo->chave = caracter;
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

void preordem(ArvBin* raiz) {
    if(raiz == NULL) {
        return;
    } else if(*raiz != NULL) {
        printf("%c ",(*raiz)->chave);
        preordem(&((*raiz)->esq));
        preordem(&((*raiz)->dir));
    }
}

void emordem(ArvBin* raiz) {
    if(raiz == NULL) {
        return;
    } else if(*raiz != NULL) {
        emordem(&((*raiz)->esq));
        printf("%c ",(*raiz)->chave);
        emordem(&((*raiz)->dir));
    }
}

void posordem(ArvBin* raiz) {
    if (raiz == NULL) {
        return;
    } else if (*raiz != NULL) {
        posordem(&((*raiz)->esq));
        posordem(&((*raiz)->dir));
        printf("%c ",(*raiz)->chave);
    }
}

int valorcaracter(char caracter) {
    int c = 0;
    if(caracter == 'A') {
        c = 1;
    } else if (caracter == 'B') {
        c = 2;
    } else if (caracter == 'C') {
        c = 3;
    } else if (caracter == 'D') {
        c = 4;
    } else if (caracter == 'E') {
        c = 5;
    } else if (caracter == 'F') {
        c = 6;
    } else if (caracter == 'G') {
        c = 7;
    } else if (caracter == 'H') {
        c = 8;
    } else if (caracter == 'I') {
        c = 9;
    } else if (caracter == 'J') {
        c = 10;
    } else if (caracter == 'K') {
        c = 11;
    } else if (caracter == 'L') {
        c = 12;
    } else if (caracter == 'M') {
        c = 13;
    } else if (caracter == 'N') {
        c = 14;
    } else if (caracter == 'O') {
        c = 15;
    } else if (caracter == 'P') {
        c = 16;
    } else if (caracter == 'Q') {
        c = 17;
    } else if (caracter == 'R') {
        c = 18;
    } else if (caracter == 'S') {
        c = 19;
    } else if (caracter == 'T') {
        c = 20;
    } else if (caracter == 'U') {
        c = 21;
    } else if (caracter == 'V') {
        c = 22;
    } else if (caracter == 'W') {
        c = 23;
    } else if (caracter == 'X') {
        c = 24;
    } else if (caracter == 'Y') {
        c = 25;
    } else if (caracter == 'Z') {
        c = 26;
    }

    return c;
}