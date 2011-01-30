#include <cstdio>
#define FOR(i,e)		for(int i = 0; i < e; ++i)
#define FORD(i,s,e)		for(int i = s; i > e; --i)
#define FOREACH(i,s,e)	for(typeof(s) i = s; i != e; ++i)
#define FORI(i,s,e)		for(int i = s; i < e; ++i)
#define IN(x)			(x = getc(stdin))
#define OUT(x)			putc(x, stdout)
template <class _T> _T max(_T a, _T b){ return a > b ? a : b; }
template <class _T> _T min(_T a, _T b){ return a < b ? a : b; }
const int N = 1024, INF = 0x3f3f3f3f;
int m2[N][N], m5[N][N]; char d2[N][N], d5[N][N];
void trace(int i, int j, char x[N][N]){
	if(i == 0 && j == 0) return;
	if(x[i][j] == 'D') trace(i - 1, j, x);
	else trace(i, j - 1, x);
	OUT(x[i][j]);
}
int main(void){
	int n, v, zx = -1, zy = -1; 
	scanf("%d", &n);
	FOR(i, n) FOR(j, n){
		int a2 = INF, a5 = INF;
		scanf("%d", &v);
		m2[i][j] = m5[i][j] = 0;
		if(!v) zx = i, zy = j;
		else {
			while(!(v & 1)) ++m2[i][j], v >>= 1;
			while(!(v % 5)) ++m5[i][j], v /= 5;
		}
		if(!i && !j) continue;
		if(i){
			a2 = m2[i - 1][j];
			a5 = m5[i - 1][j];
			d2[i][j] = d5[i][j] = 'D';
		}
		if(j){
			if(m2[i][j - 1] < a2) a2 = m2[i][j - 1], d2[i][j] = 'R';
			if(m5[i][j - 1] < a5) a5 = m5[i][j - 1], d5[i][j] = 'R';
		}
		m2[i][j] += a2;
		m5[i][j] += a5;
	}
	--n;
	int ans = min(m2[n][n], m5[n][n]);
	if(zx != -1 && ans > 0){
		puts("1");
		FOR(i, zx) OUT('D'); FOR(j, zy) OUT('R');
		FORI(i, zx, n) OUT('D'); FORI(j, zy, n) OUT('R');
	} else{
		printf("%d\n", ans);
		ans == m5[n][n] ? trace(n, n, d5) : trace(n, n, d2);
	}
	OUT(10);
	return 0;
}

