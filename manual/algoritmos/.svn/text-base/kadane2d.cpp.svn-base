int kadane2d(int a[N][N], int n) {
	int i, j, k, maxsum = 0;

	for(i = 0; i < n; i++) {
		int p[N];
		for(j = 0; j < n; j++) p[j] = 0;
		for(j = i; j < n; j++) {
			int sum;
			for(k = 0; k < n; k++) p[k] += a[j][k];
			/* p[k] = soma da coluna k, da linha i ate a linha j */
			sum = kadane(p, n);
			if(sum > maxsum) maxsum = sum;
		}
	}

	return maxsum;
}
