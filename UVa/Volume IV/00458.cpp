/////////////////////////////////
// 00458 - The Decoder
/////////////////////////////////
#include<cstdio>
int main(){
	char c;
	while((c = getchar())!=EOF) putchar(c=='\n'?'\n': (char)(c-7));
}
