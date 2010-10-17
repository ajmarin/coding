#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>

using namespace std;

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

struct edge {
	int a, b, c;
	bool operator<(const edge x) const {
		return c > x.c;
	}
} e[20000];
int cc, p[256];
map < string, int > m;
int add(const char *city){
	string s = string(city);
	if(m.count(s)) return m[s];
	return m[s] = cc++;
}
int find(int x){
	return p[x] == -1 ? x : p[x] = find(p[x]);
}
bool unionfind(int x, int y){
	int xr = find(x), yr = find(y);
	if(xr == yr) return 0;
	p[yr] = xr;
	return 1;
}
int main(void){
	char c1[64], c2[64];
	for(int n, r, sc = 0; scanf("%d %d", &n, &r) == 2 && (n || r); ){
		int cost;
		cc = 0;
		m.clear();
		FOR(i, n) p[i] = -1;
		FOR(i, r){
			scanf("%s %s %d", c1, c2, &cost);
			e[i].a = add(c1); e[i].b = add(c2); e[i].c = cost;
		}
		sort(e, e + r);
		scanf("%s %s", c1, c2);
		int ans = 10000, s = add(c1), t = add(c2);
		for(int i = 0; find(s) != find(t); ++i) 
			if(unionfind(e[i].a, e[i].b)) ans = e[i].c;
		printf("Scenario #%d\n%d tons\n\n", ++sc, ans);
	}
	return 0;
}

