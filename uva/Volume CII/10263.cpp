#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
/* Point 2d {{{ */
typedef double pdata;
struct p2d {
	pdata x, y;
	p2d operator+(p2d p){ return p2d(x + p.x, y + p.y); }
	p2d operator-(p2d p){ return p2d(x - p.x, y - p.y); }
	p2d operator*(pdata k){ return p2d(k * x, k * y); }
	p2d operator/(pdata k){ return p2d(x / k, y / k); }
	pdata  operator*(p2d p){ return (x * p.y - y * p.x);}
	pdata operator^(p2d p){ return (x * p.x + y * p.y);}
	bool operator==(p2d p){ return (x == p.x && y == p.y);}
	bool operator<(p2d p) const { return (x < p.x || (x == p.x && y < p.y));}
	bool operator>(p2d p) const { return (x > p.x || (x == p.x && y > p.y));}
	bool point_on_line(p2d p0, p2d p1){ return ((p1 - p0) * (*this - p0)) == 0;}
	pdata sqr(pdata x){ return (x * x);}
	double dist(p2d p){ return hypot(x - p.x, y - p.y); }
	double dist2(p2d p){ return sqr(x - p.x) + sqr(y - p.y);}
	double mod(){ return sqrt(x * x + y * y); }
	double mod2(){ return (x * x + y * y); }
	double point_line_distance(p2d p0, p2d p1){
		p2d v1 = *this - p0, v2 = p1 - p0;
		double u = (v1 ^ v2)/v2.mod2();
		p2d p = p0 + v2 * u;
		return (*this).dist(p);
	}
	double point_line_segment_distance(p2d p0, p2d p1){
		p2d v1 = *this - p0, v2 = p1 - p0;
		double u = (v1 ^ v2)/v2.mod2();
		if(u < 0) return (*this).dist(p0);
		if(u > 1) return (*this).dist(p1);
		return (*this).dist(p0 + v2 * u);
	}
	p2d(pdata _x = 0, pdata _y = 0): x(_x), y(_y) {};
};
/* }}} */
p2d ans;
double mind;
double point_line_segment_distance(p2d p2, p2d p0, p2d p1){
	p2d v1 = p2 - p0, v2 = p1 - p0;
	double u = (v1 ^ v2)/v2.mod2();
	double d0 = p2.dist(p0 + v2 * u);
	double d1 = p2.dist(p0);
	double d2 = p2.dist(p1);
	if(u < 0){
		if(d1 < mind) mind = d1, ans = p0;
		return d1;
	}
	if(u > 1){
		if(d2 < mind) mind = d2, ans = p1;
		return d2;
	}
	if(d0 < mind) mind = d0, ans = p0 + v2 * u;
	return d0;
}
int main(void){
	int n;
	double xf, xm, xt, yf, ym, yt;
	while(scanf("%lf %lf", &xm, &ym) == 2){
		mind = 2e15;
		scanf("%d", &n);
		for(int i = 0; i <= n; ++i){
			xf = xt, yf = yt;
			scanf("%lf %lf", &xt, &yt);
			if(i) point_line_segment_distance(p2d(xm, ym), p2d(xf, yf), p2d(xt, yt));
		}
		printf("%.4lf\n%.4lf\n", ans.x, ans.y);
	}
	return 0;
}


