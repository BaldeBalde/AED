#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Lista {
	float *num, *den, *res;
	int tamanho, quantidade;
};

struct Item {
	float infon;
	float infod;
};

void criarlista(struct Lista*, int);
void inserir(struct Lista*, struct Item);
void mostrar(struct Lista);
int buscar(struct Lista, float);
void remover(struct Lista*, struct Item);
struct Item arredondar(struct Item);



int main(void) {
	int n;
	float res;
	char command;
	struct Lista L;
	struct Item d;

	scanf("%d", &n);
	criarlista(&L, n);

	while( scanf("\n%c", &command) != EOF) {
		if ( command == 'I') {
			scanf("%f %f", &d.infon, &d.infod);
			inserir(&L, d);
		} else if (command == 'R') {
			scanf("%f %f", &d.infon, &d.infod);
			remover(&L, d);
		} else if (command == 'B') {
			scanf("%f %f", &d.infon, &d.infod);
			res = d.infon/d.infod;
			printf("%s\n",(buscar(L, res) == 1?"SIM":"NAO"));
		} else if (command == 'M') {
			mostrar(L);
		}
	}

	return 0;
}

void criarlista(struct Lista *L, int n) {
	L->tamanho = n;
	L->quantidade = 0;
	L->num = (float*)malloc(n*sizeof(float));
	L->den = (float*)malloc(n*sizeof(float));
	L->res = (float*)malloc(n*sizeof(float));
}

void inserir(struct Lista *L, struct Item d) {
	int i = 0, j, r;
	float res = d.infon/d.infod;
	r = buscar(*L, res);
	if ( L->quantidade != L->tamanho && r == 0 ) {
		while( i < L->quantidade  && res > L->res[i] ) {
			i++;
		}

		for (j = L->quantidade ; j > i ; j--) {
			L->num[j] = L->num[j-1];
			L->den[j] = L->den[j-1];
			L->res[j] = L->res[j-1];
		}

		L->num[i] = d.infon;
		L->den[i] = d.infod;
		L->res[i] = res;
		L->quantidade = L->quantidade + 1;
	}
}

void mostrar(struct Lista L) {
	int i;
	for (i = 0 ; i < L.quantidade ; i++) {
		printf("%.0f/%.0f%s", L.num[i], L.den[i], (i < L.quantidade - 1?" ":"\n"));
	}
}

int buscar(struct Lista L, float res) {
	int i;
	for( i = 0; i < L.quantidade; i++) {
		if (L.res[i] == res) {
			return 1;
		}
	}
	return 0;
}

void remover(struct Lista *L, struct Item d) {
	int i = 0, j;
	float res = d.infon/d.infod;
		while( i < L->quantidade && L->res[i] != res) {
			i++;
		}
		if (L->res[i] == res) {
			for (j = i; j < L->quantidade - 1 ; j++) {
				L->num[j] = L->num[j+1];
				L->den[j] = L->den[j+1];
				L->res[j] = L->res[j+1];
			}
			L->quantidade = L->quantidade - 1;
		}
}

struct Item arredondar (struct Item d) {
	int num, den;
	num = round(d.infon);
	den = round(d.infod);
	if ( num % 7 == 0 && den % 7 == 0) {
		while (den > 7 && num % 7 == 0 && den % 7 == 0) {
			d.infon = d.infon/7;
			d.infod = d.infod/7;
			num = round(d.infon);
			den = round(d.infod);
		}
	} else if ( num % 5 == 0 && den % 5 == 0) {
		while (den > 5 && num % 5 == 0 && den % 5 == 0) {
			d.infon = d.infon/5;
			d.infod = d.infod/5;
			num = round(d.infon);
			den = round(d.infod);
		}
	} else if (num % 3 == 0 && den % 3 == 0) {
		while (den > 3 && num % 3 == 0 && den % 3 == 0) {
			d.infon = d.infon/3;
			d.infod = d.infod/3;
			num = round(d.infon);
			den = round(d.infod);
		}
	} else if (num % 2 == 0 && den % 2 == 0) {
		while (den > 2 && num % 2 == 0 && den % 2 == 0) {
			d.infon = d.infon/2;
			d.infod = d.infod/2;
			num = round(d.infon);
			den = round(d.infod);
		}
	}
	return d;
}

