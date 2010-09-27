#include <algorithm>
#include <cmath>
#include <cstdio>
#define EPS 1e-9
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
	bool operator==(p2d p){ return (fabs(x - p.x) < EPS && fabs(y - p.y) < EPS);}
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
int main(void){
	double x0, x1, x2, x3, y0, y1, y2, y3;
	while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &x0, &y0, &x1, &y1, &x2, &y2, &x3, &y3) == 8){
		p2d p0 = p2d(x0, y0);
		p2d p1 = p2d(x1, y1);
		p2d p2 = p2d(x2, y2);
		p2d p3 = p2d(x3, y3);
		p2d ans = p2d(0.0, 0.0);
		if(p0 == p2) ans = p1 + p3 - p0;
		else if(p0 == p3) ans = p1 + p2 - p0;
		else if(p1 == p2) ans = p0 + p3 - p1;
		else if(p1 == p3) ans = p0 + p2 - p1;
		printf("%.3lf %.3lf\n", ans.x, ans.y);
	}
	return 0;
}

