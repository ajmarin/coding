#include <cstdio>

int n, d, dr, aux, i;
int q[10][100000]; /* queues */
int qf[10], qb[10]; /* front e back das queues */

int main(void) {
	while(scanf("%d %d", &n, &d)) {
		if(n == 0 && d == 0)
			break;

		/* limpa as filas */
		for(i = 0; i < 10; i++)
			qf[i] = qb[i] = 0;

		/* le os numeros nas filas */
		for(i = 0; i < n; i++) {
			scanf("%1d", &aux);
			q[aux][qb[aux]++] = i;
		}

		/* processa e imprime */
		dr = n - d;
		aux = -1;

		while(dr) {
			for(i = 9; i >= 0; i--) {
				while(qf[i] != qb[i] && q[i][qf[i]] < aux)
					qf[i]++;

				if(qf[i] == qb[i])
					continue;

				if(q[i][qf[i]] + dr - 1 < n) {
					printf("%d", i);
					aux = q[i][qf[i]++];
					dr--;
					break;
				}
			}
		}
		printf("\n");
	}

	return 0;
}
