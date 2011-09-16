#include <cstdio>
#define max(a,b) ((a<b)?(b):(a))
int a, b, max_com, n;
bool adj[20][20], in[20];
int c[20];
void bt(int k, int cnum){
	if(k == n){
		max_com = max(max_com,cnum);
		return;
	}
	if(cnum + (n - k) < max_com) return;
	bool go = 1;
	for(int i = 0; go && i < cnum; i++) go = !adj[k][c[i]];
	if(go) c[cnum] = k, bt( k+1, cnum+1 );
	bt( k+1, cnum);	
}
int main(void){
	for(int t = 1; scanf("%d",&n) && n; t++){
		for(a = 0; a < n; a++)
			for(b = 0; b < n; b++) adj[a][b] = 0;
		for(a = 0; a < n; in[a] = 0, a++)
			while(scanf("%d",&b) && b--)
				adj[a][b] = adj[b][a] = 1;
		max_com = 0;
		bt(0, 0);
		printf("Teste %d\n%d\n\n",t,max_com);
	}
	return 0;
}
