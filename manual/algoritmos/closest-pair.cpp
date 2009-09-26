#define INF 1E100
#define EPS 1E-10

int n;
point p[NN]; /* cuidado! input deve ser global */

bool xcmp(point a, point b) { return a.x < b.x; }
bool ycmp(int a, int b) { return p[a].y < p[b].y; }

double cpsolve(int a[NN], int l, int r) {
	int i, j, k, n = r-l, q = (l+r)/2;

	if(n <= 1) return INF;
	if(n == 2) return distsqr(p[a[0]], p[a[1]]);

	/* divida */
	int b[NN];
	for(i = k = 0, j = q-l; k < n; k++)
		if(a[k] <= q && i < q-l) b[i++] = a[k];
		else b[j++] = a[k];

	/* conquiste */
	double ans;
	ans = min(cpsolve(b, l, q), cpsolve(b+q-l, q+1, r));

	/* combine */
	int f[NN], t = 0;
	for(k = 0; k < n; k++)
		if(fabs(p[a[k]].x - p[q].x) - ans < EPS)
			f[t++] = a[k];
	for(i = 0; i < t; i++)
		for(j = min(i+7, t-1); j > i; j--)
			ans = min(ans, distsqr(p[f[i]], p[f[j]]));

	return ans;
}

double closestpair() {
	int i, a[NN];
	for(i = 0; i < n; i++) a[i] = i;
	sort(p, p+n, xcmp);
	sort(a, a+n, ycmp);
	return sqrt(cpsolve(a, 0, n));
}
