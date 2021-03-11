#include <stdio.h>
#include <stdlib.h>


struct Lista {
    char *info;
    int *ordem, tamanho,quantidade;
};



void criarlista(struct Lista*, int);
void mostrar(struct Lista);
void remover(struct Lista*, char);
int repetido(struct Lista*, char);
void inserirordem(struct Lista*, char);
int valoralfabeto(char);


int main(void) {
    int n;
    char command, a;
    struct Lista L;

    scanf("%d", &n);

    criarlista(&L, n);


    while( scanf("\n%c", &command) != EOF) {
        if ( command == 'I') {
            scanf("\n%c", &a);
            inserirordem(&L,a);
        } else if ( command == 'R') {
            scanf("\n%c", &a);
            remover(&L,a);
        } else if ( command == 'M') {
            mostrar(L);
        } else if ( command == 'B') {
            scanf("\n%c", &a);
            printf("%s", (repetido(&L, a)?"SIM\n":"NAO\n"));
        }
    }

    return 0;
}

void criarlista(struct Lista *L, int n) {
    L->tamanho = n;
    L->quantidade = 0;
    L->info = (char*)malloc(n*sizeof(char));
    L->ordem = (int*)malloc(n*sizeof(int));

}


void mostrar(struct Lista L) {
    int i;
    for (i = 0; i < L.quantidade; i++) {
        printf("%c%s", L.info[i], (i < L.quantidade - 1?" ":"\n"));
    }
}

int repetido (struct Lista *L, char a) {
    int i;
    for (i = 0 ; i < L->quantidade; i ++) {
        if (L->info[i] == a) {
            return 1;
        }
    }
    return 0;
}

void remover(struct Lista *L, char a) {
    int i = 0, j;
    while( i < L->quantidade && L->info[i] != a) {
        i++;
    }

    if (L->info[i] == a) {
        for(j = i ; j < L->quantidade - 1 ; j ++) {
        L->info[j] = L->info[j+1];
        L->ordem[j] = L->ordem[j + 1];
        }
    L->quantidade = L->quantidade - 1;
    }
}

void inserirordem(struct Lista *L, char a) {
    int i = 0, j, r, x;
    x = valoralfabeto(a);
    r = repetido( L,a);
    if ( L->quantidade != L->tamanho && r == 0) {
        while( i < L->quantidade &&  x > L->ordem[i]) {
            i++;
        }
        for (j = L->quantidade ; j > i ; j--) {
            L->info[j] = L->info[j - 1];
            L->ordem[j] = L->ordem[j - 1];
        }
        L->info[i] = a;
        L->ordem[i] = valoralfabeto(a);
        L->quantidade = L->quantidade + 1;
    }
}

int valoralfabeto(char a) {
    int ordem;
    if (a == 'A') {
            ordem = 1;
        } else if (a == 'B') {
            ordem = 2;
        } else if (a == 'C') {
            ordem = 3;
        } else if (a == 'D') {
            ordem = 4;
        } else if (a == 'E') {
            ordem = 5;
        } else if (a == 'F') {
            ordem = 6;
        } else if (a == 'G') {
            ordem = 7;
        } else if (a == 'H') {
            ordem = 8;
        } else if (a == 'I') {
            ordem = 9;
        } else if (a == 'J') {
            ordem = 10;
        } else if (a == 'K') {
            ordem = 11;
        } else if (a == 'L') {
            ordem = 12;
        } else if (a == 'M') {
            ordem = 13;
        } else if (a == 'N') {
            ordem = 14;
        } else if (a == 'O') {
            ordem = 15;
        } else if (a == 'P') {
            ordem = 16;
        } else if (a == 'Q') {
            ordem = 17;
        } else if (a == 'R') {
            ordem = 18;
        } else if (a == 'S') {
            ordem = 19;
        } else if (a == 'T') {
            ordem = 20;
        } else if (a == 'U') {
            ordem = 21;
        } else if (a == 'V') {
            ordem = 22;
        } else if (a == 'W') {
            ordem = 23;
        } else if (a == 'X') {
            ordem = 24;
        } else if (a == 'Y') {
            ordem = 25;
        } else if( a == 'Z') {
            ordem = 26;
        }
        return ordem;
}

