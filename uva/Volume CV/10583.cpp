#include <cstdio>
#include <cstring>
#include <cctype>

#define NN 500050
#define IN getc( stdin )

int p[NN];

void fastint( register int *n ){
	register char c = IN;
	*n = 0;
	while(!isdigit(c)) c = IN;
	do { (*n) = (*n) * 10 + (c - '0'); c = IN; }
	while(isdigit(c));
}
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
			fastint(&A), fastint(&B);
			if(union_find(A,B)) --N;
		}
		printf("Case %d: %d\n", ++C, N);
	}
	return 0;
}

