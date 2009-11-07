#include <cstdio>
#include <cstring>
#include <algorithm>
#define NN 300
#define MAX(a,b) (((a)>(b))?(a):(b))
using namespace std;
bool v[NN], inpath[NN];
int adj[NN][NN], deg[NN], p[NN], leaf[NN];
int fes[2*NN+1], freq[2*NN+1], LCSPATH[2*NN+1];
int fnum, num_leaf, path_size, pty_togo;
void dfs(int k){
	v[k] = 1;
	int sons = 0, x;
	for(int w = 0; w < deg[k]; w++){
		x = adj[k][w];
		if(!v[x]) p[x] = k, sons++, dfs(x);
	}
	if(!sons) leaf[num_leaf++] = k;
}
int LCS(){
	int i, j, x = fnum+1, y = path_size+1;
	int *frq = freq -1 , *pth = LCSPATH - 1, *pty = fes - 1 ;
	int LCS[x][y];
	for(i = 0; i < x; i++) LCS[i][0] = 0;
	for(j = 0; j < y; j++) LCS[0][j] = 0;
	for(i = 1; i < x; i++)
		for(j = 1; j < y; j++){
			if(pty[i] == pth[j]) LCS[i][j] = LCS[i-1][j-1]+frq[i];
			else LCS[i][j] = MAX(LCS[i-1][j],LCS[i][j-1]);
		}
	return LCS[x-1][y-1];
}
int main(void){
	int a, b, c, f, i, j, k, max;
	for(int t = 1; scanf("%d%d",&c,&f) && c; t++){
		memset(v,0,c);
		memset(deg,0,(c<<2));
		memset(p,-1,(c<<2));
		memset(inpath,0,c);
		for(i = 1; i < c; i++){
			scanf("%d%d",&a,&b);
			adj[--a][deg[a]++] = --b;
			adj[b][deg[b]++]= a;
		}
		for(fnum = i = 0;i < f; i++){			
			scanf("%d",&a);
			--a;
			if(fnum && a == fes[fnum-1])
				freq[fnum-1]++;
			else fes[fnum] = a, freq[fnum++] = 1;
		}
		num_leaf = 0;
		dfs(0);
		for(max = i = 0; i < num_leaf; i++){
			int novo;
			b = leaf[i]; path_size = 0;
			while(b != -1) {
				inpath[b] = 1;
				LCSPATH[path_size++] = b;
				b = p[b];
			}
			reverse(LCSPATH,LCSPATH+path_size);
			for(j = 1; j < path_size; j++) 
				LCSPATH[path_size+j-1] = LCSPATH[path_size-j-1];
			path_size = (path_size<<1)-1;
			//for(j = 0; j < path_size; j++) printf(" %d",LCSPATH[j]);
			//putchar('\n');
			/* DO LCS */
			novo = LCS();
			/* CLEAR PATH */
			for(j = 0; j < path_size; j++) inpath[LCSPATH[j]] = 0;
			max = MAX(max,novo);
		}
		printf("Teste %d\n%d\n\n",t,max);
	}
	return 0;
}

