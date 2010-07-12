/////////////////////////////////
// 00821 - Page Hopping
/////////////////////////////////
#include<cstdio>
#include<cstring>
unsigned short int graph[101][101];
unsigned int cnum,i,j,k,m,max,n,nig,pathsum;
bool ingraph[101];
int main(void){
	while(scanf("%u %u",&m,&n) && m){
		cnum++;
		memset(graph,1500,sizeof(graph));
		memset(ingraph,0,sizeof(ingraph));
		pathsum = nig = max = 0;
		do{
			graph[m][n] = 1;
			ingraph[m] = 1;
			if(m > max) max = m;
		} while(scanf("%u %u",&m,&n) && m);
		max++;
		for(k = 1; k < max; k++)
			for(i = 1; i < max; i++){
				if(ingraph[i])
					for(j = 1; j < max; j++)
						if(ingraph[j] && graph[i][j] > graph[i][k]+graph[k][j])
							graph[i][j] = graph[i][k]+graph[k][j];
			}
		for(i = 1; i != max; i++){
			if(ingraph[i]){
				nig++;
				for(j = i+1; j != max; j++)
					if(ingraph[j]) pathsum += (graph[i][j]+graph[j][i]);
			}
		}
		nig = nig*(nig-1);
		printf("Case %u: average length between pages = %.3lf clicks\n",
			cnum,pathsum*1.000/nig);
	}
	return 0;
}
		
