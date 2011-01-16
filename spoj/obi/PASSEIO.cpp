#include <cstdio>
#include <algorithm>
bool adj[150][150];
int max[150];
struct PT{
	int h, n;
	bool operator()(PT a, PT b){
		return (a.h < b.h);
	}
} p[150];
int visit(int k){
	if(max[k]) return max[k];
	for(int x = k-1; x >= 0; x--)
		if(p[x].h < p[k].h && adj[p[k].n][p[x].n]){
			int test = visit(x)+1;
			if(test > max[k]) max[k] = test;
		}
	return max[k];
}
int main(void){
	int A, i, j, L, P;
	for(int t = 1; scanf("%d%d%d",&P,&L,&A) && P; t++){
		A--;
		for(i = 0; i < P; i++){
			scanf("%d",&p[i].h);
			p[i].n = i; max[i] = 0;
			for(j = 0; j < P; j++) adj[i][j] = 0;
		}
		for(i = 0; i < L; i++){
			int a, b;
			scanf("%d%d",&a,&b);
			adj[--a][--b] = p[a].h > p[b].h;
		}
		std::sort(p,p+P,PT());
		for(i = 0; i < P; i++)
			if(p[i].n == A) break;
		printf("Teste %d\n%d\n\n",t,visit(i));
	}
	return 0;
}
