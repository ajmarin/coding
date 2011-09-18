#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <string>
using namespace std;
#define FOR(i,n)	for(int i = 0; i < n; ++i)
const int MEN(500), WOMEN(500);

map < string, int > mnum, snum;
bool graph[MEN][WOMEN], seen[WOMEN];
int matchL[MEN], matchR[WOMEN];
int men, women;

struct person { int h, m, s; } m[MEN], w[WOMEN]; 

bool bpm(int u){
	FOR(v, women) if(graph[u][v]) {
		if(seen[v]) continue;
		seen[v] = true;
		if(matchR[v] < 0 || bpm( matchR[v] )){
			matchL[u] = v;
			matchR[v] = u;
			return true;
		}
	}
	return false;
}

int main(void){
	int T; scanf("%d", &T);
	char msc[128], sex[128], sprt[128];
	for(int n; T-- && scanf("%d", &n); ){
		int ans(n), h, mtc(0), stc(0);
		men = women = 0;
		mnum.clear();
		snum.clear();
		FOR(i, n){
			scanf("%d %s %s %s", &h, sex, msc, sprt);
			int &mtype = mnum[msc], &stype = snum[sprt];
			if(!mtype) mtype = ++mtc;
			if(!stype) stype = ++stc;
			person *p;
			if(sex[0] == 'M') p = &m[men];
			else p = &w[women];
			p -> h = h;
			p -> m = mtype;
			p -> s = stype;
			men += sex[0] == 'M';
			women += sex[0] == 'F';
		}
		memset(matchR, -1, women << 2);
		memset(matchL, -1, men << 2);
		FOR(i, men) FOR(j, women){
			graph[i][j] = abs(m[i].h - w[j].h) <= 40 && m[i].m == w[j].m && m[i].s != w[j].s;
		}
		FOR(i, men){
			memset(seen, 0, women);
			ans -= bpm(i);
		}
		printf("%d\n", ans);
	}
	return 0;
}

