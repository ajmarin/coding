#include <cstdio>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>
using namespace std; 
#define LP(c,x) for(c=0;c<x;c++)
#define MIN(a,b) ((a)<(b)?(a):(b))
struct TASK {
	int v, n, d;
	vector < int > adj, gadj;
} t[1000];
vector < int > w[1000];
bool v[1000];
const char *sep = "*****";
void dfs(int x){
	v[x] = 1;
	vector < int > :: iterator it;
	for(it = t[x].gadj.begin(); it != t[x].gadj.end(); it++)
		if(!v[(*it)]) dfs((*it));  
}
void toposort(int a, int b, int k){
	int q[1000], tail = 0;
	t[a].d = MIN(t[a].d,b);
	t[a].v += k;
	v[a] = 1;
	vector < int > :: iterator it;
	for(it = t[a].adj.begin(); it != t[a].adj.end(); it++){
		int x = (*it);
		if(--t[x].n) t[x].d = MIN(t[x].d,t[a].d-1), t[x].v += t[a].v;
		else q[tail++] = x;
	}
	for(int i = 0; i < tail; i++)
		toposort(q[i],b-1,t[a].v);
}
bool ord(int a, int b){
	return(t[a].d < t[b].d);
}
int main(void){
	int i, j, s, x, y, DEP, E, T, WRK;
	while(scanf("%d %d",&T,&E) && T){
		puts(sep);
		for(i = 0; i < E; i++) w[i].clear();
		for(i = 0; i < T; i++){
			t[i].adj.clear();
			t[i].gadj.clear();
			v[i] = t[i].n = 0;
			t[i].d = 1111;
		}
		for(i = 0; i < T; i++){
			scanf("%d %d %d",&t[i].v,&DEP,&WRK);
			LP(j,DEP){
				scanf("%d",&x); --x;
				t[x].adj.push_back(i), t[i].n++;
				t[i].gadj.push_back(x);
			}
			LP(j,WRK) scanf("%d",&x), w[--x].push_back(i);
		}
		for(i = 0; i < T; i++)
			if(!v[i] && !t[i].n) toposort(i,1024,0);
		for(i = 0; i < E; i++){
			sort(w[i].begin(),w[i].begin()+w[i].size(),ord);
			memset(v,0,T);
			for(j = s = 0; j < w[i].size(); j++){
				if(v[w[i][j]]) continue;
				else dfs(w[i][j]);
				s += t[w[i][j]].v;
			}
			printf("%d %d\n",i+1,s);
		}
	}
	return 0;
}

