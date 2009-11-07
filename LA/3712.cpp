#include <cstdio>
#include <cstring>

char v0[256];
char v1[256];

int main(void){
	bool t[2];
	int ans0, ans1, idx, j, k, n, l0, l1;
	while(fgets(v0, 256, stdin)){
		l0 = strlen(v0) - 1;
		v0[l0] = 0;
		for(char *p = v0; *p; ++p) *p -= '0';
		fgets(v1, 256, stdin);
		l1 = strlen(v1) - 1;
		v1[l1] = 0;
		for(char *p = v1; *p; ++p) *p -= '0';
		ans0 = ans1 = 0;
		for(int i = 0; !ans1 && i < l0; ++i){
			for(j = i, k = 0; j < l0 && k < l1; ++j, ++k)
				if(v0[j] + v1[k] == 4) break;
			if(j == l0)	ans1 = j - i;
			else if (k == l1) ans1 = k;
		}
		for(int i = 0; !ans0 && i < l1; ++i){
			for(j = i, k = 0; j < l1 && k < l0; ++j, ++k)
				if(v1[j] + v0[k] == 4) break;
			if(j == l1) ans0 = j - i;
			else if(k == l0) ans0 = k;
		}
		int ans = ans1;
		if(ans0 > ans1) ans = ans0;
		printf("%d\n", l0 + l1 - ans);
	}
	return 0;
}

