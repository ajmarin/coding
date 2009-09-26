#include<cstdio>
#include<cstring>
int lastexe[1000001], i, k, n, total;
int main(void){
	while(scanf("%d",&n) && n){
		memset(lastexe,-1,sizeof(lastexe));
		for(i = total = 0; i < n; i++){
			scanf("%d",&k);
			if(lastexe[k]!=-1) total += (i-lastexe[k]);
			else total += k+i;
			lastexe[k] = i;
		}
		printf("%d\n",total);
	}
	return 0;
}
