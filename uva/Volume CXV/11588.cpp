#include <cstdio>

int cnt[26];

int main(void){
	char L;
	scanf("%*d");
	for(int c, cn = 0, m, n, r; scanf("%d%d%d%d", &r, &c, &m, &n) == 4; ){
		int ans = 0, maxa = -1;
		for(int i = 0; i < 26; ++i) cnt[i] = 0;
		for(int i = 0; i < r; ++i) for(int j = 0; j < c; ++j){
			scanf(" %c", &L);
			++cnt[L - 'A'];
		}
		for(int i = 0; i < 26; ++i) if(cnt[i] > maxa) maxa = cnt[i];
		for(int i = 0; i < 26; ++i) 
			if(cnt[i] == maxa) ans += cnt[i] * m;
			else ans += cnt[i] * n;
		printf("Case %d: %d\n", ++cn, ans);
	}
	return 0;
}

