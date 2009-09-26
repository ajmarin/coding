/* LUP-SOLVE (Cormen, p. 745) */
void linearsolve(double a[NN][NN], double b[NN], double x[NN], int n) {
	double lu[NN][NN], y[NN], sum;
	int i, j, p[NN];
	lupdecomp(a, lu, p, n); /* cuidado, supoe que eh invertivel */
	sum = 0.0;
	for(i = 0; i < n; i++) {
		y[i] = b[p[i]];
		for(j = 0; j < i; j++) y[i] -= lu[i][j]*y[j];
	}
	for(i = n-1; i >= 0; i--) {
		x[i] = y[i];
		for(j = i+1; j < n; j++) x[i] -= lu[i][j]*x[j];
		x[i] /= lu[i][i];
	}
}
