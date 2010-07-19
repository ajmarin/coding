#include <cctype>
#include <cstdio>
#include <ctime>
#include <unistd.h>
using namespace std;
const int M = 100030;
const int N = 10030;
int c[M], p[N], m, n;
struct edge {
	int c, f, t;
} e[M + N], *oe[M + N];
#define MAX 1048576
char buf[MAX], *lim = buf + MAX, *now = lim;
void readint(int *n){	
	while(now != lim && !isdigit(*now)) now++;
	if(now == lim){
		int r = fread(buf, 1, MAX, stdin);
		lim = buf + r - 1;
		while(isdigit(*lim)) ungetc(*lim--, stdin);
		now = buf;
	}
	while(!isdigit(*now)) now++;
	*n = 0;	
	while(isdigit(*now)) *n = *n * 10 + *now++ - '0';
}
void read_edges(){
	edge *ed = e + n - 1;
	int edges = m + n - 1;
	for(int i = 0; i < m; ++i){
		readint(&(ed->f)); readint(&(ed->t)); readint(&(ed->c));
		c[ed->c]++;
		ed++;
	}
	for(int i = 1; i < M; ++i) c[i] += c[i - 1];
	for(ed = e + edges - 1; ed >= e; ed--) oe[--c[ed->c]] = ed;
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
	clock_t ini = clock();
	int a, airports, connected, cost, t;
	readint(&t);
	
	for(int cnum = 1; cnum <= t; ++cnum){
		for(int i = 0; i < M; ++i) c[i] = 0;
		airports = cost = 0;
		connected = 1;
		readint(&n); readint(&m); readint(&a);
		++n;
		edge *ed = e;
		for(int i = 1; i < n; ++i){
			ed->f = i;
			ed->t = n;
			ed->c = a;
			p[i] = -1;
			ed++;
		}
		c[a] = n - 1;
		p[n] = -1;
		read_edges();
		int max = m + n - 1;
		for(int i = 0; i < max; i++){
			ed = oe[i];
			if(unionfind(ed->f, ed->t)){		
				cost += ed -> c;
				airports+= ed -> t == n;
				if(++connected == n) break;
			}
		}
		printf("Case #%d: %d %d\n", cnum, cost, airports);	
	}
	return 0;
}
