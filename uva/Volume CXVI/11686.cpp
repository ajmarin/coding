#include <cstdio>
#include <vector>
#include <cctype>

using namespace std;

#define tr(x) for(typeof(x.begin())it = x.begin(); it != x.end(); it++)
const int NN = 1000032;
vector < int > adj[NN];
int dep[NN], q[NN];
int h, t;
int M, N;

void toposort(){
	while(h != t){
		int x = q[h++];
		tr(adj[x]) if(--dep[(*it)] == 0) q[t++] = (*it);
	}
}
void fastint( register int *n ){
	register char c;
	*n = 0;
	while(!isdigit(c = getc( stdin )));
	do {
		(*n) = (*n)*10 + (c - '0');
	}while( isdigit( c = getc( stdin ) ));
}
int main(void){
	int a, b;

	while(scanf("%d%d",&N,&M) && N){
		h = t = 0;
		for(int i = 0; i < N; ++i) adj[i].clear(), dep[i] = 0;
		for(int i = 0; i < M; ++i){
			fastint(&a), fastint(&b);
			adj[--a].push_back(--b);
			dep[b]++;
		}
		for(int i = 0; i < N; ++i){
			if(dep[i] == 0) q[t++] = i;
		}
		toposort();
		if(t != N) puts("IMPOSSIBLE");
		else for(int i = 0; i < t; ++i) printf("%d\n",q[i]+1);
	}
	return 0;
}
