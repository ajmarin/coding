#include <cctype>
#include <cstdio>

#define FOR(i,n)	for(int i = 0; i < n; ++i)
#define IN			getc(stdin)

const int MAXPLEN = 1024, MAXW = 10240;
struct word {
	int l;
	char w[128];
} dict[10048];

int readString(char *s){
	char c; int cnt(0);
	for(c = IN; !islower(c); c = IN);
	for(;islower(c); *s++ = c, c = IN, ++cnt);
	*s = 0;
	return cnt;
}

char phrase[MAXPLEN];
int cnt[32];
int from[MAXPLEN][128], len[MAXPLEN];
int ansidx[MAXPLEN], ansc, tmpans[MAXPLEN];
int mark[MAXPLEN];
int plen;
bool ambiguous, impossible;

//#define DBG
bool dfs(int left, int d){
	if(left == plen){
		if(!impossible) ambiguous = true;
		impossible = false;
		ansc = d;
		FOR(i, ansc) ansidx[i] = tmpans[i];
		return true;
	}
	if(mark[left] != -1) return mark[left];
	if(ambiguous) return true;
	bool r = false;
	FOR(i, len[left]){
		int x = tmpans[d] = from[left][i], z = left + dict[x].l;
		ambiguous |= mark[z] == 1;
		r |= mark[z] == 1 || dfs(z, d + 1) == 1;
	}
	return mark[left] = r;
}

int main(void){
	int T; scanf("%d", &T);
	for(int n; T--; ){
		plen = readString(phrase);
		scanf("%d", &n);
		/* INIT */
		FOR(i, plen) len[i] = 0, mark[i] = -1;
		ambiguous = false;
		impossible = true;
		/* */
		FOR(i, n){
			int wlen = dict[i].l = readString(dict[i].w);
			if(wlen <= plen){
				int mustbezero = 0;
				FOR(j, 32) cnt[j] = 0;
				FOR(j, wlen){
					++cnt[dict[i].w[j] - 'a'];
					--cnt[phrase[j] - 'a'];
				}
				FOR(j, 32) mustbezero += cnt[j] != 0;
				FOR(j, plen - wlen + 1){
					char rejoin, leave;
					if(j){
						rejoin = phrase[j - 1] - 'a';
						leave = phrase[j + wlen - 1] - 'a';
						++cnt[rejoin];
						mustbezero -= cnt[rejoin] == 0;
						mustbezero += cnt[rejoin] == 1;
						--cnt[leave];
						mustbezero -= cnt[leave] == 0;
						mustbezero += cnt[leave] == -1;
					}
					if(mustbezero == 0 && phrase[j] == dict[i].w[0] && phrase[j + wlen - 1] == dict[i].w[wlen - 1]){
						from[j][len[j]++] = i;
					}
				}
			}
		}
		dfs(0, 0);
		if(impossible) puts("impossible");
		else if(ambiguous) puts("ambiguous");
		else FOR(i, ansc) printf("%s%c", dict[ansidx[i]].w, i == ansc - 1 ? '\n' : ' ');
	}

	return 0;
}

