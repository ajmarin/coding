/////////////////////////////////
// 10469 - To Carry or not to Carry
/////////////////////////////////
#include<cstdio>
bool bin[32];
int i,w;
unsigned long int a,b;
void solveit(){
	for(i = 0; i <  32; i++) bin[i] = 0;
	for(i = 0; a!=0; i++){
		bin[31-i] = a%2;
		a = a>>1;
	}
	for(i = 0; b!=0; i++){
		bin[31-i] = bin[31-i]^(b%2);
		b = b>>1;
	}
	w = 1;
	for(i = 31; i > -1; a+=bin[i]*w,w*=2,i--);
	printf("%lu\n",a);
}
int main(void){	
	while(scanf("%lu %lu",&a,&b)!=EOF) solveit();	
	return 0;
}
