#include <cstdio>
int min(int x, int y){ return x < y ? x : y; }
int max(int x, int y){ return x > y ? x : y; }
int w;
struct interval {
	int a, b;
} v[2];
int main(void){
	int A1, A2, A3, A4, t;
	int a1, a2, a3, b1, b2, b3;
	scanf("%d", &t);
	double ans, p, x, y;
	for(int cnum = 0; cnum++ < t; ){
		scanf("%d %d %d %d %d", &v[0].a, &v[0].b, &v[1].a, &v[1].b, &w);
		A1 = A2 = A3 = A4 = 0;
		a1 = max(v[0].a, v[1].a - w);
		b1 = min(v[0].b, v[1].a + w);		
		if(a1 < b1) A1 = ((a1 - v[1].a + w) + (b1 - v[1].a + w)) * (b1 - a1);
		a2 = max(v[0].a, v[1].a + w);
		b2 = min(v[0].b, v[1].b - w);
		if(a2 < b2) A2 = (b2 - a2) * (w << 1);
		a3 = max(v[0].a, v[1].b - w);
		b3 = min(v[0].b, v[1].b + w);
		if(a3 < b3) A3 = ((v[1].b + w - a3) + (v[1].b + w - b3)) * (b3 - a3);
		if(a3 < b1) A4 = (a3 - b1) * (w << 1);
		ans = (A1/2. + A2 + A3/2. + A4);
		p = ans / (double)((v[0].b - v[0].a) * (v[1].b - v[1].a));
		printf("Case #%d: %.10lf\n", cnum, p);
	}
	return 0;
}
