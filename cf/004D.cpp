#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define FOR(i,e)		for(int i = 0; i < e; ++i)
#define FORD(i,s,e)		for(int i = s; i > e; --i)
#define FORI(i,s,e)		for(int i = s; i < e; ++i)
const int N = 5096;
struct envelope {
	int w, h, n;
	bool operator<(const envelope e) const { return w < e.w || (w == e.w && h < e.h); }
	bool operator>(const envelope e) const { return w > e.w && h > e.h; }
} e[N];
int memo[N], jump_to[N], n;
void dfs(int x){
	memo[x] = 1;
	FORI(i, x + 1, n)
		if(e[i] > e[x]){
			if(!memo[i]) dfs(i);
			if(memo[i] + 1 > memo[x]){
				memo[x] = 1 + memo[i];
				jump_to[x] = i;
			}
		}
}
int main(void){
	scanf("%d %d %d", &n, &e[0].w, &e[0].h), e[0].n = 0; ++n;
	FORI(i, 1, n) scanf("%d %d", &e[i].w, &e[i].h), e[i].n = i;
	memset(memo, 0, n << 2);
	sort(e, e + n);
	FOR(i, n) if(e[i].n == 0){
		dfs(i);
		printf("%d\n", --memo[i]);
		int k = i;
		while(memo[k]--) printf("%d%c", e[i = jump_to[i]].n, memo[k] ? ' ' : '\n');			
		break;
	}
	return 0;
}

