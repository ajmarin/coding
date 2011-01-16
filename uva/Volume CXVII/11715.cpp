#include <cstdio>
#include <cmath>

double a, s, t, u, v;

double *m[4][3];
int main(void){
	m[0][0] = m[1][0] = m[2][0] = &u;
	m[1][2] = m[2][1] = m[3][1] = &a;
	m[0][1] = m[1][1] = m[3][0] = &v;
	m[2][2] = m[3][2] = &s;
	m[0][2] = &t;
	for(int cnum = 1, n; scanf("%d", &n) && n--; ++cnum){
		printf("Case %d: ", cnum);
		scanf("%lf %lf %lf", m[n][0], m[n][1], m[n][2]);
		if(n == 0){
			a = (v - u)/t;
			s = u * t + a * t * t / 2;
			printf("%.3lf %.3lf\n", s, a);
		} else if(n == 1){
			t = (v - u)/a;
			s = u * t + a * t * t / 2;
			printf("%.3lf %.3lf\n", s, t);
		} else if(n == 2){
			t = (-u + sqrt(u * u + 2 * a * s))/a;
			v = u + a * t;
			printf("%.3lf %.3lf\n", v, t);
		} else {
			u = sqrt(v * v - 2 * a * s);
			t = (v - u) / a;
			printf("%.3lf %.3lf\n", u, t);
		}
	}
	return 0;
}
