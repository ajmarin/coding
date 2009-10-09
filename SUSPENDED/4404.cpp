#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

char women[32][32];
char names[2048];

map < string, int > man_map;
map < string, int > wom_map;


/* {{{ Hopcroft-Karp */
#define tr(x) for(typeof(g[x].begin())it = g[x].begin(); it != g[x].end(); it++)
#define NN 32
#define DEBUG
int dx[NN], dy[NN], py[NN], q[NN];
vector <int> g[NN];

struct MAN {
	char name[32];
	int p;
	bool operator<(const MAN x) const {
		return (strcmp(name,x.name) < 0);
	}
}men[32];
bool BFS(int n, int m){
	bool f = 0;
	int i, h = 0, t = 0;
	memset(dx,0,n<<2);
	memset(dy,0,m<<2);
	for(i = 0; i < n; i++) if(men[i].p == -1) q[t++] = i;
	while(h < t){
		int x = q[h++];
		tr(x) if(!dy[(*it)]){
			dy[(*it)] = dx[x] + 1;
			if(py[(*it)] == -1) f = 1;
			else dx[py[(*it)]] = dy[(*it)]+1, q[t++] = py[(*it)];
		}
	}
	return f;
}
bool DFS(int x){
	tr(x) if(dy[(*it)] == dx[x]+1){
		dy[(*it)] = 0;
		if(py[(*it)] == -1 || DFS(py[(*it)]))
			return men[x].p = (*it), py[(*it)] = x, true;
	}
	return false;
}
int hopcroft_karp(int n, int m){
	int i, mm = 0;
	for(int i = 0; i < n; ++i) men[i].p = -1;
	memset(py,-1,m<<2);
	while(BFS(n, m))
		for(i = 0; i < n; i++)
			mm += (men[i].p == -1 && DFS(i));
	return mm;
}
/* }}} */
int main(void){
	int T, N;
	scanf("%d\n",&T);
	for(int cnum = 0; cnum < T; ){
		scanf("%d\n",&N);
		printf("Case %d:\n",++cnum);
		man_map.clear();
		wom_map.clear();
		for(int i = 0; i < N; ++i) {
			scanf("%s",men[i].name);
			man_map[string(men[i].name)] = i;
			g[i].clear();
		}
		for(int i = 0; i < N; ++i){
			scanf("%s",women[i]);
			wom_map[string(women[i])] = i;
		}
		char c;
		while(!isalpha(c = getc( stdin )));
		ungetc( c, stdin);
		for(int i = 0; i < N; ++i){
			fgets(names, 2048, stdin);
			names[strlen(names) - 1] = 0;
			char *ptr = strtok(names," :\r\n");
#ifdef DEBUG
			printf("%s likes ->",ptr);
#endif
			int man_n = man_map[string(ptr)];
			ptr = strtok(NULL, " :\r\n");
			while(ptr != NULL){
#ifdef DEBUG
				printf("%s ",ptr);
#endif
				g[man_n].push_back(wom_map[string(ptr)]);
				ptr = strtok(NULL, " :\r\n");
			}
#ifdef DEBUG
			printf("\n");
#endif
		}
		int x = hopcroft_karp(N,N);
		if(x == N){
			sort(men,men+N);
			for(int i = 0; i < N; ++i){
				if(i) putc(' ',stdout);
				printf("%s %s",men[i].name,women[men[i].p]);
			}
			printf("\n");
		} else printf("No Way\n");

	}
	return 0;
}

