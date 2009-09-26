void quicksort(int d[], int n) {
	if(n > 1) {
		int piv = d[0], l = 1, r = n;
		int tmp;

		while(l < r) {
			if(d[l] <= piv) {
				l++;
			} else {
				tmp = d[l];
				d[l] = d[--r];
				d[r] = tmp;
			}
		}

		tmp = d[--l];
		d[l] = d[0];
		d[0] = tmp;

		quicksort(d, l);
		quicksort(d + r, n - r);
	}
}
