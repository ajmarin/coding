#include <cstdio>
#include <algorithm>

char num[1048576], ans[1048576];
int main(void){
	int b, b1, b2, k;
	while(scanf("%s %d %d", num, &b1, &b2) == 3){
		char *p;
		for(p = num; *p; ++p)
			*p = (*p >= 'A' ? 10 + *p - 'A' : *p - '0');
		b = 1; k = 0;
		while(p-- > num){
			k += *p * b;
			b *= b1;
		}
		if(k) 
			for(p = ans; k; p++){
				*p = k % b2;
				if(*p > 9) *p = 'A' + *p - 10;
				else *p += '0';
				k /= b2;
			}
		else ans[0] = '0', p = ans + 1;
		std::reverse(ans, p);
		*p = 0;
		if(p - ans > 7) printf("  ERROR\n");
		else printf("%7s\n",ans);
	}
	return 0;
}

