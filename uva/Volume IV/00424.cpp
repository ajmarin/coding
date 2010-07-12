/////////////////////////////////
// 00424 - Integer Inquiry
/////////////////////////////////
#include<cstdio>
int i, cr, pos;
int res[200];
char str[105];
int main(void){
	while(gets(str)){
		if(str[0] == '0') break;
		for(i = 0; str[i] != '\0'; i++);
		pos = 199;
		for(i = i-1; i > -1; i--){
			cr = res[pos] + str[i] - '0';			
			res[pos--] = cr%10;
			res[pos] += cr/10;
		}
	}	
	for(i = 0; res[i] == 0; i++);
	for(; i < 200; i++) printf("%d",res[i]);
	printf("\n");
}