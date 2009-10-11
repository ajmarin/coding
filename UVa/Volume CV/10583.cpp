#include <cstdio>
#include <cstring>

#define NN 500050

int p[NN];

bool union_find(int a, int b){
	int da, db;
	da = db = 0;
	while(p[a] != -1) a = p[a], da++;
	while(p[b] != -1) b = p[b], db++;
	if(a == b) return 0;
	if(da < db) p[a] = b;
	else p[b] = a;
	return 1;
}

int main(void){
	int A, B, C = 0, M, N;
	while(scanf("%d %d",&N,&M) && N){
		memset(p, -1, (N+1)<<2);
		while(M--){
			scanf("%d%d",&A,&B);
			if(union_find(A,B)) --N;
		}
		printf("Case %d: %d\n", ++C, N);
	}
	return 0;
}

