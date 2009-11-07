#include <cstdio>

int f,p,e,a,cost,edp[5000][20],min[5000][20],i,j,k,temp,min_edp;
int main(void) {
	while(scanf("%d %d %d %d",&f,&p,&e,&a)) {
		if(f == 0) break;
		/*init */
		cost = e*a;
		/* input */
		for(i = 0;i < p;i++) 
			for(j = 0;j < f;j++) {
				scanf("%d %d",&e,&a);
				edp[i][j] = e*a;
			}
		/* processa */
		for(j = 0; j < f;j++)
			min[p-1][j] = edp[p-1][j];
		for(i = p-2;i >= 0;i--)
			for(j=0;j < f;j++) {
				min_edp = 1<<29;
				for(k=0;k < f;k++) {
					temp = min[i+1][k] + edp[i][j];
					if(j != k) temp += cost;
					if (temp < min_edp) min_edp = temp;
				}
				min[i][j] = min_edp;
			}
		/* output */
		min_edp=min[0][0];
		for(j=1;j < f;j++)
			if(min[0][j]+cost < min_edp) min_edp = min[0][j] + cost;
		printf("%d\n",min_edp);
	}
	return 0;
}

