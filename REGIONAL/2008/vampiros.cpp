#include <algorithm>
#include <cstdio>
#include <cmath>

#define NN 32
#define EPS 1E-30

int lupdecomp(double a[NN][NN], double lu[NN][NN], int p[NN], int n) {
	int i, j, k, psgn = 1;
	for(i = 0; i < n; i++) {
		p[i] = i;
		for(j = 0; j < n; j++) lu[i][j] = a[i][j];
	}
	for(k = 0; k < n; k++) {
		double v = 0.0;
		int kl;
		for(i = k; i < n; i++) {
			if(fabs(lu[i][k]) - v > EPS) {
				v = fabs(lu[i][k]);
				kl = i;
			}
		}
		if(fabs(v) < EPS) return 0;
		if(k != kl) {
			std::swap(p[k], p[kl]), psgn *= -1;
			for(i = 0; i < n; i++)
				std::swap(lu[k][i], lu[kl][i]);
		}
		for(i = k+1; i < n; i++) {
			lu[i][k] /= lu[k][k];
			for(j = k+1; j < n; j++)
				lu[i][j] -= lu[i][k]*lu[k][j];
		}
	}
	return psgn;
}

void linearsolve(double a[NN][NN], double b[NN], double x[NN], int n) {
	double lu[NN][NN], y[NN], sum;
	int i, j, p[NN];
	lupdecomp(a, lu, p, n);
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

double a[NN][NN], b[NN], x[NN], p;
int ev1, ev2, at, d, n;

int main(void) {
	int i, j;
	while(scanf("%d %d %d %d", &ev1, &ev2, &at, &d)) {
		if(ev1 == 0 && ev2 == 0 && at == 0 && d == 0) break;
		n = ev1 + ev2;
		p = at/6.0;
		for(i = 0; i < n; i++) {
			if(i < d) b[i] = p;
			else b[i] = 0.0;
			for(j = 0; j < n; j++) {
				if(i == j) a[i][j] = 1.0;
				else if(j == i-d) a[i][j] = -p;
				else if(j == i+d) a[i][j] = -(1-p);
				else a[i][j] = 0.0;
			}
		}
		linearsolve(a, b, x, n-1);
		printf("%.1lf\n", x[n - ev1 - 1]*100.0);
	}

	return 0;
}
