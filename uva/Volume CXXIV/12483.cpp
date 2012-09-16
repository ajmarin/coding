#include <algorithm>
#include <cmath>
#include <cstdio>

#define EPS 1e-9
using namespace std;

typedef double dat;
const int N = 1024;
dat sqr(dat x){ return x * x; }

struct p2d {
	dat x, y;

	p2d(dat _x = 0, dat _y = 0): x(_x), y(_y) {}
	p2d operator+(p2d p){ return p2d(x + p.x, y + p.y); }
	p2d operator-(p2d p){ return p2d(x - p.x, y - p.y); }
	p2d operator*(dat k){ return p2d(x * k, y * k); }
	dat operator^(p2d p){ return x * p.x + y * p.y; }
	double dist(p2d p){ return hypot(x - p.x, y - p.y); }
	double mod2() { return x * x + y * y; }
	double point_line_segment_distance(p2d p0, p2d p1){
		p2d v1 = *this - p0, v2 = p1 - p0;
		double u = (v1 ^ v2) / v2.mod2();
		if(u < -EPS) return (*this).dist(p0);
		if(u - 1 > EPS) return (*this).dist(p1);
		return (*this).dist(p0 + v2 * u);
	}
} p[N][2];

int main(void){
	double L, H;
	for(int n; scanf("%d", &n) == 1; ){
		scanf("%lf %lf", &L, &H);
		for(int i = 0; i < n; ++i){
			p[i][0].x = i & 1 ? L : 0;
			scanf("%lf %lf %lf", &p[i][0].y, &p[i][1].x, &p[i][1].y);
		}
		double r = L;
		for(int i = 0; i < n; ++i){
			r = min(r, i & 1 ? p[i][1].x : L - p[i][1].x);
			if(i != n - 1)
				r = min(r, p[i][1].point_line_segment_distance(p[i + 1][0], p[i + 1][1]));
		}
		printf("%.2lf\n", r);
	}
	return 0;
}

