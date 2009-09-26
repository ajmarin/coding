/////////////////////////////////
// 00195 - Anagram
/////////////////////////////////
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
unsigned int cnum;
char word[1000];
int value[127],len;
struct cmp {
  bool operator()(int x, int y) {
    return value[x] < value[y];
  }
};
int main(void){
	for(len = 'A'; len < 'Z'+1; len++){
		value[len] = 2*(len-'A');
		value[len+32] = value[len]+1;
	}
	scanf("%u\n",&cnum);
	while(cnum--){
		gets(word);
		len = strlen(word);
		sort(word,word+len,cmp());
		do { puts(word); } while(next_permutation(word,word+len,cmp()));
	}
	return 0;
}
