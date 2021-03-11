#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct String {
    char string[10];
};

struct Lista {
    struct String* word;
    int *ordem, tamanho,quantidade;
};



void criarlista(struct Lista*, int);
void mostrar(struct Lista);
void remover(struct Lista*, char*);
int repetido(struct Lista*, char*);
void inserirordem(struct Lista*, char*);
int valoralfabeto(char);
int lexicografia(struct Lista*,char *a, int, int);


int main(void) {
    int n;
    char command, a[10];
    struct Lista L;

    scanf("%d", &n);

    criarlista(&L, n);


    while( scanf("\n%c", &command) != EOF) {
        if ( command == 'I') {
            scanf("%s", a);
            inserirordem(&L, a);
        } else if (command == 'M') {
            mostrar(L);
        } else if (command == 'R') {
            scanf("%s", a);
            remover(&L, a);
        } else if (command == 'B'){
            scanf("%s", a);
            printf("%s\n", repetido(&L, a)?"SIM":"NAO");
        }
    }

    return 0;
}

void criarLista(struct Lista *L, int n) {
    L->tamanho = n;
    L->quantidade = 0;
    L->word = (struct String*)malloc(n*sizeof(struct String));
    L->ordem = (int*)malloc(n*sizeof(int));
}

void inserirordem(struct Lista *L, char *a) {

}


void remover(struct Lista *L, char *a) {
    int i = 0, j;
    while( i < L->quantidade && strcmp(L->word[i].string, a) != 0) {
        i++;
    }

    if (strcmp(L->word[i].string, a) == 0) {
        for ( j = i; j < L->quantidade - 1; j ++) {
            strcpy(L->word[j].string, L->word[j+1].string);
            L->ordem[j] = L->ordem[j+1];
        }
        L->quantidade = L->quantidade - 1;
    }
}

int lexicografia(struct Lista* L,char *a, int i, int k) {

}


void mostrar(struct Lista L) {
    int i;
    for (i = 0; i < L.quantidade ; i++) {
        printf("%s%s", L.word[i].string, (i < L.quantidade - 1?" ":"\n"));
    }
}

int repetido (struct Lista *L, char *a) {
    int i,x;
    for (i = 0 ; i < L->quantidade; i ++) {
        x = strcmp(L->word[i].string, a);
        if (x == 0) {
            return 1;
        }
    }
    return 0;
}


int valoralfabeto(char a) {
    int ordem;
    if (a == 'a'&& a == 'A') {
            ordem = 1;
        } else if (a == 'b' && a == 'B') {
            ordem = 2;
        } else if (a == 'c' && a == 'C') {
            ordem = 3;
        } else if (a == 'd' && a == 'D') {
            ordem = 4;
        } else if (a == 'e' && a == 'E') {
            ordem = 5;
        } else if (a == 'f' && a == 'F') {
            ordem = 6;
        } else if (a == 'g' && a == 'G') {
            ordem = 7;
        } else if (a == 'h' && a == 'H') {
            ordem = 8;
        } else if (a == 'i' && a == 'I') {
            ordem = 9;
        } else if (a == 'j' && a == 'J') {
            ordem = 10;
        } else if (a == 'k' && a == 'K') {
            ordem = 11;
        } else if (a == 'l' && a == 'L') {
            ordem = 12;
        } else if (a == 'm' && a == 'M') {
            ordem = 13;
        } else if (a == 'n' && a == 'N') {
            ordem = 14;
        } else if (a == 'o' && a == 'O') {
            ordem = 15;
        } else if (a == 'p' && a == 'P') {
            ordem = 16;
        } else if (a == 'q' && a == 'Q') {
            ordem = 17;
        } else if (a == 'r' && a == 'R') {
            ordem = 18;
        } else if (a == 's' && a == 'S') {
            ordem = 19;
        } else if (a == 't' && a == 'T') {
            ordem = 20;
        } else if (a == 'u' && a == 'U') {
            ordem = 21;
        } else if (a == 'v' && a == 'V') {
            ordem = 22;
        } else if (a == 'w' && a == 'W') {
            ordem = 23;
        } else if (a == 'x' && a == 'X') {
            ordem = 24;
        } else if (a == 'y' && a == 'Y') {
            ordem = 25;
        } else if( a == 'z' && a == 'Z') {
            ordem = 26;
        }
        return ordem;
}
