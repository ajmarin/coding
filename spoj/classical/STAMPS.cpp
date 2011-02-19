#include <algorithm>
#include <cstdio>
int main(void){
	int c, f, i, L[1024], need, s, t;
	for(c = 0, scanf("%d", &t); c++ < t; ){
		s = 0;
		scanf("%d %d", &need, &f);
		for(i = 0; i < f; ++i) scanf("%d", L + i), s += L[i];
		std::sort(L, L + f);
		for(i = 0; s - L[i] >= need; s -= L[i++]);
		printf("Scenario #%d:\n", c, f - i);
		if(s >= need) printf("%d\n", f - i);
		else puts("impossible");
		puts("");
	}
	return 0;
}

