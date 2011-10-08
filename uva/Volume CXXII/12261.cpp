#include <cstdio>
const int NN = 1048;
char s[NN];
int m[NN], r[2];
int min(int a, int b){ return a < b ? a : b; };
int main(void){
	int t; scanf("%d", &t);
	while(t--){
		scanf("%s", s);
		int e = 0, L = 0, mov = 0;
		for(char *p = s; *p; ++p, mov += m[L++])
			m[L] = min(*p - 'A', 'Z' - *p + 1);
		if(!mov){ puts("0"); continue; }
		r[0] = r[1] = L - 1;
		for(int ri = 0; ri < 2; ++ri){
			for(int i = 0; i < L; ++i){
				if(m[i]){
					if(e && e != i) r[ri] = min(r[ri], L + i - 2 - (e << 1));
					e = 0;
				}
				e += !m[i];
			}
			if(e) r[ri] = min(r[ri], L - 1 - e);
			e = 0;
			for(int i = 1, t; i < (L >> 1); ++i) 
				t = m[L-i], m[L-i] = m[i], m[i] = t;
		}
		printf("%d\n", mov + min(r[0], r[1]));
	}
	return 0;
}
			
