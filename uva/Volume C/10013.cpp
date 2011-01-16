/////////////////////////////////
// 10013 - Super long sums
/////////////////////////////////
#include<cstdio>
char a[1000001], line[10];
int sums,j,k,n;
int main(void){
	scanf("%d\n",&sums);
	while(sums--){
		scanf("%d\n",&n);
		for(k = 0; k < n; k++) {
			gets(line);
			a[k] = line[0]+line[2]-'0';
			if(a[k] > 57){
				a[k] = (a[k]-'0')%10+'0';
				j = k-1;
				++a[j];
				while(a[j] == 58){
					a[j] = (a[j]-'0')%10+'0';				
					a[--j]++;
				}
			}
		}
		a[n] = '\0';
		puts(a);
		if(sums) putchar('\n');
	}
	return 0;
}
