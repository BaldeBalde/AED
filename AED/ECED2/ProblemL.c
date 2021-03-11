#include <stdio.h>
#include <stdlib.h>

int marcianvalue(int);
void insertionsort(int*,int);

int main(void) {
    int *vetor, n, a, i;

    scanf("%d",&n);

    vetor = (int*)malloc(n*sizeof(int));

    for(i = 0 ; i < n ; i++) {
        scanf("%d", &a);
        vetor[i] = a;
    }

    insertionsort(vetor, n);

    for(i = 0; i < n ; i++) {
        printf("%d%s",vetor[i], i < n - 1?" ":"\n");
    }

    return 0;
}

int marcianvalue(int a) {
    int count = 0, aux;
    while(a > 0) {
        if (a < 10) {
            if(a%10 == 0) {
                count = count + 0;
            } else if(a%10 == 5) {
                count = count + 1;
            } else if(a%10 == 6) {
                count = count + 2;
            } else if(a%10 == 4) {
                count = count + 3;
            } else if(a%10 == 8) {
                count = count + 4;
            } else if(a%10 == 9) {
                count = count + 5;
            } else if(a%10 == 7) {
                count = count + 6;
            } else if(a%10 == 3) {
                count = count + 7;
            } else if(a%10 == 1) {
                count = count + 8;
            } else if(a%10 == 2) {
                count = count + 9;
            }
            a = a/10;
        } else if (a >= 10 && a < 100) {
            if(a >= 50 && a < 60 ) {
                count = count + 10;
                a = a - 50;
            } else if(a >= 60 && a < 70) {
                count = count + 20;
                a = a - 60;
            } else if(a >= 40 && a < 50) {
                count = count + 30;
                a = a - 40;
            } else if(a >= 80 && a < 90) {
                count = count + 40;
                a = a - 80;
            } else if(a >= 90 && a < 100) {
                count = count + 50;
                a = a - 90;
            } else if(a >= 70 && a < 80) {
                count = count + 60;
                a = a - 70;
            } else if(a >= 30 && a < 40) {
                count = count + 70;
                a = a - 30;
            } else if(a >= 10 && a < 20) {
                count = count + 80;
                a = a - 10;
            } else if(a >= 20 && a < 30) {
                count = count + 90;
                a = a - 20;
            }
        } else if (a >= 100 && a < 1000) {
            if(a >= 500 && a < 600 ) {
                count = count + 100;
                a = a - 500;
            } else if(a >= 600 && a < 700) {
                count = count + 200;
                 a = a - 600;
            } else if(a >= 400 && a < 500) {
                count = count + 300;
                 a = a - 400;
            } else if(a >= 800 && a < 900) {
                count = count + 400;
                 a = a - 800;
            } else if(a >= 900 && a < 1000) {
                count = count + 500;
                 a = a - 900;
            } else if(a >= 700 && a < 800) {
                count = count + 600;
                 a = a - 700;
            } else if(a >= 300 && a < 400) {
                count = count + 700;
                 a = a - 300;
            } else if(a >= 100 && a < 200) {
                count = count + 800;
                 a = a - 100;
            } else if(a >= 200 && a < 300) {
                count = count + 900;
                 a = a - 200;
            }
        } else if (a >= 1000 && a < 10000) {
            if(a >= 5000 && a < 6000 ) {
                count = count + 1000;
                a = a - 5000;
            } else if(a >= 6000 && a < 7000) {
                count = count + 2000;
                 a = a - 6000;
            } else if(a >= 4000 && a < 5000) {
                count = count + 3000;
                 a = a - 4000;
            } else if(a >= 8000 && a < 9000) {
                count = count + 4000;
                 a = a - 8000;
            } else if(a >= 9000 && a < 10000) {
                count = count + 5000;
                 a = a - 9000;
            } else if(a >= 7000 && a < 8000) {
                count = count + 6000;
                 a = a - 7000;
            } else if(a >= 3000 && a < 4000) {
                count = count + 7000;
                 a = a - 3000;
            } else if(a >= 1000 && a < 2000) {
                count = count + 8000;
                 a = a - 1000;
            } else if(a >= 2000 && a < 3000) {
                count = count + 9000;
                 a = a - 2000;
            } else if (a >= 10000) {
                a = 0;
            }
        } else if (a >= 10000 && a < 100000) {
            if(a >= 50000 && a < 60000 ) {
                count = count + 10000;
                a = a - 50000;
            } else if(a >= 60000 && a < 70000) {
                count = count + 20000;
                 a = a - 60000;
            } else if(a >= 40000 && a < 50000) {
                count = count + 30000;
                 a = a - 40000;
            } else if(a >= 80000 && a < 90000) {
                count = count + 40000;
                 a = a - 80000;
            } else if(a >= 90000 && a < 100000) {
                count = count + 50000;
                 a = a - 90000;
            } else if(a >= 70000 && a < 80000) {
                count = count + 60000;
                 a = a - 70000;
            } else if(a >= 30000 && a < 40000) {
                count = count + 70000;
                 a = a - 30000;
            } else if(a >= 10000 && a < 20000) {
                count = count + 80000;
                 a = a - 10000;
            } else if(a >= 20000 && a < 30000) {
                count = count + 90000;
                 a = a - 20000;
            }
        } else if (a >= 100000 && a < 1000000) {
            if(a >= 500000 && a < 600000 ) {
                count = count + 100000;
                a = a - 500000;
            } else if(a >= 600000 && a < 700000) {
                count = count + 200000;
                 a = a - 600000;
            } else if(a >= 400000 && a < 500000) {
                count = count + 300000;
                 a = a - 400000;
            } else if(a >= 800000 && a < 900000) {
                count = count + 400000;
                 a = a - 800000;
            } else if(a >= 900000 && a < 1000000) {
                count = count + 500000;
                 a = a - 900000;
            } else if(a >= 700000 && a < 800000) {
                count = count + 600000;
                 a = a - 700000;
            } else if(a >= 300000 && a < 400000) {
                count = count + 700000;
                 a = a - 300000;
            } else if(a >= 100000 && a < 200000) {
                count = count + 800000;
                 a = a - 100000;
            } else if(a >= 200000 && a < 300000) {
                count = count + 900000;
                 a = a - 200000;
            }
        }
    }
    return count;
}


void insertionsort(int* vetor, int n) {
    int i,j,aux;
    for(i = 1 ; i < n ; i++) {
        aux = vetor[i];
        for(j = i ; (j > 0) && (marcianvalue(aux) < marcianvalue(vetor[j-1])) ; j--) {
            vetor[j] = vetor[j-1];
        }
        vetor[j] = aux;
    }
}