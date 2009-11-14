#include <cstdio>

int T, N;

int main(void){
	char ign[128];
	while(scanf("%d %d", &T, &N) && T){
		int E = 0, p;
		for(int i = 0; i < T; ++i) scanf("%s %d", &ign, &p), E += p;
		printf("%d\n", N + (N << 1) - E);
	}
	return 0;
}

