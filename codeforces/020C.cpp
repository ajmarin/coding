#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define FOR(i,e)		for(int i = 0; i < e; ++i)
#define FORD(i,s,e)		for(int i = s; i > e; --i)
#define FOREACH(i,s,e)	for(typeof(s) i = s; i != e; ++i)
#define FORI(i,s,e)		for(int i = s; i < e; ++i)
#define IN(x)			(x = getc(stdin))
#define OUT(x)			putc(x, stdout)
template <class _T> _T MAX(_T a, _T b){ return a > b ? a : b; }
template <class _T> _T MIN(_T a, _T b){ return a < b ? a : b; }
const int N = 100048;
vector < pii > adj[N];
long long c[N];
priority_queue< pair <long long, int> > q;
int p[N], n;
void dijkstra(int s, int t){
	FOR(i, n) c[i] = 1LL<<60, p[i] = -1;
	q.push(make_pair(c[s] = 0, s));
	while(!q.empty()){
		int x = q.top().second;
		long long cost = -q.top().first;
		q.pop();
		if(cost > c[x]) continue;
		if(x == t) break;
		FOREACH(it, adj[x].begin(), adj[x].end()){
			int to = it->first;
			long long w = it->second;
			if(c[to] > c[x] + w){
				q.push(make_pair(-(c[to] = c[x] + w), to));
				p[to] = x;
			}
		}
	}
}
void show_path(int x, int t){
	if(x == -1) return;
	show_path(p[x], t);
	printf("%d%c", x + 1, x != t ? ' ' : '\n');
}
int main(void){
	int a, b, m, w; scanf("%d %d", &n, &m);
	FOR(i, m){
		scanf("%d %d %d", &a, &b, &w); --a; --b;
		adj[a].push_back(make_pair(b, w));
		adj[b].push_back(make_pair(a, w));
	}
	dijkstra(0, n - 1);
	if(c[n - 1] == 1LL<<60) puts("-1");
	else show_path(n-1, n-1);
	return 0;
}

