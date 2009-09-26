/* LUP-DECOMPOSITION (Cormen, p. 752) */
/* Retorna Psgn = det P (ou 0, se a matriz for singular) */
int lupdecomp(double a[NN][NN], double lu[NN][NN], int p[NN], int n) {
	int i, j, k, psgn = 1;
	/* copia A para LU */
	for(i = 0; i < n; i++) {
		p[i] = i;
		for(j = 0; j < n; j++) lu[i][j] = a[i][j];
	}
	for(k = 0; k < n; k++) {
		double v = 0.0;
		int kl;
		/* encontra o maior elemento lu[kl][k] na coluna k */
		for(i = k; i < n; i++) {
			if(fabs(lu[i][k]) - v > EPS) {
				v = fabs(lu[i][k]);
				kl = i;
			}
		}
		if(fabs(v) < EPS) return 0; /* matriz singular */
		if(k != kl) {
			/* troca linhas k e kl */
			std::swap(p[k], p[kl]), psgn *= -1;
			for(i = 0; i < n; i++)
				std::swap(lu[k][i], lu[kl][i]);
		}
		/* computa o complemento Schur */
		for(i = k+1; i < n; i++) {
			lu[i][k] /= lu[k][k];
			for(j = k+1; j < n; j++)
				lu[i][j] -= lu[i][k]*lu[k][j];
		}
	}
	return psgn;
}
