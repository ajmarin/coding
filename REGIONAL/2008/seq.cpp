#include <cstdio>

#define N 1024

int c, r;
int m[N][N], l[N][N];
int ans;

int main(void) {
	int i, j, k;
	int h, maxh, a;

	while(scanf("%d %d", &r, &c)) {
		if(r == 0 && c == 0) break;

		/* input */
		for(i = 0; i < r; i++) {
			l[i][c-1] = 1;
			for(j = 0; j < c; j++)
				scanf("%d", &m[i][j]);
		}

		/* computa l[][] */
		for(i = 0; i < r; i++) {
			for(j = c-2; j >= 0; j--) {
				if(m[i][j] < m[i][j+1]) l[i][j] = l[i][j+1] + 1;
				else l[i][j] = 1;
			}
		}

		/* processa */
		ans = 0;
		for(i = 0; i < c; i++) {
			for(j = i; j < c; j++) {
				if(r*(j-i+1) < ans) continue; /* sem = TLE */
				h = maxh = 0;
				for(k = 0; k < r; k++) {
					if(l[k][i] >= j-i+1) {
						if(k > 0 && m[k][i] > m[k-1][j]) h++;
						else h = 1;
						if(h > maxh) maxh = h;
					} else {
						h = 0;
					}
				}
				if(maxh*(c-i) < ans) break; /* sem = TLE */
				a = maxh*(j-i+1);
				if(a > ans) ans = a;
			}
		}

		/* output */
		printf("%d\n", ans);
	}

	return 0;
}
