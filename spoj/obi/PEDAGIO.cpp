#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int a, b, C, E, i, L, P, total;
int adj[50][200], ans[50], deg[50];
bool v[50];
queue < pair < int, int > > q;
int main(void){
	for(int t = 1; scanf("%d%d%d%d",&C,&E,&L,&P) && C; t++){
		total = 0;
		for(i = 0; i < C; i++) v[i] = deg[i] = 0;
		for(i = 0; i < E; i++){
			scanf("%d%d",&a,&b);
			adj[--a][deg[a]++] = --b;
			adj[b][deg[b]++] = a;
		}
		q.push(make_pair(L-1,0)); v[L-1] = 1;
		while(!q.empty()){
			int s = q.front().first, p = q.front().second;
			q.pop();
			if(p < P)
				for(i = 0; i < deg[s]; i++)
					if(!v[adj[s][i]]){
						int k = adj[s][i];
						q.push(make_pair(k,p+1));
						v[k] = 1;
						ans[total++] = k;
					}
		}
		std::sort(ans,ans+total);
		printf("Teste %d\n",t);
		for(i = 0; i < total; i++)
			printf("%d ",ans[i]+1);
		printf("\n\n");
	}
	return 0;
}
