/////////////////////////////////
// 00146 - ID Codes
/////////////////////////////////
#include<cstdio>
#include<algorithm>
char c[55];
int i;
int main(void){
	while(gets(c)){
		if(c[0] == '#') break;
		for(i = 0; c[i]; i++);
		if(std::next_permutation(c,c+i)) printf("%s\n",c);
		else printf("No Successor\n");
	}
}
