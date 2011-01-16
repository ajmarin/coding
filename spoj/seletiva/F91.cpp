#include<cstdio>
int n;
int main(void){
	scanf("%d",&n);
	while(n){
		printf("f91(%d) = %d\n",n,(n<102)?91:n-10);
		scanf("%d",&n);
	}
	return 0;
}
