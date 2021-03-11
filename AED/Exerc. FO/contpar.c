#include <stdio.h>

int main(void) {
    int n, r, c = 0 ;

    while(scanf("%d",&n) != EOF) {

        do {
            r = n%10;
            if( r%2 == 0) {
                c = c + 1;
            }
            n = n / 10;

        } while(n >= 1);
        printf("%d\n", c);
        c = 0;
    }

    return 0;
}