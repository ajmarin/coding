#include <cstdio>
#define _m_(a,b) ((a>b)?(a):(b))
int C[100], L[100];
int main(void){
	int i, j, k, m, n, max = 0;
	scanf("%d%d",&n,&m);
	for(i = 0; i < n || i < m; i++) L[i] = C[i] = 0;
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			scanf("%d",&k);
			L[i] += k;
			C[j] += k;
		}
		max = _m_(max,L[i]);
		if(i == n-1)
			for(j = 0; j < m; j++)
				max = _m_(max,C[j]);
	}
	printf("%d\n",max);
	return 0;
}
