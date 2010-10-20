#include <cstdio>
int main(void){
#ifdef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	const char *ans[2] = {"-", "+"};
	int t, k; scanf("%d %d", &t, &k); ++k;
	for(int m, n; t-- && scanf("%d %d", &m, &n) == 2; ){
		if(n > m) n ^= m ^= n ^= m;
		puts(ans[!(n % k) || ((n / k) & k > 2)^((m + n) & 1)]);
	}
	return 0;
}

