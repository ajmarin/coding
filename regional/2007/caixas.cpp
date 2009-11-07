#include <cstdio>

#define PP 1024

int n, p, q;
int t[PP], h[PP], s[PP];
int min;

int main(void) {
	int i, j, k;

	while(scanf("%d %d", &n, &p)) {
		if(n == 0 && p == 0) break;

		/* input */
		for(i = 0; i < p; i++) {
			scanf("%d", &t[i]);
			for(j = 0; j < t[i]; j++) {
				scanf("%d", &k), k--;
				h[k] = j;
				s[k] = i;
			}
		}

		/* processa */
		int a, b;
		for(a = 0, i = s[0]; i >= 0; i--) {
			if(t[i] > h[0]) a += t[i] - h[0];
			else break;
		}
		for(b = 0, i = s[0]; i < p; i++) {
			if(t[i] > h[0]) b += t[i] - h[0];
			else break;
		}

		/* output */
		printf("%d\n", (a < b ? a : b) - 1);
	}

	return 0;
}
