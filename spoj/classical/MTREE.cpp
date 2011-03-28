#include <cctype>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long LL;
const LL M = 1000000007;
const int N = 100048;
vector < pair< int, int > > adj[N];
LL memo[N], weight = 0;
LL dfs(int k, int p){
	LL r = 0; int sz = adj[k].size();
	for(int i = 0; i < sz; ++i){
		int to = adj[k][i].first, w = adj[k][i].second;
		if(to != p) r = (r + w * (1 + dfs(to, k))) % M;
	}
	return memo[k] = r;
}
void doval(int k, int p, LL w){
	LL &r = memo[k];
	r = (r + w * (1 + memo[p] + M - (w * (r + 1)) % M)) % M;
	weight = (weight + r) % M;
	int sz = adj[k].size();
	for(int i = 0; i < sz; ++i){
		int to = adj[k][i].first, cost = adj[k][i].second;
		if(to != p) doval(to, k, cost);
	}
}
/* Reading integers */
const int MAX = 4096;
char buf[MAX], *lim = buf + MAX, *now = lim;
void readint(int &n){	
	while(now != lim && !isdigit(*now)) now++;
	if(now == lim){
		int r = fread(buf, 1, MAX - 1, stdin);
		buf[r] = 0;
		lim = buf + r - 1;
		while(isdigit(*lim)) ungetc(*lim--, stdin);
		now = buf;
	}
	while(!isdigit(*now)) now++;
	for(n = 0; isdigit(*now); n = (n << 1) + (n << 3) + *now++ - '0');
}
int main(void){
	int a, b, n, w; readint(n);
	for(int i = 1; i < n; ++i){
		readint(a); readint(b); readint(w);
		adj[a].push_back(make_pair(b, w));
		adj[b].push_back(make_pair(a, w));
	}
	memo[0] = 0;
	dfs(1, 0);
	doval(1, 0, 0);
	weight = (weight * 500000004) % M;
	printf("%lld\n", weight);
	return 0;
}

