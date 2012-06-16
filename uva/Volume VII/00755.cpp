#include <algorithm>
#include <cstdio>
using namespace std;

const char *mm[] = { "0", "1", "2ABC", "3DEF", "4GHI", "5JKL", "6MNO", "7PRS", "8TUV", "9WXY" };

char map[128];
char line[1048576];
int phones[100048];

int main(void){
	for(int i = 0; i < 128; ++i) map[i] = 0;
	for(int i = 0; i < 10; ++i)
		for(int j = 0; mm[i][j]; ++j)
			map[mm[i][j]] = i;
	int t; scanf("%d", &t);
	for(int n; t-- && scanf("%d", &n) == 1; ){
		for(int i = 0, v; i < n && scanf("%s", line) == 1; ++i){
			for(int j = v = 0; line[j]; ++j) if(line[j] != '-') v = (v * 10) + map[line[j]];
			phones[i] = v;
		}
		sort(phones, phones + n);

		// Output
		int shown = 0;
		for(int i = 0, j = 0; i < n; ++i){
			for(j = i; j < n && phones[j] == phones[i]; ++j);
			if(j - i > 1){
				printf("%03d-%04d %d\n", phones[i] / 10000, phones[i] % 10000, j - i);
				++shown;
			}
			i = j - 1;
		}
		if(!shown) puts("No duplicates.");
		if(t) puts("");
	}
	return 0;
}

