#include <cstdio>
#include <map>
#include <vector>
#include <cstring>
#include <string>
#define NN 30
#define MIN(a,b) ((a<b)?(a):(b))
using namespace std;
map < string , int > m;
int adj[30][30], ans[30], ansp, deg[30], n, r[30];
char name[30][32];
bool v[30];
void TOPOSORT(int k){
	ans[ansp++] = k;
	v[k] = 1;
	for(int w = 0; w < deg[k]; w++){
		int x = adj[k][w];
		if(!v[x] && --r[x] == 0) TOPOSORT(x);
	}
}
int main(void){
	int a, b, i, j, rest;
	char naame[32];
	for(int t = 1; scanf("%d",&n) && n; t++){
		printf("Teste %d\n",t);
		m.clear();
		memset(deg,0,sizeof(int)*n);
		memset(adj,0,sizeof(adj));
		memset(v,0,n);
		for(i = 0; i < n; i++){
			scanf("%s",&name[i]);
			m[string(name[i])] = i;
			deg[i] = 0;
		}
		for(i = 0; i < n; i++){
			scanf("%s %d",&naame,&rest);
			a = m[string(naame)];
			r[a] = rest;
			for(j = 0; j < rest;  j++)
				scanf("%s",&naame),
				b = m[string(naame)],
				adj[b][deg[b]++] = a;
		}
		ansp = 0;
		for(i = 0; i < n; i++)
			if(r[i] == 0 && !v[i]) TOPOSORT(i);
		if(ansp == n){
			for(i = 0; i < n; i++)
				printf("%s ",name[ans[i]]);
		} else printf("impossivel");
		printf("\n\n");
	}
	return 0;
}

