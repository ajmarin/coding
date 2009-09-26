#include <cstdio>

int ultdig(int n, int d) {
	int r = 1;
	while(d--) r *= 10;
	return n % r;
}

int grupo(int n) {
	return n == 0 ? 99/4 : (n-1)/4;
}

int main(void) {
	double v;
	int n, m;

	while(scanf("%lf %d %d", &v, &n, &m)) {
		if(v < 1E-9 && n == 0 && m == 0) break;

		if(ultdig(n, 4) == ultdig(m, 4)) printf("%.2lf\n", v*3000.0);
		else if(ultdig(n, 3) == ultdig(m, 3)) printf("%.2lf\n", v*500.0);
		else if(ultdig(n, 2) == ultdig(m, 2)) printf("%.2lf\n", v*50.0);
		else if(grupo(ultdig(n, 2)) == grupo(ultdig(m, 2))) printf("%.2lf\n", v*16.0);
		else printf("0.00\n");
	}

	return 0;
}
