#include <cstdio>

typedef long long LL;
LL fact[21];
char s[32], ans[32];
int main(void){
	int t; scanf("%d", &t);
	LL n;
	fact[0] = 1;
	for(int i = 1; i < 21; ++i) fact[i] = i * fact[i - 1];
	for(int c = 0; c++ < t && scanf("%s %lld", s, &n) == 2; ){
		int len;
		for(len = 0; s[len]; ++len);
		for(int i = 0, u = 0; i < len; ++i){
			int j, rpos = 0, z;
			while(n > fact[len - i - 1]){
				++rpos;
				n -= fact[len - i - 1];
			}
			for(j = z = 0; z < rpos || (u & (1 << j)); ++j)
				if(!(u & (1 << j))) ++z;
			ans[j] = s[i];
			u |= (1 << j);
		}
		ans[len] = 0;
		printf("Case %d: ", c);
		puts(ans);
	}
	return 0;
}

