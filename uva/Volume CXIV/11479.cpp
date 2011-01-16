/////////////////////////////////
// 11479 - Is this the Easiest Problem?
/////////////////////////////////
#include<stdio.h>
#include<iostream.h>
int i, cases;
long long a,b,c,sum;
int main(void){
	scanf("%d",&cases);
	for(i = 1; !(i > cases); i++){
		cin >> a >> b >> c;		
		printf("Case %d: ",i);
		if(a <= 0 || b <= 0 || c <= 0){
			printf("Invalid\n");
			continue;
		}
		sum = a+b;
		if(sum <= c){
			printf("Invalid\n");
			continue;
		}
		sum = b+c;
		if(sum <= a){
			printf("Invalid\n");
			continue;
		}
		sum = a+c;
		if(sum <= b){
			printf("Invalid\n");
			continue;
		}
		if(a == b){
			if(b == c) printf("Equilateral\n");
			else printf("Isosceles\n");
		}
		else if(a == c || b == c) printf("Isosceles\n");
		else printf("Scalene\n");
	}
	return 0;
}