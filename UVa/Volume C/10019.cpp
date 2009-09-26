/////////////////////////////////
// 10019 - Funny Encryption Method
/////////////////////////////////
#include<cstdio>
int c,b1,b2,n;
int howmanyones[] = {0,1,1,2,1,2,2,3,1,2};
void findb1(){
	for(b1 = 0; n!=0; n = n>>1)
		b1 += n%2;
}
void findb2(int k){
	int temp = k;
	for(b2 = 0; temp != 0; temp /= 10)
		b2+= howmanyones[temp%10];
}
int main(void){
	scanf("%d",&c);
	while(c){
		scanf("%d",&n);
		findb2(n);
		findb1();
		printf("%d %d\n",b1,b2);
		c--;
	}
	return 0;
}
