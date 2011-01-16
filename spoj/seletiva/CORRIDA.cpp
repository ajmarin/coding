#include<cstdio>
#define min(a,b) ((a<b)?(a):(b))
int m[128][128][2];
int i, j, k, roads, smallest, t, tour, x, weight, y;
int main(void){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&tour,&roads);
		tour++;
		for(i = 1; i < tour; i++)
			for(j = 1; j < tour; j++)
				m[i][j][0] = m[i][j][1] = 
				m[j][i][0] = m[j][i][1] = (1<<17);
		for(i = 0; i  < roads; i++){
			scanf("%d%d%d",&x,&y,&weight);
			m[x][y][1] = m[y][x][1] = weight;			
		}
		for(k = 1; k < tour; k++)
			for(i = 1; i < tour; i++)
				for(j = 1; j < tour; j++){
					int imp1 = m[i][k][1]+m[k][j][0];
					int imp2 = m[i][k][0]+m[k][j][1];
					int p1 = m[i][k][1]+m[k][j][1];
					int p2 = m[i][k][0]+m[k][j][0];
					m[i][j][1] = min(m[i][j][1],min(imp1,imp2));
					m[i][j][0] = min(m[i][j][0],min(p1,p2));
				}
		smallest = 1<<17;
		for(i = 1; i < tour; i++)
			if(smallest > m[i][i][1]) smallest = m[i][i][1];
		if(smallest < (1<<17)) printf("%d\n",smallest);
		else puts("impossivel");		
	}
	return 0;
}
