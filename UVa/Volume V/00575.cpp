/////////////////////////////////
// 00575 - Skew Binary
/////////////////////////////////
#include<cstdio>
#include<cstring>
#include<cmath>
long int result;
char c[35];
int i;
int length;
int main(void){
	while(scanf("%s",&c)){

		if(c[0] == '0') break;
		
		result = 0;
		length = strlen(c);
		for(i = 0; i < length; i++){
			c[i]-='0';
			result+= c[i]*(pow(2,length-i)-1); 
		}
		printf("%ld\n",result);		
	}
}
