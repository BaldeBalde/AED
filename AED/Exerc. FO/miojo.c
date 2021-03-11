#include <stdio.h>

int main(void) {
    int T, A, B, S, soma, c = 0, aux1, aux2, C = 0;

    scanf("%d %d %d", &T, &A, &B);
    aux1 = A;
    aux2 = B;
    soma = B;

    do {
        S = B - A;

        if ( c == 0 && C == 0) {
            B = aux1;
            A = S;
            c = c + 1;
            C = 1;
        } else if (c == 0) {
            B = aux1;
            A = S;
            c = c + 1;
            soma = soma + S;
        } else {
            B = aux2;
            A = S;
            c = c - 1;
            soma = soma + S;
        }

        printf("S = %d\n", S);


    }while (S != T);

    printf("%d\n", soma);

    return 0;
}