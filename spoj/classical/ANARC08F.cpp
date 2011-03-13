#include <cstdio>
#include <cstring>
#include <map>
#include <string>
using namespace std;
const int N = 128;
int cities, m[N][N], q[1024];
map < string, int > cn;
int add_city(const char *name){
	int &x = cn[name];
	if(!x) x = cities++;
	return x;
}
int main(void){
	char c1[16], edge[16], c2[16];
	int cnum = 0;
	for(int c, r, n; scanf("%d %d %d", &n, &c, &r) == 3 && (c + n + r); ){
		int a, b, cost, l;
		/* Clear adjacency matrix, map, reset city counter */
		memset(m, 0x3f, sizeof m);
		cn.clear();
		cities = 1;
		++c;
		/* Read broken-cars' cities */
		for(int i = 0; i < c; ++i){
			scanf("%s", c1);
			q[i] = add_city(c1);
		}
		/* Read graph's edges */
		for(int i = 0; i < r; ++i){
			scanf("%s %s %s", c1, edge, c2);
			sscanf(edge + 2, "%d", &cost);
			a = add_city(c1);
			b = add_city(c2);
			l = strlen(edge) - 1;
			if(edge[0] == '<') m[b][a] = min(m[b][a], cost);
			if(edge[l] == '>') m[a][b] = min(m[a][b], cost);
		}
		/* Floyd-Warshall All Pairs Shortest Path */
		for(int k = 1; k < cities; ++k)
			for(int i = 1; i < cities; ++i)
				for(int j = 1; j < cities; ++j)
					m[i][j] = min(m[i][j], m[i][k] + m[k][j]);
		/* Compute answer */
		int ans = 0, origin = q[0];
		for(int i = 1; i < c; ++i)
			ans += m[origin][q[i]] + m[q[i]][origin];
		/* Show case number followed by answer */
		printf("%d. %d\n", ++cnum, ans);
	}
	return 0;
}

