#include<cstdio>
#include<algorithm>
using namespace std;
int c, i, n;
int x[2000],y[2000],d1[2000],d2[2000];
int eq,max_bloons;
void dofor(int k[]){
	sort(k,k+n);
	//printf("Sorted\n");
	for(i = 1; i < n; i++){
		eq = 1;
		while(i < n && k[i] == k[i-1]) eq++, i++;
		if(eq > max_bloons) max_bloons = eq;
	}
}
int main(void){
	scanf("%d",&c);
	while(c--){
		scanf("%d",&n);
		max_bloons = 1;
		for(i = 0; i < n; i++){
			scanf("%d %d",&x[i],&y[i]);
			d1[i] = x[i]-y[i];
			d2[i] = x[i]+y[i];
		}
		//printf("Read\n");
		dofor(x);
		//printf("Done for x\n");
		dofor(y);
		//printf("Done for y\n");
		dofor(d1);
		//printf("Done for d1\n");
		dofor(d2);
		//printf("Done for d2\n");
		printf("%d\n",max_bloons);
	}
	return 0;
}
			
