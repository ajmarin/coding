#include <cctype>
#include <cstdio>
#define IN getc(stdin)
const int N = 64;
const int M = 5000;
const char *ans[] = {"Valid", "Invalid"};
int adj[M][8], deg[M], v[M], vis;
int h[N][N], lines, w[N][N];
void add(int i, int j, bool v){
	int i1 = 60 * i + j, i2;
	if(v){
		i2 = i1 + 60;
		if(j) h[i][j - 1]++;		
	} else{
		i2 = i1 + 1;
		if(i) h[i - 1][j]++;
	}
	adj[i1][deg[i1]++] = i2;
	adj[i2][deg[i2]++] = i1;
	h[i][j]++;
	lines++;
}
void dfs(int x){
	v[x] = 1;
	vis++;
	for(int i = 0; i < deg[x]; ++i){
		int k = adj[x][i];
		if(!v[k]) dfs(k);
	}
}
int main(void){
	int c, col, r, row, t;
	bool fu;
	char in;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d\n", &r, &c);
		for(int i = 0; i < M; ++i) v[i] = 0, deg[i] = 0; 
		for(int i = 0; i < r; ++i)
			for(int j = 0; j < c; ++j)
				w[i][j] = -1, h[i][j] = 0;
		r = (r << 1) + 1;
		c = (c << 1) + 1;
		fu = lines = 0;
		for(int i = 0; i < r; ++i){
			for(int j = 0; j < c; ++j){
				in = IN;				
				if(in == '-' || in == '|') add(i >> 1, j >> 1, i & 1);
				if(isdigit(in)) w[i >> 1][j >> 1] = in - '0';
			}
			IN;
		}
		r >>= 1;
		c >>= 1;
		for(int i = 0; !fu && i < r; ++i)
			for(int j = 0; j < c; ++j)
				fu |= w[i][j] != -1 && h[i][j] != w[i][j];
		for(int i = 0; !fu && i < M; ++i){
			if(deg[i]){
				vis = 0;
				dfs(i);
				fu = vis != lines;
				break;
			}
		}
		puts(ans[fu]);
	}
	return 0;
}
