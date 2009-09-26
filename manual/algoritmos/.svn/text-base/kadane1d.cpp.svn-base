int kadane(int a[], int n) {
	int max = 0, s = 0;
	int i;

	for(i = 0; i < n; i++) {
		s += a[i];
		if(s < 0)
			s = 0;
		if(s > max)
			max = s;
	}

	return max;
}
