#include <cstdio>
int main(void){
	int n; scanf("%d", &n);
	int jump = n - 1;
	for(int i = 1; ; ){		
		printf("%d%c", i, jump ? ' ' : '\n');
		if(!jump) break;
		i += jump;
		jump = -jump + (jump > 0) - (jump < 0);
	}
	return 0;
}
