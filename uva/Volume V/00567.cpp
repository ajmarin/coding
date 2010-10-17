#include <cstdio>
#define ABS(a)		((a)< 0?-(a):(a))
#define ALL(x)		x.begin(), x.end()
#define ALLI(x,n)	x, x+n
#define FORI(a,b,c)	for(int a = b; a < c; ++a)
#define FOR(a,b)	FORI(a,0,b)
#define GETI(a)		scanf("%d",&a)
#define GETS(a)		scanf("%s",a)
#define GETL(a) 	fgets(a, sizeof(a), stdin)
#define IN(x) 		x = getc( stdin )
#define MAX(a,b)	((a)>(b)?(a):(b))
#define MIN(a,b) 	((a)<(b)?(a):(b))
#define OUT(x)		putc(x, stdout)
#define SQR(x)		((x) * (x))
#define TR(x) 		for(typeof(x.begin())it=x.begin();it!=x.end();++it)

int adj[32][32];
int min(int x, int y){ return x < y ? x : y; }
int main(void){
	for(int c, f, t, ts = 0; scanf("%d", &c) == 1; ){
		FOR(i, 32) FOR(j, 32) adj[i][j] = 1000;
		FORI(i, 1, 20){
			FOR(j, c){
				scanf("%d", &t);
				adj[i][t] = adj[t][i] = 1;
			}
			scanf("%d", &c);
		}
		FORI(k, 1, 21) FORI(i, 1, 21) FORI(j, 1, 21) 
			adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
		printf("Test Set #%d\n", ++ts);
		FOR(i, c) 
			scanf("%d %d", &f, &t), printf("%2d to %2d: %d\n", f, t, adj[f][t]);
		putc(10, stdout);
	}
	return 0;
}

