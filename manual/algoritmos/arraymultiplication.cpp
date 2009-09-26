int num_arrays;
int p[MAX_ARRAYS];
int m[MAX_ARRAYS][MAX_ARRAYS];
int s[MAX_ARRAYS][MAX_ARRAYS];

/* MATRIX-CHAIN-ORDER (Cormen, p. 336) */
void matrix_chain_order() {
	int l, i, j, k, q;
	for(l = 2; l <= num_arrays; l++) {
		for(i = 1; i <= num_arrays - l + 1; i++) {
			j = i + l - 1;
			m[i][j] = INT_MAX;
			for(k = i; k <= j - 1; k++) {
				q = m[i][k] + m[k + 1][j] + p[i-1]*p[k]*p[j];
				if(q < m[i][j]) {
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
}


/* PRINT-OPTIMAL-PARENS (Cormen, p. 338) */
void print_optimal_parens(int i, int j) {
	if(i == j)
		printf("A%d", i);
	else {
		printf("(");
		print_optimal_parens(i, s[i][j]);
		printf(" x ");
		print_optimal_parens(s[i][j] + 1, j);
		printf(")");
	}
}
