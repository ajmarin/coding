#include <cstdio>

int min(int a, int b){ return a < b ? a : b; }

int main(void){
	char op[16];
	for(int f = 0, n, r, z; scanf("%d", &n) == 1 && n; f = 1){
		int s[2] = {0, 0};
		if(f) puts("");
		for(int i = 0; i < n; ++i){
			scanf("%s %d", op, &z);
			if(*op == 'D'){
				s[1] += z;
				printf("DROP 2 %d\n", z);
			} else {
				if(!s[0]){
					s[0] = s[1];
					printf("MOVE 2->1 %d\n", s[1]);
					s[1] = 0;
				}
				r = min(s[0], z);
				s[0] -= r;
				z -= r;
				printf("TAKE 1 %d\n", r);
				if(z){
					s[0] = s[1] - z;
					printf("MOVE 2->1 %d\n", s[1]);
					printf("TAKE 1 %d\n", z);
					s[1] = 0;
				}
			}
		}
	}
	return 0;
}

