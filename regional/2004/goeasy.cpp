#include <cstdio>

#define NN 128
#define INF 1<<15

int num_zones, num_stations;
int num_trains, num_bus;
int inicio, fim;

int w[NN][NN];

/* Union-Find {{{ */
int item[NN], rank[NN];

void makeset(int x) {
	item[x] = x;
	rank[x] = 0;
}

int findset(int x) {
	if(x != item[x]) item[x] = findset(item[x]);
	return item[x];
}

void linkset(int x, int y) {
	if(rank[x] > rank[y]) {
		item[y] = x;
	} else {
		item[x] = y;
		if(rank[x] == rank[y]) rank[y]++;
	}
}

void unionset(int x, int y) { linkset(findset(x), findset(y)); }
/* }}} */
/* Dijkstra {{{ */
int dijkstra(int start, int end) {
	int in[NN];
	int d[NN];
	int p, z;

	for(z = 0; z < num_stations; z++) {
		d[z] = w[start][z];
		in[z] = 0;
	}

	d[start] = 0;
	in[start] = 1;

	while(!in[end]) {
		int menor = INF;
		for(p = -1, z = 0; z < num_stations; z++) {
			if(!in[z] && d[z] < menor) {
				menor = d[z];
				p = z;
			}
		}

		if(menor == INF)
			break;

		in[p] = 1;

		for(z = 0; z < num_stations; z++)
			if(!in[z] && w[p][z] < INF && d[p] + w[p][z] < d[z])
				d[z] = d[p] + w[p][z];
	}

	return d[end];
}
/* }}} */

int min(int a, int b) { return a < b ? a : b; }

int main(void) {
	int i, j, k;

	while(scanf("%d %d", &num_zones, &num_stations)) {
		if(num_zones == 0 && num_stations == 0) break;

		/* init */
		for(i = 0; i < num_stations; i++)
			for(j = 0; j < num_stations; j++)
				w[i][j] = i == j ? 0 : INF;
		for(i = 0; i < num_stations; i++) makeset(i);

		/* input */
		/* le zones */
		for(i = 0; i < num_zones; i++) {
			int ns;
			scanf("%d", &ns);
			for(int a = -1, b = -1, j = 0; j < ns; j++) {
				scanf("%d", &b), b--;
				if(a > -1 && findset(a) != findset(b)) unionset(a, b);
				a = b;
			}
		}
		scanf("%d %d", &num_trains, &num_bus);
		/* le trains */
		for(i = 0; i < num_trains; i++) {
			int s[NN], ns;
			scanf("%d", &ns);
			for(j = 0; j < ns; j++) scanf("%d", &s[j]), s[j]--;
			for(j = 0; j < ns; j++) {
				int crosses = 0;
				for(k = j+1; k < ns; k++) {
					if(findset(s[k]) != findset(s[k-1])) crosses++;
					w[s[k]][s[j]] = w[s[j]][s[k]] = min(w[s[j]][s[k]], crosses*4);
				}
			}
		}
		/* le buses */
		for(i = 0; i < num_bus; i++) {
			int s[NN], ns;
			scanf("%d", &ns);
			for(j = 0; j < ns; j++) scanf("%d", &s[j]), s[j]--;
			for(j = 0; j < ns; j++) {
				for(k = j+1; k < ns; k++) {
					w[s[j]][s[k]] = min(w[s[j]][s[k]], 1);
					w[s[k]][s[j]] = min(w[s[k]][s[j]], 1);
				}
			}
		}
		/* src dest */
		scanf("%d %d", &inicio, &fim), inicio--, fim--;

		/* output */
		printf("%d\n", 2 + dijkstra(inicio, fim));
	}

	return 0;
}
