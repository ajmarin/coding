/////////////////////////////////
// 00488 - Triangle Wave
/////////////////////////////////
#include<cstdio>
#include<string>
#include<vector>
const char *a[] = {"1\n","22\n","333\n","4444\n","55555\n",
"666666\n","7777777\n","88888888\n","999999999\n"};
char i,j;
unsigned int amp,cnum,freq;
std::vector <std::string> v(9);
int main(void){
	for(i = 1; i < 10; i++){
		v[i-1] = "";
		for(j = 0; j < i; j++) v[i-1] += a[j];
		for(j = i-2; j > -1 ; j--) v[i-1] += a[j];
	}
	scanf("%u\n",&cnum);
	while(cnum--){
		scanf("%u\n%u\n",&amp,&freq);
		const char *ans = v[amp-1].c_str();
		while(freq--){
			printf("%s",ans);
			if(freq) putc('\n',stdout);
		}
		if(cnum) putc('\n',stdout);
	}
	return 0;
}
