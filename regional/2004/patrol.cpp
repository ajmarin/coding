#include <cstdio>

#define NN 1024
#define INF (1<<20)

int num_cities, num_roads, num_cycles, current, next;
int dist[NN][NN], ici[NN];
int cycle, distleft, iei, ei;

int main(void) {
	int i, j;

	while(scanf("%d %d %d %d", &num_cities, &num_roads, &num_cycles, &current)) {
		if(num_cities == 0 && num_roads == 0 && num_cycles == 0 && current == 0) break;

		/* init */
		iei = ei = 0;
		cycle = 0;
		distleft = 0;
		current--;
		for(i = 0; i < num_cities; i++) {
			ici[i] = 0;
			for(j = 0; j < num_cities; j++)
				dist[i][j] = INF;
		}

		/* input */
		for(i = 0; i < num_roads; i++) {
			int x, y, d;
			scanf("%d %d %d", &x, &y, &d), x--, y--;
			dist[x][y] = dist[y][x] = d;
		}

		/* simula */
		int highest = 0, next = -1;
		for(i = num_cities-1; i >= 0; i--) {
			if(dist[current][i] < INF && ici[i] >= highest) {
				next = i;
				highest = ici[i];
				distleft = dist[current][i];
			}
		}
		current = next;

		while(cycle < num_cycles) {
			/* atualiza ici e iei */
			iei = 0;
			for(i = 0; i < num_cities; i++) {
				ici[i]++;
				iei += ici[i];
			}

			if(distleft) distleft--;

			if(distleft == 0) {
				/* visita a cidade */
				iei -= ici[current];
				ici[current] = 0;

				/* encontra proxima cidade */
				int highest = 0, next = -1;
				for(i = num_cities-1; i >= 0; i--) {
					if(dist[current][i] < INF && ici[i] >= highest) {
						next = i;
						highest = ici[i];
						distleft = dist[current][i];
					}
				}
				current = next;
			}

			/* atualiza ei */
			ei += iei;

#ifdef DEBUG
			printf("cycle %d: (iei: %d, ei: %d)\n", cycle, iei, ei);
			for(i = 0; i < num_cities; i++) printf("ici%d: %d, ", i+1, ici[i]);
			printf("\n");
#endif

			/* proximo ciclo! */
			cycle++;
		}

		/* output */
		printf("%d\n", ei);
	}

	return 0;
}
