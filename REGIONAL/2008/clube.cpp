#include <cstdio>
#include <climits>

int n, m, l, k;
int p[10001], q[10001];
int x, y;

int main(void) {
	int i, j, a;

	while(scanf("%d %d", &n, &m)) {
		if(n == 0 && m == 0)
			break;

		scanf("%d", &l);
		scanf("%d", &k);

		for(i = 0; i <= 10000; i++)
			q[i] = p[i] = 0;

		for(i = 0; i < k; i++) {
			scanf("%d", &j);
			q[j] = ++p[j];
		}

		if((n * 100) % l && (m * 100) % l) {
			printf("impossivel\n");
		} else {
			x = y = INT_MAX;

			/* horizontal */
			if((n * 100) % l == 0) {
				a = n * 100 / l; /* linhas restantes */
				x = 0;

				/* coloca as tabuas grandonas */
				while(p[m] > 0 && a > 0) {
					p[m]--;
					x++;
					a--;
				}

				/* coloca as menores */
				for(j = m-1; a > 0 && x < INT_MAX; a--) {
					while(j > 0) {
						if(j == m/2.0 && p[j] > 1) break;
						if(j != m/2.0 && p[j] > 0 && p[m-j] > 0) break;
						j--;
					}
					if(j <= 0) {
						/* solucao invalida */
						x = INT_MAX;
						break;
					}
					p[j]--;
					p[m-j]--;
					x += 2;
				}
			}

			/* vertical */
			if((m * 100) % l == 0) {
				a = m * 100 / l; /* linhas restantes */
				y = 0;

				/* coloca as tabuas grandonas */
				while(q[n] > 0 && a > 0) {
					q[n]--;
					y++;
					a--;
				}

				/* coloca as menores */
				for(j = n-1; a > 0 && y < INT_MAX; a--) {
					while(j > 0) {
						if(j == n/2.0 && q[j] > 1) break;
						if(j != n/2.0 && q[j] > 0 && q[n-j] > 0) break;
						j--;
					}
					if(j <= 0) {
						/* solucao invalida */
						y = INT_MAX;
						break;
					}
					q[j]--;
					q[n-j]--;
					y += 2;
				}
			}

			if(x == INT_MAX && y == INT_MAX)
				printf("impossivel\n");
			else
				printf("%d\n", x < y ? x : y);
		}
	}

	return 0;
}
