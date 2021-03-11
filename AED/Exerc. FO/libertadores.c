#include <stdio.h>

int main(void) {
    int n, N, i, T1r, T2r, T1s = 0, T2s = 0, T1saldo, T2saldo;
    char vs;

    scanf("%d", &n);


    for (i = 0; i < n ; i = i + 1) {
        scanf("%d %c %d", &T1r, &vs, &T2r);
        T1s = T1s + T1r;
        T2s = T2s + T2r;
        T2saldo = T2r;
        scanf("%d %c %d", &T2r, &vs, &T1r);
        T1s = T1s + T1r;
        T2s = T2s + T2r;
        T1saldo = T1r;

        if ( T1s > T2s) {
            printf("Time 1\n");
        } else if ( T2s > T1s) {
            printf("Time 2\n");
        } else if ( T1s == T2s && T1saldo > T2saldo) {
            printf("Time 1\n");
        } else if ( T1s == T2s && T2saldo > T1saldo) {
            printf("Time 2\n");
        } else {
            printf("Penaltis\n");
        }

        T1s = 0;
        T2s = 0;
    }



    return 0;
}