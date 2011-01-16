/////////////////////////////////
// 11371 - Number Theory for Newbies
/////////////////////////////////
#include<cstdio>
#include<cstring>
#include<algorithm>
char valuex[15],valuey[15],len,i;
long long int X,Y;
void XandYpleaseKthx(){
	strcpy(valuey,valuex);
	X = Y = 0;
	for(i = 0; valuex[i] == '0'; i++);
	valuex[i] ^= valuex[0] ^= valuex[i] ^= valuex[0];
	for(i = 0; i < len; i++){
		X*=10; X+= (valuex[i]-'0');
		Y*=10; Y+= (valuey[len-i-1]-'0');
	}
}
int main(void){
	while(scanf("%s",&valuex)==1){
		len = strlen(valuex);
		std::sort(valuex,valuex+len);
		XandYpleaseKthx();
		printf("%lld - %lld = %lld = 9 * %lld\n",Y,X,Y-X,(Y-X)/9);
	}
	return 0;
}
