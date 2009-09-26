double det(double a[NN][NN], int n) {
	int p[NN], detp;
	double lu[NN][NN], d = 1.0;
	detp = lupdecomp(a, lu, p, n);
	if(detp == 0) return 0; /* matriz singular */
	for(int i = 0; i < n; i++) d *= a[i][i];
	return d/detp;
}
