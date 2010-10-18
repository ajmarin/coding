#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define FOR(a,b)	for(int a = 0; a < b; ++a)
#define FORI(a,b,c)	for(int a = b; a < c; ++a)

char cnt[128], test[16];
struct word {
	char w[16];
} dict[128];
bool cmp(word w1, word w2){ return strcmp(w1.w, w2.w) < 0; }
bool check(char *p, char *t){
	FORI(i, 'a', 'z' + 1) cnt[i] = 0;
	for(;*p || *t;){
		if(*p) cnt[*p++]++;
		if(*t) cnt[*t++]--;
	}
	FORI(i, 'a', 'z' + 1) if(cnt[i]) return 0;
	return 1;
}

int main(void){
	int n = 128;
	FOR(i, n){
		scanf("%s", dict[i].w);
		if(dict[i].w[0] == 'X'){ n = i; break; }
	}
	sort(dict, dict + n, cmp); 
	while(scanf("%s", test) && test[0] != 'X'){
		int s = 0;
		FOR(i, n) if(check(test, dict[i].w)) printf("%s\n", dict[i].w), s++;
		if(!s) puts("NOT A VALID WORD");
		puts("******");
	}
	return 0;
}

