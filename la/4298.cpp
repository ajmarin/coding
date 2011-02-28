#include <cmath>
#include <cstdio>
#define FOR(i,n)	for(int i = 0; i < n; ++i)
#define FORI(i,s,e)	for(int i = s; i < e; ++i)
const int N = 10;
int c[N][N];
double d[N][N];
int main(void){
	for(int n, nw, nz; scanf("%d", &n) == 1; ){
		double td = 0, w, z;
		long long new_paths, paths = 0;
		FOR(i, N) FOR(j, N) c[i][j] = d[i][j] = 0;
		FOR(i, n){
			scanf("%lf %lf", &w, &z);
			nw = floor(w), nz = floor(z);
			++c[nw][nz];
			d[nw][nz] += w + z - (nw + nz);
		}
		FORI(i, 1, N) FORI(j, 1, N) FOR(k, i) FOR(l, j){
			td += d[i][j] * c[k][l] - d[k][l] * c[i][j];
			paths += (new_paths = ((long long) c[i][j]) * c[k][l]);
			td += (i + j - k - l) * new_paths;
		}
		printf("%.8lf\n", td / paths);
	}
	return 0;
}

