#include <cstdio>
#include <ctime>

const int INF = 1 << 28, SZ = 80;
int m[SZ][SZ], r[SZ][SZ];
bool v[SZ][SZ];
int min(int a, int b){ return a < b ? a : b; }
int main(void){
	clock_t ini = clock();	
	int ans = -1;
	freopen("matrix.txt", "r", stdin);
	for(int i = 0; i < SZ; ++i)
		for(int j = 0; j < SZ; ++j){
			scanf("%d%*c", &m[i][j]);
			v[i][j] = 0;
			r[i][j] = INF;
		}
	r[0][0] = 0;
	while(true){
		int x, y, z = INF;
		for(int i = 0; i < SZ; ++i)
			for(int j = 0; j < SZ; ++j)
				if(!v[i][j] && r[i][j] < z){
					z = r[i][j];
					x = i;
					y = j;
				}
		if(z == INF) break;
		v[x][y] = 1;
		if(y == SZ - 1 && x == SZ - 1){
			ans = r[x][y] + m[x][y];
			break;
		}
		if(y)			r[x][y - 1] = min(r[x][y - 1], r[x][y] + m[x][y]);
		if(y < SZ - 1)	r[x][y + 1] = min(r[x][y + 1], r[x][y] + m[x][y]);
		if(x)			r[x - 1][y] = min(r[x - 1][y], r[x][y] + m[x][y]);
		if(x < SZ - 1)	r[x + 1][y] = min(r[x + 1][y], r[x][y] + m[x][y]);
	}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}
