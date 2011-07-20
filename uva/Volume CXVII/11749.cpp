#include <cctype>
#include <cstdio>
#define FOR(i,n)	for(int i = 0; i < n; ++i)
#define FORI(i,f,n)	for(int i = f; i < n; ++i)
/* {{{ FAST integer input */
#define X10(n)	((n << 3) + (n << 1))
#define RI		readint
const int MAXR = 65536;
char buf[MAXR], *lim = buf + MAXR - 1, *now = lim + 1;
bool adapt(){ // Returns true if there is a number waiting to be read, false otherwise
	while(now <= lim && !isdigit(*now)) ++now;
	if(now > lim){
		int r = fread(buf, 1, MAXR-1, stdin);
		buf[r] = 0;
		lim = buf + r - 1;
		if(r == MAXR - 1){
			while(isdigit(*lim)) ungetc(*lim--, stdin);
			if(*lim == '-') ungetc(*lim--, stdin);
		}
		now = buf;
	}
	while(now <= lim && !isdigit(*now)) ++now;
	return now <= lim;
}
bool readint(int& n){ // Returns true on success, false on failure
	if(!adapt()) return false;
	bool ngtv = *(now - 1) == '-';
	for(n = 0; isdigit(*now); n = X10(n) + *now++ - '0');
	if(ngtv) n = -n;
	return true;
}
/* }}} end FAST integer input */
const int MAXN = 512, MINPPA = 1<<31;
int adj[MAXN][MAXN], p[MAXN], cnt[MAXN];
int findroot(int x){
	return p[x] = p[x] == x ? x : findroot(p[x]);
}
void unionfind(int a, int b){
	int ra = findroot(a), rb = findroot(b);
	if(ra == rb) return;
	p[ra] = rb;
}
int max(int a, int b){ return a > b ? a : b; }
void swap(int &a, int &b){ int tmp = a; a = b; b = tmp; }
int main(void){
	int m, n;
	for(RI(n), RI(m); (m || n); RI(n), RI(m)){
		int a, ans = 0, b, maxppa = MINPPA, ppa;
		FOR(i, n) cnt[i] = 0, p[i] = i;
		FOR(i, n) FORI(j, i + 1, n) adj[i][j] = MINPPA;
		FOR(i, m){
			RI(a), RI(b), RI(ppa);
			--a; --b;
			if(a > b) swap(a, b);
			if(ppa > adj[a][b]){
				adj[a][b] = ppa;
				maxppa = max(maxppa, ppa);				
			}
		}
		FOR(i, n) FORI(j, i + 1, n) if(adj[i][j] == maxppa) unionfind(i, j);
		FOR(i, n) ans = max(ans, ++cnt[findroot(i)]);
		printf("%d\n", ans);
	}
	return 0;
}

