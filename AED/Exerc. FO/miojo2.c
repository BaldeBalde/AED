#include <stdio.h>

int main(void) {
    int T, A, B, auxA, auxB, S, soma = 0, c = 0, start = 0, C = 0, rodar = 0;

    scanf("%d %d %d", &T, &A, &B);

    if ( T >= 0 && T <= 10000 && B > A && B > T && B < 40000) {
        rodar = 1;
    }

    auxA = A;
    auxB = B;
    soma = B;
    if (rodar == 1) {
    do{
        S = auxB - auxA;
        //printf("S = %d\n", S);


       if (S > A && c == 0) {
           B = S;
           auxA = A;
       } else if (S < A && c == 0){
           auxB = A;
           auxA = S;
           c = 1;
       } else if (S > A && c == 1){
            B = S;
            auxA = B;
       } else if (S < A && c == 1) {
           auxB = B;
           auxA = S;
           if (c == 1 && start == 0) {
               start = 1;
           }
           c = 0;
       }

       if (start == 1) {
           soma = soma + S;
       }
       //printf("soma = %d\n", soma);

    }while (S != T);

    printf("%d\n", soma);
    }

    return 0;
}