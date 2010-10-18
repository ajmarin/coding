#include <cstdio>
#define FOR(a,b)	for(int a = 0; a < b; ++a)
int miss[32];
int min(int x, int y){ return x < y ? x : y; }
int main(void){
	for(int n, k; scanf("%d %d", &n, &k) == 2 && (n || k); ){
		int cnt = 0, curr = 0, cs = 0, next = 1;
		FOR(i, n) miss[i] = 40;
		for(int cs = 0; cnt != n; cs = (cs + 1) % n){
			if(!miss[cs]) continue;
			if(!curr) {
				curr = next++;
				if(next > k) next = 1;
			}
			int d = min(miss[cs], curr);
			miss[cs] -= d;
			curr -= d;
			if(!miss[cs]){
				++cnt;
				printf("%3d", cs + 1);
			}
		}
		putc(10, stdout);
	}
	return 0;
}

