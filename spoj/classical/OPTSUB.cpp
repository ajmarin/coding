#include <cstdio>
const int MAX = 4096, N = 1024;
int adj[N][4], deg[N], maxs, w[N], x[N], y[N];
bool v[N];
/* Reading integers */
bool isdigit(char a){ return (a >= '0' && a <= '9') || a == '-'; }
char buf[MAX], *lim = buf + MAX, *now = lim;
void readint(int &n){	
	while(now != lim && !isdigit(*now)) now++;
	if(now == lim){
		int r = fread(buf, 1, MAX - 1, stdin);
		buf[r] = 0;
		lim = buf + r - 1;
		now = buf;
		if(r == MAX - 1) while(isdigit(*lim)) ungetc(*lim--, stdin);
	}
	bool negative = false;
	while(!isdigit(*now)) now++;
	if(*now == '-') now++, negative = true;
	for(n = 0; isdigit(*now); n = (n << 1) + (n << 3) + *now++ - '0');
	if(negative) n = -n;
}
int dfs(int k){
	int r = w[k], sz = deg[k];
	v[k] = 1;
	for(int i = 0; i < sz; ++i){
		if(v[adj[k][i]]) continue;
		int x = dfs(adj[k][i]);
		if(x > 0) r += x;
	}
	return r;
}
int abs(int a){ return a < 0 ? -a : a; }
int max(int a, int b){ return a > b ? a : b; }
int main(void){
	int n, t; readint(t);
	while(t--){
		readint(n);
		for(int i = 0; i < n; ++i) deg[i] = v[i] = 0;
		for(int i = 0; i < n; ++i){
			readint(x[i]); readint(y[i]); readint(w[i]);
			for(int j = 0; j < i; ++j)
				if(abs(x[j] - x[i]) + abs(y[j] - y[i]) == 1){
					adj[i][deg[i]++] = j;
					adj[j][deg[j]++] = i;
				}
		}
		maxs = 0;
		for(int i = 0; i < n; ++i) maxs = max(maxs, dfs(i)); 
		printf("%d\n", maxs);
	}
	return 0;
}

