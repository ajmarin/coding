#include <cstdio>

int main(void){
	for(int n; scanf("%d", &n) == 1; ){
		bool neg = n < 1;
		if(n < 0) n = -n;
		if(neg) printf("%d\n", 1 - (n * n + n) / 2);
		else printf("%d\n", (n * n + n) / 2);
	}
	return 0;
}

