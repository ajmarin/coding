#include <cstdio>
#include <cstring>

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define INF 1077952576
int v[201], mt[201][201], N;
struct node {
	int v, n;
	node *next;
} n[201];
int slash(int l, int r){
	if((r > l) && (r - l) < 2) mt[l][r] = 0;
	else if((r < l) && (N - l + r) < 2) mt[l][r] = 0;
	int temp, p1, p2;
	if(mt[l][r] == INF) 
		for(int x = l+1; x != r; x++){
			if(x > N){ x -= N+1; if(x == r) break; }
			if(x > l) p1 = v[x] - v[l];
			else p1 = v[N] - v[l] + v[x];
			if(x < r) p2 = v[r] - v[x];
			else p2 = v[N] - v[x] + v[r];
			temp = MAX(p1,p2) +	slash(l,x) + slash(x,r);
			mt[l][r] = MIN(mt[l][r],temp);
		}
	return mt[l][r];
}
int main(void){
	int i, min, p, x;
	double TF;
	while(scanf("%d %lf",&N,&TF) && N){
		memset(mt,1<<6,sizeof(mt));
		min = 1000000; p = 0;
		for(i = 1; i <= N; i++) scanf("%d",&x), p += x, v[i] = p;
		for(i = 0; i < N; i++){
			if(i) p = slash(i-1,(N+i)%(N+1));
			else p = slash(0,N);
			if(p < min) min = p;
		}
		printf("%.2lf\n",min*TF);
	}
	return 0;
}
		
