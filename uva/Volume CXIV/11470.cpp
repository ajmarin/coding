/////////////////////////////////
// 11470 - Square Sums
/////////////////////////////////
#include<cstdio>
int i,j,n,sum,case_number = 0;
int v[10][10];
int main(void){
	scanf("%d",&n);
	while(n){
		for(i = 0; i < n; i++) for(j = 0; j < n; scanf("%d",&v[i][j]),j++);	
		printf("Case %d:",++case_number);
		for(i = 0; i < n/2; i++){
			sum = 0;
			sum += v[i][i]+v[i][n-1-i]+v[n-1-i][i]+v[n-1-i][n-1-i];
			for(j = i+1; j < n-1-i; j++) sum += v[i][j]+v[j][i]+v[n-1-j][n-1-i]+v[n-1-i][n-1-j];
			printf(" %d",sum);
		}
		if(n % 2 != 0) printf(" %d",v[n/2][n/2]);
		printf("\n");
		scanf("%d",&n);		
	}
	return 0;
}	
