#include <cctype>
#include <cstdio>

#define IN getc( stdin )

void fastint( register int *n ){
	register char c = IN;
	*n = 0;
	while(!isdigit(c)) c = IN;
	while(isdigit(c)) (*n) = (*n) * 10 + (c - '0'), c = IN;
}
int n, v[20020];
int main(void){
	while(scanf("%d", &n) && n){
		int idx, max = 0, *pv = v, *pvn = v + n, sum = 0;
		for(int i = 0; i < n; ++i){
			fastint(pv);
			if(*pv >= max) max = *pv,  idx = (pv - v);
			sum += *pv;
			*pvn++ = *pv++;
		}
		while(sum % max) ++max;
		int *lim = v + idx + n, rem = 0;
		for(pv = v + idx; pv != lim; ++pv){
			if(*pv < max) ++rem, *(pv + 1) += *pv;
			else if(*pv > max) break;
		}
		if(pv != lim || (n - rem) < 3) puts("-1");
		else printf("%d\n", rem);
	}
	return 0;
}

