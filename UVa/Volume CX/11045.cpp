#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
const char *YYY = "YES", *NNN = "NO";
#define NN 64
/* {{{ Hopcroft-Karp */
#define tr(x) for(typeof(g[x].begin())it = g[x].begin(); it != g[x].end(); it++)

int dx[NN], dy[NN], px[NN], py[NN], q[NN];
vector <int> g[NN];

bool BFS(int n, int m){
	bool f = 0;
	int i, h = 0, t = 0;
	memset(dx,0,n<<2);
	memset(dy,0,m<<2);
	for(i = 0; i < n; i++) if(px[i] == -1) q[t++] = i;
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
			return px[x] = (*it), py[(*it)] = x, true;
	}
	return false;
}
int hopcroft_karp(int n, int m){
	int i, mm = 0;
	memset(px,-1,n<<2);
	memset(py,-1,m<<2);
	while(BFS(n, m))
		for(i = 0; i < n; i++)
			mm += (px[i] == -1 && DFS(i));
	return mm;
}
/* }}} */
int get_num(const char *p){
	if(p[0] == 'X'){
		if(p[1] == 'X') return 0;
		if(p[1] == 'L') return 1;
		return 5;
	}
	if(p[0] == 'L') return 2;
	if(p[0] == 'M') return 3;
	return 4;
}
int main(void){
	int i, j, x, N, M, T;
	char s1[5], s2[5], n1, n2;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&N,&M);
		for(i = 0; i < N; i++) g[i].clear();
		x = N/6;
		for(i = 0; i < M; i++){
			scanf("%s%s",s1,s2);
			n1 = x*get_num(s1);
			n2 = x*get_num(s2);
			for(j = 0; j < x; j++){
				g[n1+j].push_back(i);
				g[n2+j].push_back(i);
			}
		}
		hopcroft_karp(N,M)==M ? puts(YYY): puts(NNN);
	}
	return  0;
}
