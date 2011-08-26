#include <cstdio>
#include <cstring>
char line[10048];
int main(void) {
	int T, N, cost[258], p, total;
	char ch;
	scanf("%d\n", &T);
	while(T-- && scanf("%d\n", &N)==1) {
		memset(cost, 0, sizeof cost);
		total = 0;
		while (N-- && scanf("%c %d\n", &ch, &p)==2) cost[ch + 128] = p;
		scanf("%d\n", &N);
		while (N--) {
			fgets(line, 10048, stdin);
			for(int i = 0; line[i] != '\n'; ++i) total += cost[line[i] + 128];
		}
		printf("%d.%02d$\n", total / 100, total % 100);
	}
	return 0;
}
