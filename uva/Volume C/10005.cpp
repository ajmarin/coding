#include <algorithm> 
#include <cstdio>
#include <cmath>
using namespace std;
/* Point 2d {{{ */
#define EPS 1e-9
typedef double dat;
struct p2d {
	dat x, y;
	p2d operator+(p2d p) { return p2d(x + p.x, y + p.y); }
	p2d operator-(p2d p) { return p2d(x - p.x, y - p.y); }
	p2d operator*(dat k) { return p2d(k * x, k * y); }
	p2d operator/(dat k){ return p2d(x / k, y / k); }
	dat  operator*(p2d p){ return (x * p.y - y * p.x);}
	dat operator^(p2d p){ return (x * p.x + y * p.y);}
	bool operator==(p2d p){ return (x == p.x && y == p.y);}
	bool operator<(p2d p) const { return (x < p.x || (x == p.x && y < p.y));}
	bool operator>(p2d p) const { return (x > p.x || (x == p.x && y > p.y));}
	bool point_on_line(p2d p0, p2d p1){ return ((p1 - p0) * ((*this) - p0)) == 0;}
	dat sqr(dat x){ return (x * x);}
	double dist(p2d p){ return hypot(x - p.x, y - p.y); }
	double dist2(p2d p){ return sqr(x - p.x) + sqr(y - p.y);}
	double mod(){ return sqrt(x * x + y * y); }
	double mod2(){ return (x * x + y * y); }
	double ang(p2d &p){ return acos((*this ^ p)/((*this).mod() * p.mod())); }
	double point_line_distance(p2d &p0, p2d &p1){
		p2d v1 = *this - p0, v2 = p1 - p0;
		double u = (v1 ^ v2)/v2.mod2();
		p2d p = p0 + v2 * u;
		return (*this).dist(p);
	}
	double point_line_segment_distance(p2d &p0, p2d &p1){
		p2d v1 = *this - p0, v2 = p1 - p0;
		double u = (v1 ^ v2)/v2.mod2();
		if(u < 0) return (*this).dist(p0);
		if(u > 1) return (*this).dist(p1);
		return (*this).dist(p0 + v2 * u);
	}
	p2d(dat _x = 0, dat _y = 0): x(_x), y(_y) {};
};
struct l2d {
	p2d s, v;
	l2d(p2d &p0, p2d &p1){
		s = p2d(p0.x, p0.y);
		v = p1 - p0;
	}
	int line_line_intersection(l2d &line2, p2d &pi){
		p2d p1 = p2d(s.x, s.y), p2 = s + v;
		p2d p3 = p2d(line2.s.x, line2.s.y), p4 = line2.s + line2.v;
		dat den = (p1.x - p2.x) * (p3.y - p4.y) - (p3.x - p4.x) * (p1.y - p2.y);
		if(fabs(den) < EPS) return -1;
		dat x = ((p1 * p2) * (p3.x - p4.x) - (p3 * p4) * (p1.x - p2.x));
		dat y = ((p1 * p2) * (p3.y - p4.y) - (p3 * p4) * (p1.y - p2.y));
		pi = p2d(x / den, y / den);
		return 0;
	}
};
struct c2d {
	p2d center;
	double r;
	c2d(){}
	c2d(p2d p0, p2d p1, double _r){
		p2d mid = (p1 + p0)/(double)2, v = (p1 - p0);
		double q = p0.dist(p1), d = sqrt(r * r - q * q / (double) 4);
		v = v / v.mod();
		swap(v.x, v.y);
		v.x = -v.x;
		center = mid + v * d;
		r = _r;
	};
	c2d(p2d p0, p2d p1, p2d p2){

	};
};
/* }}} */
p2d p[128];
int x[128], y[128];
int sqr(int x){ return (x * x); }
int main(void){
	double r, maxd;
	for(int n, maxd2; scanf("%d", &n) && n; ){
		maxd2 = 0;
		for(int i = 0; i < n; ++i){
			scanf("%d %d", &x[i], &y[i]);
			p[i] = p2d(x[i], y[i]);
		}
		scanf("%lf", &r);
		maxd = sqrt(maxd2);
		bool ok = 0;
		for(int i = 0; !ok && i < n; ++i){
			for(int j = 0; !ok && j < n; ++j){
				if(i == j) continue;
				c2d circle = c2d(p[i], p[j], r);
				ok = 1;
				for(int k = 0; ok && k < n; ++k)
					ok &= circle.center.dist(p[k]) <= r;
			}
		}
		if(ok) puts("The polygon can be packed in the circle.");
		else puts("There is no way of packing that polygon.");
	}
	return 0;
}

