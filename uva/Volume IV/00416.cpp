#include <cstdio>

const char *lit[10] = { "YYYYYYN", "NYYNNNN", "YYNYYNY", "YYYYNNY",
	"NYYNNYY", "YNYYNYY", "YNYYYYY", "YYYNNNN", "YYYYYYY", "YYYYNYY" };
char cd[16][16];
int main(void){
	for(int n; scanf("%d", &n) == 1 && n; ){
		for(int i = 0; i < n; ++i) scanf("%s", cd[i]);
		bool match = false;
		for(int f = 9; !match && f >= (n - 1); --f){
			for(int burned = 0; !match && burned < 128; ++burned){
				int cb = burned;
				bool valid = true;
				for(int i = 0; valid && i < n; ++i)
					for(int j = 0; valid && j < 7; ++j){
						valid &= cd[i][j] == 'N' || (lit[f - i][j] == 'Y' && !(cb & (1 << j)));
						if(cd[i][j] == 'N' && lit[f - i][j] == 'Y') cb |= (1 << j);
					}
				match |= valid;
			}
		}
		puts("MISMATCH" + 3 * match);
	}
	return 0;
}

