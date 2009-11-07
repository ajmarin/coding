#include <cstdio>

#define NN 10001
#define PP 101
#define BB 1300031

int t, n, p;
int d[NN][PP];

int main(void) {
	/* init */
	for(n = 0; n < NN; n++)
		for(p = 0; p < PP; p++)
			d[n][p] = 0;
	d[0][0] = 1;
	d[1][0] = 1, d[1][1] = 3, d[1][2] = 3, d[1][3] = 1;
	for(n = 2; n < NN; n++) {
		for(p = 0; p < PP && d[n-1][p]; p++) {
			for(int i = 0; i < 4 && p+i < PP; i++) {
				d[n][p+i] += (d[1][i]*d[n-1][p]) % BB;
				d[n][p+i] %= BB;
			}
		}
	}

	/* in/out */
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &n, &p);
		printf("%d\n", d[n][p]);
	}

	return 0;
}
