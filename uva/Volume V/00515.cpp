#include <cstdio>

const int INF = 1 << 30, NN = 256;
struct edge { int from, to, w; } e[NN];
int d[NN], ecnt;

void add_edge(int from, int to, int w){
	edge &E = e[ecnt++];
	E.from = from;
	E.to = to;
	E.w = w;
}

int main(void){
	char ord[8];
	d[0] = 0;
	for(int m, n; scanf("%d %d", &n, &m) == 2; ){
		++n;
		for(int a, b, w, i = ecnt = 0; i < m; ++i){
			scanf("%d %d %s %d", &a, &b, ord, &w);
			b += a + 1;
			if(*ord == 'g'){ // F(b) - F(a) > w
				// F(b) - F(a) >= w + 1 ==> F(a) - F(b) <= -w - 1
				add_edge(b, a, -w - 1);
			} else { // F(b) - F(a) < w ==> F(b) - F(a) <= w - 1
				add_edge(a, b, w - 1);
			}
		}
		for(int i = 1; i <= n; ++i){
			add_edge(0, i, 0);
			d[i] = INF;
		}
		for(int i = 1; i <= n; ++i)
			for(int j = 0; j < ecnt; ++j){
				int from = e[j].from, to = e[j].to;
				int temp = d[from] + e[j].w;
				if(temp < d[to]) d[to] = temp;
			}
		bool impossible = false;
		for(int j = 0; j < ecnt; ++j){
			int from = e[j].from, to = e[j].to;
			if(d[from] + e[j].w < d[to]) impossible = true;
		}
		puts(impossible ? "successful conspiracy" : "lamentable kingdom");
	}
	return 0;
}

