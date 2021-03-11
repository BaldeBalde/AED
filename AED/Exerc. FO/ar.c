#include <stdio.h>

int main(void) {
    int N, V, V2, P = 0, flag = 0, C;

    scanf("%d %d", &N, &V);
    V2 = V;

    do{
        do {
            V2 = V;
            while(V2 > 0) {
                C = V2;
                while( C > 0) {
                    P = P + V2;
                    if (P == N) {
                        flag = 1;
                    }
                    C = C - 1;
                }
                V2 = V2 - 1;
            }

            P = 0;
            V = V - 1;
        }while (flag == 0 && V > 0);

            if ( flag == 1) {
                printf("possivel\n");
            } else {
                printf("impossivel\n");
            }

            flag = 0;

            scanf("%d %d", &N, &V);
    }while(N != 0 && V != 0);

    return 0;
}