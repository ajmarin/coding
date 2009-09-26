void mergesort(int a[], int n) {
	int i, j, k, s[NN], f = n/2;
	if(n <= 1) return;

	/* ordena metades */
	mergesort(a, f);
	mergesort(a+f, n-f);

	/* merge */
	for(i = 0, j = f, k = 0; i < f && j < n; k++)
		if(a[i] <= a[j]) s[k] = a[i++];
		else s[k] = a[j++], c += f-i;
	while(i < f) s[k++] = a[i++];
	while(j < n) s[k++] = a[j++];
	for(i = 0; i < n; i++) a[i] = s[i];
}
