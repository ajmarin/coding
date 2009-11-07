#include <cstdio>
#include <cstring>

#define MAX(a,b) ((a)>(b)?(a):(b))
const int NN = 100032;

int h[NN], height[NN], l[NN], p[NN], r[NN];

void ht(int i, int lh = 0, int rh = 0, int lth = 0, int rth = 0){
	int LH, RH;
	LH = (l[i] == -1)? 0 : h[l[i]];
	RH = (r[i] == -1)? 0 : h[r[i]];
	height[i] = MAX(MAX(1 + lh, 1 + rh),MAX(1 + lth + LH, 1 + rth + RH));
	if(l[i] != -1) ht(l[i], lh, MAX(rh, 1 + rth + RH), lth, 1 + rth);
	if(r[i] != -1) ht(r[i], MAX(lh, 1 + lth + LH), rh, 1 + lth, rth);
}
int dfs(int node){
	int h1, h2;
	h1 = h2 = 0;
	if(l[node] != -1) h1 = dfs(l[node]);
	if(r[node] != -1) h2 = dfs(r[node]);
	h[node] = 1 + MAX(h1, h2);
	return h[node];
}
int main(void){
	int N, root;
	while(scanf("%d",&N) && N){
		memset(p, -1, sizeof(p));
		for(int i = 0; i < N; ++i){
			int a, b;
			scanf("%d %d",&a,&b);
			if(a) p[a-1] = i;
			l[i] = --a;
			if(b) p[b-1] = i;
			r[i] = --b;
		}
		for(int i = 0; i < N; ++i) 
			if(p[i] == -1){ root = i; break; }
		dfs(root);
		ht(root);
		for(int i = 0; i < N; ++i) printf("%d\n",height[i]);
	}
	return 0;
}
