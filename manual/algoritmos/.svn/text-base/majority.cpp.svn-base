int findmajority(int a[], int n) {
	int x, y, i;

	x = a[0];
	y = 1;

	for(i = 1; i < n; i++) {
		if(y >= 1) {
			if(a[i] == x) y++;
			else y--;
		} else {
			x = a[i];
			y = 1;
		}
	}

	/* verifica se eh majoritario (caso nao haja) */
	int c = 0;
	for(i = 0; i < n; i++)
		if(a[i] == x) c++;

	if(c > n/2) return x; /* tem */
	else return -1; /* nao tem */
}
