#include <cstdio>

char num[1048576], *s;
int main(void){
	int cmp, len, t;
	int lc, rc, L, R;
	scanf("%d", &t);
	while(t--){
		s = num + 1;
		scanf("%s", s);
		for(len = -1; s[++len]; );
		lc = L = (len >> 1) - !(len & 1);
		rc = R = len >> 1;
		cmp = 0;
		while(L > -1){
			cmp = cmp ? cmp : (s[L] > s[R]) - (s[L] < s[R]);
			s[R++] = s[L--];
		}
		if(cmp != 1){
			L = lc, R = rc;
			while(s[L] == '9') s[L--] = s[R++] = '0';
			if(L == -1) s[L] = '1', s[R-1] = '1', s = num;
			else ++s[L], s[R] += L != R;			
		}
		puts(s);
	}
	return 0;
}
