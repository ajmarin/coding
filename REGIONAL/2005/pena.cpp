#include <cstdio>
#include <cstring>
#include <cstdlib>

struct tarefa {
	int dia, inicio, fim;
	int pont;
};

int n, t;
tarefa tarefas[10240];
int p[60*24][5];

int max(int a, int b) { return a > b ? a : b; }

int tarefacmp(const void *ta, const void *tb) {
	tarefa a = *(tarefa *)ta;
	tarefa b = *(tarefa *)tb;
	if(a.dia < b.dia) return -1;
	else if(a.dia > b.dia) return 1;
	else {
		if(a.inicio < b.inicio) return -1;
		else if(a.inicio > b.inicio) return 1;
		else {
			if(a.fim < b.fim) return -1;
			else if(a.fim > b.fim) return 1;
			else return 0;
		}
	}
}

int getvalor(int dia, int min) {
	int i;
	for(i = min; i < 60*24 && p[i][dia] == -1; i++);
	return p[i][dia];
}

int main(void) {
	int i, j;

	while(scanf("%d", &n)) {
		if(n == 0) break;

		/* init */
		t = 0;
		for(j = 0; j < 5; j++) {
			for(i = 0; i < 60*24; i++)
				p[i][j] = -1;
			p[60*24 - 1][j] = 0;
		}

		/* input */
		for(i = 0; i < n; i++) {
			char dia[6];
			int h, m;
			scanf("%d", &tarefas[i].pont);
			scanf("%d", &tarefas[i].pont);
			scanf("%s", dia);
			if(strcmp(dia, "Seg") == 0) tarefas[i].dia = 0;
			else if(strcmp(dia, "Ter") == 0) tarefas[i].dia = 1;
			else if(strcmp(dia, "Qua") == 0) tarefas[i].dia = 2;
			else if(strcmp(dia, "Qui") == 0) tarefas[i].dia = 3;
			else if(strcmp(dia, "Sex") == 0) tarefas[i].dia = 4;
			scanf("%d:%d", &h, &m);
			tarefas[i].inicio = h*60 + m;
			scanf("%d:%d", &h, &m);
			tarefas[i].fim = h*60 + m;
		}

		/* ordena */
		qsort(tarefas, n, sizeof(tarefa), tarefacmp);

		/* processa */
		for(i = n-1; i >= 0; i--)
			p[tarefas[i].inicio][tarefas[i].dia] =
				max(getvalor(tarefas[i].dia, tarefas[i].inicio), getvalor(tarefas[i].dia, tarefas[i].fim) + tarefas[i].pont);
		for(i = 0; i < 5; i++) t += getvalor(i, 0);

		/* output */
		printf("Total de pontos: %d\n", t);
		printf("Seg: %d\n", getvalor(0, 0));
		printf("Ter: %d\n", getvalor(1, 0));
		printf("Qua: %d\n", getvalor(2, 0));
		printf("Qui: %d\n", getvalor(3, 0));
		printf("Sex: %d\n", getvalor(4, 0));
	}

	return 0;
}
