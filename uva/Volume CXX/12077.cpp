#include <cstdio>
#include <cstring>

#define FOR(i,n)	for(int i = 0; i < n; ++i)
#define FORI(i,s,n)	for(int i = s; i < n; ++i)
struct product {
	int n;
	int lo[100], hi[100];
	int least[100], most[100];
	char ing[100][32], name[32];
} p[16];

int min(int a, int b){ return a < b ? a : b; }
int max(int a, int b){ return a > b ? a : b; }

int memo[128][128][128];
bool tryQty(int ing, int top, int remain, product &z){
	if(remain < 0 || ing == z.n) return remain == 0;
	int &r = memo[ing][top][remain];
	if((r >> 1) != (&z - p)){
		r = (&z - p) << 1;
		int stop_at = min(z.most[ing], top) + 1;
		FORI(i, z.least[ing], stop_at)
			if(tryQty(ing + 1, i, remain - i, z)){
				r |= 1;
				z.lo[ing] = min(z.lo[ing], i);
				z.hi[ing] = max(z.hi[ing], i);
			}
	}
	return r & 0x1;
}
int main(void){
	char ingredient[16], line[1024];
	for(int P; scanf("%d", &P) == 1 && P; ){
		FOR(i, 128) FOR(j, 128) FOR(k, 128)
			memo[i][j][k] = -1;
		FOR(i, P){
			scanf("%s %d\n", p[i].name, &p[i].n);
			FOR(j, p[i].n){
				fgets(line, 1024, stdin);
				if(sscanf(line, "%s %d", p[i].ing[j], &p[i].least[j]) == 2)
					p[i].most[j] = p[i].least[j];
				else {
					sscanf(line, "%s", p[i].ing[j]);
					p[i].least[j] = 1;
					p[i].most[j] = 100;
				}
				p[i].lo[j] = 100;
				p[i].hi[j] = 0;
			}
			tryQty(0, 100, 100, p[i]);
		}
		int queries;
		int list[16];
		for(scanf("%d", &queries); queries--; ){
			int top(0);
			int left(0), right(100);
			scanf("%s %s", line, ingredient);
			FOR(i, P) {
				int least(0), most(0);
				FOR(j, p[i].n) if(!strcmp(p[i].ing[j], ingredient)){
					least = p[i].lo[j];
					most = p[i].hi[j];
					break;
				}
				left = max(left, least);
				right = min(right, most);
			}
			FOR(i, P){
				int least(0), most(0);
				FOR(j, p[i].n) if(!strcmp(p[i].ing[j], ingredient)){
					least = p[i].lo[j];
					most = p[i].hi[j];
					break;
				}
				if((line[0] == 'm' && most >= left) ||
				   (line[0] == 'l' && least <= right))
					list[top++] = i;
			}
			FOR(i, top)
				printf("%s%c", p[list[i]].name, i == top - 1 ? '\n' : ' ');
		}
	}
	return 0;
}

