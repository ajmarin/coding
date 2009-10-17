#include <algorithm>
#include <cstdio>
#include <cstring>

bool p(int k){
	char o[6], *p = o, r[6], x;
	while(k) *p++ = k % 10 + '0', k /= 10;
	*p = 0;
	x = p - o;
	strcpy(r, o);
	std::reverse(r, r + x);
	return !strcmp(r, o);
}

int n[2400], ns = 0;
int main(void){
	int T;
	for(int h = 0; h < 24; ++h)
		for(int m = 0; m < 60; ++m){
			int x = 100 * h + m;
			if(p(x)) n[ns++] = x;
		}
	scanf("%d", &T);
	while(T--){
		int h, m, t, u, v;
		scanf("%2d:%2d",&h, &m);
		t = 100 * h + m;
		for(u = 0, v = ns; u < v; ){
			int c = (u + v) >> 1;
			if(n[c] > t) v = c; else u = c + 1;
		}
		while(u < ns && n[u] <= t) u++;
		u %= ns;
		printf("%02d:%02d\n",n[u]/100,n[u]%100);
	}
	return 0;
}

