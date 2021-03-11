#include <stdio.h>

int main(void) {
    int n, i, pv1, pv2;

    scanf("%d", &n);

    for( i = 0 ; i < n ; i = i + 1) {
        scanf("%d %d", &pv1, &pv2);

        if (pv1 > pv2 && pv2 >= 3 && pv2 <= 96) {
            printf("Minguante\n");
        } else if (pv2 >= 0 && pv2 <= 2) {
            printf("Nova\n");
        } else if (pv2 >= 3 && pv2 <= 96) {
            printf("Crescente\n");
        } else {
            printf("Cheia\n");
        }
    }




    return 0;
}