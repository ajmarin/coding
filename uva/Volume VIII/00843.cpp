#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
using namespace std;

#define FOR(i,n) for(int i = 0; i < n; ++i)

char m[128], phrase[128], w[32][1000][32];
int csz[32];
bool mapped[128];

bool bt(int pos){
	if(!phrase[pos]) return true;
	int lset, sz = 0;
	while(phrase[pos] == ' ') ++pos;
	for(sz = 0; islower(phrase[pos + sz]); ++sz);
	FOR(i, csz[sz]){
		bool ok = true;
		for(int j = pos, k = lset = 0; ok && k < sz; ++k, ++j){
			if(m[phrase[j]] == '*' && !mapped[w[sz][i][k]]){
				mapped[ m[phrase[j]] = w[sz][i][k] ] = true;
				lset |= (1 << k);
			}
			ok &= m[phrase[j]] == w[sz][i][k];
		}
		if(ok && bt(pos + sz + 1)) return true;
		FOR(k, sz) if(lset & (1 << k)){
			mapped[m[phrase[k + pos]]] = false;
			m[phrase[k + pos]] = '*';
		}
	}
	return false;
}

struct x { char s[32]; int L; bool operator<(const x y) const { return L > y.L; } } sw[128];
void split_sort_phrase(char *s){
	char ts[128];
	strcpy(ts, s);
	char *p = strtok(ts, " ");
	int cnt, pos = 0;
	for(cnt = 0; p != NULL; ++cnt){
		sw[cnt].L = strlen(p);
		strcpy(sw[cnt].s, p);
		p = strtok(NULL, " ");
	}
	sort(sw, sw + cnt);
	FOR(i, cnt){
		strcpy(phrase + pos, sw[i].s);
		phrase[pos + sw[i].L] = ' ';
		pos += sw[i].L + 1;
	}
	phrase[pos] = 0;
	phrase[--pos] = 10;
}

int main(void){
	char p[128], word[32];
	for(int n, z; scanf("%d", &n) == 1; ){
		FOR(i, 32) csz[i] = 0;
		FOR(i, n){
			scanf("%s", word);
			z = strlen(word);
			strcpy(w[z][csz[z]++], word);
			scanf(" ");
		}
		while( fgets(p, 128, stdin) ){
			p[strlen(p) - 1] = 0;
			FOR(i, 128) m[i] = '*', mapped[i] = false;
			m[32] = 32; m[10] = 10;
			split_sort_phrase(p);
			bt(0);
			for(int j = 0; p[j]; ++j) putc(m[p[j]], stdout);
			puts("");
		}
	}

	return 0;
}

