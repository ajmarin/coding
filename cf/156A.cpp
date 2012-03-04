#include <cstdio>

int main(void){
	for(char s[2048], t[2048]; scanf("%s %s", s, t) == 2; ){
		int diff, lens, lent, minc = 1 << 20;
		for(lens = 0; s[lens]; ++lens);
		for(lent = 0; t[lent]; ++lent);
		for(int i = -lent; i < lens; ++i){
			for(int j = diff = 0; j < lent; ++j)
				diff += (i + j) < 0 || (i + j) >= lens || s[i + j] != t[j];
			if(diff < minc) minc = diff;
		}
		printf("%d\n", minc);
	}
	return 0;
}

