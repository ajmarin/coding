#include <cassert>
#include <cmath>
#include <cstdio>
#include <queue>
using namespace std;
#define FOR(i,n)	for(int i = 0; i < n; ++i)
const int INF = 0x3FFFFFFF, NN = 205;

int cap[NN][NN], flow[NN][NN], p[NN], q[NN], x[NN], y[NN];
int n;

struct edge { int d, w; edge(int _d = 0, int _w = 0): d(_d), w(_w) {} };

void show_path(int x){
	if(x == -1) return;
	show_path(p[x]);
	printf("%d -> ", x);
}
int max_flow(int s, int t){
	int at, capacity, next, r = 0;
	FOR(i, n) FOR(j, n) flow[i][j] = 0;
	while(true){
		FOR(i, n) p[i] = -1;
		int head(0), tail;
		int begin, end;
		q[(tail = 0)++] = s;
		while(head != tail){
			at = q[head++];
			if(!at || at > n>>1) begin = 1, end = (n>>1) + 1;
			else begin = (n>>1) + 1, end = n;
			for(next = begin; next < end; ++next)
				if(p[next] == -1 && cap[at][next] - flow[at][next] > 0){
					q[tail++] = next;
					p[next] = at;
					if(next == t) break;
				}
			if(next == t) break;
		}
		if(head == tail) break;
		for(capacity = INF, at = t; p[at] != -1 && at != s; at = p[at])
			capacity = min(capacity, cap[p[at]][at] - flow[p[at]][at]);
		for(at = t; at != s; at = p[at]){
			flow[p[at]][at] += capacity;
			flow[at][p[at]] -= capacity;
		}
		r += capacity;
	}
	return r;
}

int sqr(int x){ return x * x; }

int main(void){
	int T; scanf("%d", &T);
	for(double D; T-- && scanf("%d %lf", &n, &D) == 2; ){
		int f(n), total_penguins(0);
		n = 2*n + 1;
		FOR(i, n) FOR(j, n) cap[i][j] = 0;
		for(int i = 1; i <= f; ++i){
			int penguins, res;
			scanf("%d %d %d %d", &x[i], &y[i], &penguins, &res);
			total_penguins += penguins;
			// source to floater
			cap[0][i] = penguins;
			// node i in to node i out
			cap[i][i+f] =  res;
			for(int j = 1; j < i; ++j){
				int dist = sqr(x[j] - x[i]) + sqr(y[j] - y[i]);
				if(sqrt(dist) < D + 1e-9){
					// i out to j in
					cap[i + f][j] = INF;
					// j out to i in
					cap[j + f][i] = INF;
				}
			}
		}
		int list[f], top = 0;
		for(int i = 1; i <= f; ++i)
			if(max_flow(0, i) == total_penguins)
				list[top++] = i - 1;
		for(int i = 0; i < top; ++i)
			printf("%d%c", list[i], i == top - 1 ? '\n' : ' ');
		if(!top) puts("-1");
	}
	return 0;
}

