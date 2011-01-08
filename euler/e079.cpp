#include <cmath>
#include <cstdio>
#include <ctime>
char d[16];
bool adj[10][10], app[10];
int deg[10], q[10];
int main(void){
	clock_t ini = clock();
	long long ans = 0;
	int t = 0;
	freopen("keylog.txt", "r", stdin);
	for(int i = 0; i < 10; ++i){
		app[i] = 0;
		for(int j = 0; j < 10; ++j) adj[i][j] = 0;
	}
	while(scanf("%s", d) == 1){
		for(int i = 0; i < 3; ++i) d[i] -= '0';
		adj[d[0]][d[1]] = adj[d[0]][d[2]] = adj[d[1]][d[2]] = 1;
		app[d[0]] = app[d[1]] = app[d[2]] = 1;
	}
	for(int i = 0; i < 10; ++i){
		if(!app[i]) continue;
		deg[i] = 0;
		for(int j = 0; j < 10; ++j) deg[i] += adj[j][i];
		if(!deg[i]) q[t++] = i;
	}
	for(int i = 0; i < t; ++i){
		int k = q[i];
		ans = ans * 10 + k;
		for(int j = 0; j < 10; ++j)
			if(adj[k][j] && --deg[j] == 0) q[t++] = j;
	}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %lld\n", ans);
	return 0;
}

