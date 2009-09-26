#include <cstdio>
int T[10000], sum, tmin, tmax;
int main(void){
	int i, j, n, ts;
	for(int t = 1; scanf("%d %d",&n,&ts) && n; t++){
		tmin = (1<<25); tmax = -1<<25;
		for(i = 0; i < n; i++) scanf("%d",&T[i]);
		for(sum = i = 0; i < ts; i++) sum += T[i];
		for(i = 0, j = ts; j <= n; i++, j++){
			int mean = sum/ts;
			if(mean < tmin) tmin = mean;
			if(mean > tmax) tmax = mean;
			if(j == n) break;
			sum = sum + T[j] - T[i];
		}
		printf("Teste %d\n%d %d\n\n",t,tmin,tmax);
	}
	return 0;
}

