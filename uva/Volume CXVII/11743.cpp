#include <cstdio>

int v[2][10];
char n[16];
const char *answer[2] = {"Invalid", "Valid"};
int main(void){
	int t;
	for(int i = 0; i < 5; ++i) v[0][i] = i, v[1][i] = (i << 1);
	for(int i = 5; i < 10; ++i) v[0][i] = i, v[1][i] = (i << 1) - 9;
	scanf("%d", &t);
	while(t--){
		int s = 0;
		bool t = 1;
		for(int i = 0; i < 4; ++i){
			scanf("%s", n);
			for(char *p = n; *p; ++p, t = 1 - t) s += v[t][*p - '0'];
		}
		puts(answer[!(s % 10)]);
	}
	return 0;
}
