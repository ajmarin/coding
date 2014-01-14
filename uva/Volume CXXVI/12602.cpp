#include <cstdlib>
#include <cstdio>

int main(void){
	char p[16];
	int n; scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%s", p);
		int first = (p[0] - 'A') * 676 + (p[1] - 'A') * 26 + (p[2] - 'A'), second;
		sscanf(p + 4, "%d", &second);
		puts(abs(first - second) <= 100 ? "nice" : "not nice");
	}
	return 0;
}

