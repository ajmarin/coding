#include <cstdio>
#define FOR(a,b) for(int a = 0; a < b; ++a)
char rule[512], word[128][512];
int idx[512];
int m, n;
void bt(int k){
	if(!rule[k]){
		FOR(i, k){
			if(rule[i] == '#')
				for(char *p = word[idx[i]]; *p; p++)
					putc(*p, stdout);
			else putc('0' + idx[i], stdout);
		}
		putc(10, stdout);
		return;
	}
	if(rule[k] == '#') FOR(i, n) idx[k] = i, bt(k + 1);
	else FOR(i, 10) idx[k] = i, bt(k + 1);
}
int main(void){

	while(scanf("%d", &n) == 1){
		FOR(i, n) scanf("%s", word[i]);
		scanf("%d", &m);
		puts("--");
		FOR(i, m){
			scanf("%s", &rule);
			bt(0);
		}
	}
	return 0;
}
