#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX(a,b) ((a)>(b)?(a):(b))

int ways[32][1050];
int v[32];
int T, V, M;
using namespace std;
int doDP(){
	if(v[0] > M) return 0;
	memset(ways,0,sizeof(ways));
	int LI, LS, r = 0, l = V-1;
	LI = MAX(M - 2*v[0] + 1, 0);
	LS = MAX(M - v[0], 0);
	for(int i = LI; i < LS; ++i)
		printf("%2d ",i);
	printf("\n");
	for(int i = 1; i < V; ++i){
		int k = v[i];
		for(int j = 0; j < M; ++j)
			if(ways[i-1][j]){
				int x = ways[i-1][j];
				int s = j + k;
				if(s >= LI && s < LS) printf("(%d) Created %d with %d + %d, %d\n",i, s,j,k,x);
				if(!ways[i][j]) ways[i][j] = x;
				else ways[i][j]++;
				if(s <= M) ways[i][s]++;
			}
		ways[i][k]++;
		for(int j = LI; j < LS; ++j)
			printf("%2d ",ways[i][j]);
		printf("\n");
	}
	printf("v[0] = %d\n",v[0]);
	for(int i = MAX(LI,0); i < MAX(LS,0); ++i){
		printf("\tCreated %d in %d ways\n",i,ways[l][i]);
		r += ways[l][i];
	}
	return r;
}
int main(void){
	scanf("%d",&T);
	for(int cnum = 0; cnum < T; ){
		scanf("%d%d",&V,&M);
		for(int i = 0; i < V; ++i) scanf("%d",&v[i]);
		sort(v, v+V);
		int ans = 0;
		for(int i = 0; i < V; ++i){
			swap(v[i],v[0]);
			ans += doDP();
			printf("Current ans = %d\n",ans);
		}
		printf("%d %d\n",++cnum,ans);
	}
	return 0;
}

