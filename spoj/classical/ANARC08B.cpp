#include <cstdio>
char f[64], s[64];
int ans[16], map[128];
const char *r[10] = {"063", "010", "093", "079", "106",
                     "103", "119", "011", "127", "107"};
int main(void){
	map[63] = 0; map[10] = 1; map[93] = 2;
	map[79] = 3; map[106] = 4; map[103] = 5;
	map[119] = 6; map[11] = 7; map[127] = 8;
	map[107] = 9;
	while(scanf("%[^+]", f) && f[0] != 'B'){
		long long fv = 0, sv = 0;
		int z;
		scanf("+%[^=]=\n", s);
		for(int i = 0; f[i]; i += 3){
			int z; sscanf(f + i, "%3d", &z);
			fv = 10 * fv + map[z];
		}
		for(int i = 0; s[i]; i += 3){
			int z; sscanf(s + i, "%3d", &z);
			sv = 10 * sv + map[z];
		}
		fv += sv;
		for(z = 0; fv; ++z) ans[z] = fv % 10, fv /= 10;
		printf("%s+%s=", f, s);
		while(z--) printf("%s", r[ans[z]]);
		puts("");
	}
	return 0;
}

