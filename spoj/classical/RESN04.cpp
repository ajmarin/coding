#include <cstdio>

int main(void){
	int n, s, t, z; scanf("%d", &t);
	while(t-- && scanf("%d", &n) == 1){
		s = 0;
		for(int i = 1; i <= n; ++i){
			scanf("%d", &z);
			s += z / i;
		}
		puts(s & 1 ? "ALICE" : "BOB");
	}
	return 0;
}

