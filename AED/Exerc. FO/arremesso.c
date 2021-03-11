#include <stdio.h>

int main(void) {
    int N, V, P = 0, flag = 0, C;

    scanf("%d %d", &N, &V);

    while( N != 0 && V != 0) {
        C = V;
        while(V > 0) {
            while( C > 0) {
                P = P + V;
                if (P == N) {
                    flag = 1;
                    C = C - 1;
                }
            }
            V = V - 1;
        }
        if ( flag == 1) {
            printf("possivel\n");
        } else {
            printf("impossivel\n");
        }

        scanf("%d %d", &N, &V);
    }

    return 0;
}