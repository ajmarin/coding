#include <cstdio>
#include <cstring>
#include <vector>
#include <cctype>

using namespace std;

#define IN getc( stdin ) 
struct edge {
	int d, v;
	edge(int _d, int _v):d(_d),v(_v){}
};
vector < edge > adj[500050];
int deg[500050], q[500050], nv[500050];
void fastint( register int *n ){
	register char c, p;
	bool neg = 0;
	*n = 0;
	c = getc( stdin );
	while(!isdigit(c)) p = c, c = IN;
	do {
		(*n) *= 10; (*n) += ( c - '0' );
		c = IN;
	} while(isdigit(c));
	if(p == '-') (*n) *= -1;
}
int main(void){
	int h, maxval, p, t, x, N;
	while(scanf("%d\n",&N) && N){
		for(int i = 0; i < N; ++i){
			adj[i].clear();
			deg[i] = 0;
			nv[i] = 0;
		}
		for(int i = 1; i < N; ++i){
			fastint(&x), fastint(&p);
			deg[x]++;
			adj[i].push_back(edge(x,p));
		}
		h = maxval = t = 0;
		for(int i = 0; i < N; ++i) q[t] = i, t += (!deg[i]);
		while(h != t){
			int x = q[h++];
			vector < edge > :: iterator it;
			for(it = adj[x].begin(); it != adj[x].end(); it++){
				int w = (*it).d;
				int val = nv[x] + (*it).v, mm = val + nv[w];
				if(mm > maxval) maxval = mm;
				if(val > nv[w]) nv[w] = val;
				q[t] = w;
				t += !--deg[w];
			}
		}
		printf("%d\n",maxval);

	}
	return 0;
}

