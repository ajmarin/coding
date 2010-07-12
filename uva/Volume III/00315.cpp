/////////////////////////////////
// 00315 - Network
/////////////////////////////////
#include<cstdio>
#include<cstring>
#define min(a,b) (a<b?a:b)
unsigned char art[101],crit,i,j,low[101],n,reach[101][101],test,time,vn[101],x,y;
void Art(register unsigned char v, register unsigned char u){
	low[v] = vn[v] = time = time+1;
	for (register unsigned char w = 1; w <= n; w++)
		if(reach[v][w]){
			if (vn[w]) low[v] = min(low[v],vn[w]);
			else {
				Art(w, v);
				low[v] = min(low[v],low[w]);
				if(!art[v] && ((vn[v] == 1 && vn[w] != 2)||(vn[v] != 1 && low[w] >= vn[v]))) {
					art[v] = 1;
					crit++;
				}
			}
		}
}
int main(void){
	while(scanf("%hu\n",&n)!=EOF && n){
		crit = time = 0;
		memset(reach,0,sizeof(unsigned char)*10201);
		memset(art,0,sizeof(unsigned char)*101);
		memset(low,0,sizeof(unsigned char)*101);
		memset(vn,0,sizeof(unsigned char)*101);
		while(scanf("%hu%c",&x,&test) && x) 
			while(test!='\n'){
				scanf("%hu%c",&y,&test);
				reach[x][y] = reach[y][x] = 1;
			}
		Art(1,0);	
		printf("%hu\n",crit);
	}
	return 0;
}
