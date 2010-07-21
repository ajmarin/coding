#include <cctype>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
#define MAX 1048576
#define PB push_back
#define RINT readint
const int N = 10000;
char buf[MAX], *lim = buf + MAX, *now = lim;
void readint(int *n){	
	while(now != lim && !isdigit(*now)) now++;
	if(now == lim){
		int r = fread(buf, 1, MAX - 1, stdin);
		buf[r] = 0;
		lim = buf + r - 1;
		while(isdigit(*lim)) ungetc(*lim--, stdin);
		now = buf;
	}
	while(!isdigit(*now)) now++;
	*n = 0;	
	while(isdigit(*now)) *n = *n * 10 + *now++ - '0';
}
vector < int > adj[N];
bool imp[N];
int app[N], d[N], important, n, s;
bool v[N];
float bfs(int k){
	queue < int > q;
	float md = 0;
	int vimp = 1;
	for(int i = 0; i < n; ++i) v[i] = 0;
	q.push(k); d[k] = 0; v[k] = 1;	
	while(!q.empty()){
		int c = q.front(); q.pop();
		for(int i = 0; i < adj[c].size(); ++i){
			int x = adj[c][i];
			if(!v[x]){
				d[x] = d[c] + (v[x] = 1);
				if(imp[x]){
					md += d[x];
					if(++vimp == important) return md;
				}
				q.push(x);
			}
		}
	}
}
void inc(int x){ if(++app[x] == 2) important += imp[x] = 1; }
int main(void){
	int best, k, p, t; 
	RINT(&t);
	while(t--){
		important = 0;
		RINT(&n), RINT(&s);
		for(int i = 0; i < n; ++i) adj[i].clear(), app[i] = imp[i] = 0;
		for(int i = 0; i < s; ++i){
			RINT(&p); 
			--p; inc(p);
			while(1){
				RINT(&k);
				if(!k--) break;
				inc(k);
				adj[k].PB(p), adj[p].PB(k);
				p = k;
			}
		}
		int min = 1<<30;
		for(int i = 0; i < n; ++i)
			if(imp[i]){
				int temp = bfs(i);
				if(temp < min){
					min = temp;
					best = i;
				}
			}
		printf("Krochanska is in: %d\n", best + 1);
	}
	return 0;
}
