#include <cstdio>

#define NN 100
#define INF 0x40000000
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))

struct edge { int a, b, c; };
int D, E, N, S, v[NN];
edge e[NN*NN];
int bellman_ford(){
	int i, j;
	for(i = 0; i < N; i++) v[i] = 0;
	v[S] = INF;
	for(i = 0; i < N; i++)
		for(j = 0; j < E; j++){
			v[e[j].b] = MAX(MIN(e[j].c, v[e[j].a]), v[e[j].b]);
			v[e[j].a] = MAX(MIN(e[j].c, v[e[j].b]), v[e[j].a]);
		}
	return v[D]-1;
}	
int main(void){
	int i, k, T;
	for(int sc = 1; scanf("%d%d",&N,&E) && N; sc++){
		for(i = 0; i < E; i++) 
			scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].c), --e[i].a, --e[i].b;
		scanf("%d%d%d",&S,&D,&T);
		--S, --D;
		k = bellman_ford();
		printf("Scenario #%d\nMinimum Number of Trips = %d\n\n",sc,(k-1+T)/k);
	}
	return 0;
}
