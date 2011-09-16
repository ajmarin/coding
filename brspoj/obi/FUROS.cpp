#include <cstdio>
#include <cmath>
int p[1000][2];
double dist[1000], max;
void updist(int x, int y){
	int xx, yy;
	xx = p[x][0] - p[y][0];
	yy = p[x][1] - p[y][1];
	double d = sqrt(xx*xx+yy*yy);
	if(d > dist[x]) dist[x] = d;
	if(d > dist[y]) dist[y] = d;
}
int main(void){
	int i, j, n, tnum = 1;
	while(scanf("%d",&n) && n){
		max = 9000000;
		for(i = 0; i < n; i++) dist[i] = 0;
		for(i = 0; i < n; i++){			
			scanf("%d%d",&p[i][0],&p[i][1]);
			for(j = i-1; j >= 0; j--)
				updist(i,j);
		}
		for(i = 0; i < n; i++)
			if(dist[i] < max) max = dist[i];
		printf("Teste %d\n%d\n\n",tnum++,(int)(ceil(max*2)+5));
	}
	return 0;
}
