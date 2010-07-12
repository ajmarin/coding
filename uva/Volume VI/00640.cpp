/////////////////////////////////
// 00640 - Self Numbers
/////////////////////////////////
#include<cstdio>
#include<cstring>
bool self[1000001];
unsigned int i;
unsigned short int res;
void dsum(unsigned int k){
	res = 0;
	while(k){ res+=k%10; k/=10;}
}
int main(void){
	memset(self,1,sizeof(self));
	for(i = 1; i < 1000001; i++){
		dsum(i);
		if(res+i < 1000001) self[res+i] = 0;
		if(self[i]) printf("%u\n",i);
	}
	return 0;
}