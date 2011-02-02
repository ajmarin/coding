#include <cstdio>
#define FOR(i,e)		for(int i = 0; i < e; ++i)
#define FORI(i,s,e)		for(int i = s; i < e; ++i)
const int N = 24;
int sqr(int x){ return (x * x); }
int f(int x, int y){ return sqr(x) + sqr(y); }
int sc(int x){for(int r=0;;++r){if(!(x>>=1))return r+1;}}
int d[N][N], e[N], m[1<<N], p[1<<N], x[N], y[N]; 
int main(void){
	int n, ox, oy; scanf("%d %d %d", &ox, &oy, &n);
	FOR(i,n){
		scanf("%d %d", &x[i], &y[i]);
		e[i] = f(x[i] - ox, y[i] - oy);
		FOR(j,i) d[j][i] = f(x[i] - x[j], y[i] - y[j]);
	}
	FOR(i,(1<<n)) if(!i || m[i]){
		FOR(j,n) if(!(i & (1 << j))){
			int h = i | (1 << j), c = m[i] + (e[j] << 1);
			if(!m[h] || c < m[h]) m[h] = c, p[h] = i;
			FORI(k, j + 1, n) if(!(i & (1 << k))){
				h = i | (1 << j) | (1 << k);
				c = m[i] + e[j] + e[k] + d[j][k];
				if(!m[h] || c < m[h]) m[h] = c, p[h] = i;
			}
			break;
		}
	}
	int z = (1 << n) - 1;
	printf("%d\n", m[z]);
	while(z){
		printf("0 ");
		for(int r = z - p[z]; r; r &= r - 1) printf("%d ", sc(r & -r));
		z = p[z];
	}
	printf("0\n");
	return 0;
}

