#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#define EPS 1e-15
#define DBGR
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
	double ang(p2d p){ return acos((*this ^ p)/((*this).mod() * p.mod())); }
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
void calc_tangent(double xp, double yp, double r, p2d *p1, p2d *p2){
	double a, b, c, r2, delta, xp2, yp2;
	r2 = r * r;
	xp2 = xp * xp;
	yp2 = yp * yp;
	double x1, x2, y1, y2;
	a = xp2 + yp2;
	if(fabs(xp) > EPS){
		b = - 2 * r2 * yp;
		c = r2 *(r2 - xp2);
		delta = sqrt(b * b - 4 * a * c);
		y1 = (-b + delta)/(2 * a);
		x1 = (r2 - yp * y1)/xp;
		y2 = (-b - delta)/(2 * a);
		x2 = (r2 - yp * y2)/xp;
	} else {
		b = - 2 * r2 * xp;
		c = r2 * (r2 - yp2);
		delta = sqrt(b * b - 4 * a * c);
		x1 = (-b + delta)/(2 * a);
		y1 = (r2 - xp * x1)/yp;
		x2 = (-b - delta)/(2 * a);
		y2 = (r2 - xp * x2)/yp;
	}
	*p1 = p2d(x1, y1);
	*p2 = p2d(x2, y2);
}
double calc_arc(p2d p1, p2d p2){
	return p1.ang(p2);
}
int main(void){
	int t; double r, x0, x1, y0, y1;
	for(scanf("%d", &t); t-- && scanf("%lf %lf %lf %lf %lf", &x0, &y0, &x1, &y1, &r) == 5; ){
		p2d orig = p2d(0, 0), p0 = p2d(x0, y0), p1 = p2d(x1, y1);
		double dist = orig.point_line_segment_distance(p0, p1);
		if(dist < r){
			p2d t1, t2, t3, t4;
			double arc = 2e15, temp;
			calc_tangent(x0, y0, r, &t1, &t2);
			calc_tangent(x1, y1, r, &t3, &t4);
			arc = min(arc, calc_arc(t1, t3));
			arc = min(arc, calc_arc(t1, t4));
			arc = min(arc, calc_arc(t2, t3));
			arc = min(arc, calc_arc(t2, t4));
			printf("%.3lf\n", p0.dist(t1) + p1.dist(t3) + arc * r);
		} else printf("%.3lf\n", p0.dist(p1));
	}
	return 0;
}

