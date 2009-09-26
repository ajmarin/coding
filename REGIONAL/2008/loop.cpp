#include <cstdio>

int n, peaks;
int v[10000];

int s(int i) {
	if(i < 0) return v[n + i];
	if(i >= n) return v[i - n];
	return v[i];
}

int main(void) {
	int i;

	while(scanf("%d", &n)) {
		if(n == 0)
			break;

		/* leitura */
		for(i = 0; i < n; i++)
			scanf("%d", &v[i]);

		/* conta os peaks */
		peaks = 0;
		for(i = 0; i < n; i++)
			if((s(i) > s(i - 1) && s(i) > s(i + 1)) ||
					(s(i) < s(i - 1) && s(i) < s(i + 1)))
				peaks++;
		printf("%d\n", peaks);
	}

	return 0;
}
