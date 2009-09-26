char a[WW], b[WW];
int n, m; /* n = strlen(a), m = strlen(b) */
int c[WW+1][WW+1], d[WW+1][WW+1];

void printlcs(int i, int j) {
	if(i == 0 || j == 0) return;
	if(d[i][j] == 1) {
		printlcs(i-1, j-1);
		printf("%c", a[i-1]);
	} else if(d[i][j] == 2) printlcs(i-1, j);
	else printlcs(i, j-1);
}

void computelcs() {
	int i, j;
	for(i = 0; i <= n; i++) c[i][0] = 0;
	for(j = 0; j <= m; j++) c[0][j] = 0;
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= m; j++) {
			if(a[i-1] == b[j-1]) {
				c[i][j] = c[i-1][j-1] + 1;
				d[i][j] = 1;
			} else if(c[i-1][j] >= c[i][j-1]) {
				c[i][j] = c[i-1][j];
				d[i][j] = 2;
			} else {
				c[i][j] = c[i][j-1];
				d[i][j] = 0;
			}
		}
	}
}
