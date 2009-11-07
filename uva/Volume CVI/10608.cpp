#include <cctype>
#include <cstdio>
#include <vector>

using namespace std;

#define IN getc ( stdin )
#define MAX(a,b) ((a)>(b)?(a):(b))
#define NN 30050

vector < int > adj[NN];
int left;
bool v[NN];

void tni( register int *n ){
	register char c;
	while(!isdigit(c = IN));
	for(*n = 0; isdigit(c); c = IN) *n = *n * 10 + c - '0';
}
int dfs(int k){
	int f = 0;
	v[k] = 1;
	left--;
	vector < int > :: iterator it;
	for(it = adj[k].begin(); it != adj[k].end(); it++)
		if(!v[*it]) f += dfs(*it);
	return 1 + f;
}

int main(void){
	int a, b, i, max, x, M, N, T;
	tni(&T);
	while(T--){
		tni(&N); tni(&M); 
		left = N;
		for(i = 0; i < N; ++i) adj[i].clear(), v[i] = 0;
		for(i = 0; i < M; ++i){
			tni(&a), --a;
			tni(&b), --b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		for(i = max = 0; left > max; ++i)
			if(!v[i]) x = dfs(i), max = MAX(max, x);
		printf("%d\n",max);
	}
	return 0;
}

