/////////////////////////////////
// 10098 - Generating Fast
/////////////////////////////////
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
unsigned int cnum;
char word[15],len;
int main(void){
	scanf("%u\n",&cnum);
	while(cnum--){
		gets(word);
		len = strlen(word);
		sort(word,word+len);
		do { puts(word); } while(next_permutation(word,word+len));
		putchar('\n');
	}
	return 0;
}
