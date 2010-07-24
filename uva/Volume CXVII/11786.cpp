#include <cstdio>
#define IN getc( stdin )
const int N = 20050, M = 10025;
int d[N];
int main(void){
	int ans, h, i, t; scanf("%d\n", &t);
	register char c;
	while(t--){
		for(i = 0; i < N; ++i) d[i] = -1;
		for(ans = i = 0, c = IN, h = M; c != 10; c = IN, i++){
			if(c == '\\') d[h--] = i; 
			else if(c == '/' && d[++h] != -1){
				ans += i - d[h];
				d[h] = -1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
