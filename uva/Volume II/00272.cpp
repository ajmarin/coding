/////////////////////////////////
// 00272 - TEX Quotes
/////////////////////////////////
#include<cstdio>
int main(){
	char c;
	for (int count=0; (c = getchar())!=EOF;){		
		if(c=='"') printf((++count&1)? "``":"''" );
	   else putchar(c);
	}
}
