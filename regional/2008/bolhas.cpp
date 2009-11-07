#include <cstdio>

int n, c;
int v[100000], a[100000];

void merge(int a[], int aux[], int esq, int meio, int dir) {
	int i, esq_fim, n, aux_pos;

	esq_fim = meio - 1;
	aux_pos = esq;
	n = dir - esq + 1;

	while(esq <= esq_fim && meio <= dir) {
		if(a[esq] <= a[meio]) {
			aux[aux_pos++] = a[esq++];
		} else {
			aux[aux_pos++] = a[meio++];
			c += esq_fim - esq + 1; /* conta swaps */
		}
	}

	while(esq <= esq_fim)
		aux[aux_pos++] = a[esq++];

	while(meio <= dir)
		aux[aux_pos++] = a[meio++];

	for(i = 0; i < n; i++, dir--)
		a[dir] = aux[dir];
}

void mergesort(int a[], int aux[], int esq, int dir) {
	if(dir > esq) {
		int meio = (dir + esq) / 2;
		mergesort(a, aux, esq, meio);
		mergesort(a, aux, meio + 1, dir);
		merge(a, aux, esq, meio + 1, dir);
	}
}

int main(void) {
	int i;

	while(scanf("%d", &n)) {
		if(n == 0)
			break;

		/* leitura */
		for(i = 0; i < n; i++)
			scanf("%d", &v[i]);

		/* processa */
		c = 0;
		mergesort(v, a, 0, n-1);

		/* output */
		printf("%s\n", (c % 2) ? "Marcelo" : "Carlos");
	}

	return 0;
}
