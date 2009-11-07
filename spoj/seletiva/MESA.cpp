#include <cstdio>
#include <cstring>
int adj[100][100], color[100], deg[100];
int n;
void fastint( register int *n ){
	register char c;
	*n = 0;
	while( ( c = getc( stdin ) )){
		switch( c ){
			case ' ': case '\n': return;
			default: (*n) *= 10; (*n) += ( c - '0' ); break;
		}
	}
}
bool bip(int k){
	bool bicolorable = true;
	int c = color[k];
	for(int i = 0; bicolorable && i < deg[k]; i++){
		if(color[adj[k][i]] == -1)
			color[adj[k][i]] = 1-c, 
			bicolorable = bip(adj[k][i]);
		else if(color[adj[k][i]] == c){
			return 0;
		}
	}
	return bicolorable;
}
int main(void){
	int a, b, i, m;
	for(int cnum = 1; (scanf("%d%d\n",&n,&m) != EOF); cnum++){
		memset(deg,0,(n<<2));
		memset(color,-1,(n<<2));
		for(i = 0; i < m; i++){
			fastint(&a); fastint(&b);
			adj[--a][deg[a]++] = --b;
			adj[b][deg[b]++] = a;
		}
		printf("Instancia %d\n",cnum);
		color[0] = 1;
		if(bip(0)) printf("sim\n\n");
		else printf("nao\n\n");
	}
	return 0;
}

