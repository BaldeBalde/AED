#include <stdio.h>
#include <math.h>

int main(void) {
    int a, b, c;
    float delta, x1, x2;

    scanf("%d %d %d", &a, &b, &c);

    delta = b*b - 4 * a * c;

    x1 = ((-1)*b + sqrt(delta))/2*a;
    x2 = ((-1)*b - sqrt(delta))/2*a;

    printf("%.4f %.4f\n", x1, x2);


    return 0;
}