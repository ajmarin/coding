#include <cstdio>

#define FORI(a,b,c)	for(int a = b; a < c; ++a)
#define FOR(a,b)	FORI(a,0,b)

/* Geometry 2D {{{ */
#include <cmath>
#include <algorithm>
using namespace std;
#define EPS 1e-9

typedef double dat;
dat sqr(dat x) { return (x * x); }

struct p2d {
	dat x, y;
	
	p2d(dat _x = 0, dat _y = 0): x(_x), y(_y) {};

	p2d operator+(p2d p) { return p2d(x + p.x, y + p.y); }
	p2d operator-(p2d p) { return p2d(x - p.x, y - p.y); }
	p2d operator*(dat k) { return p2d(k * x, k * y); }
	p2d operator/(dat k){ return p2d(x / k, y / k); }
	dat operator*(p2d p){ return (x * p.y - y * p.x); } // cross product
	dat operator^(p2d p){ return (x * p.x + y * p.y); } // dot product

	// dat = double?
	bool operator==(p2d p){ return (x == p.x && y == p.y); }
	bool operator<(p2d p) const { return (x < p.x || (x == p.x && y < p.y)); }
	bool operator>(p2d p) const { return (x > p.x || (x == p.x && y > p.y)); }

	double dist(p2d p){ return hypot(x - p.x, y - p.y); }
	double dist2(p2d p){ return sqr(x - p.x) + sqr(y - p.y);}
	double mod(){ return sqrt(x * x + y * y); }
	double mod2(){ return (x * x + y * y); }
	double ang(p2d p){ return atan2(*this * p, *this ^ p); } // [-pi,pi]
	double point_line_segment_distance(p2d p0, p2d p1){
		p2d v1 = *this - p0, v2 = p1 - p0;
		double u = (v1 ^ v2)/v2.mod();
		if(u < -EPS) return (*this).dist(p0);
		if(u - 1 > EPS) return (*this).dist(p1);
		return (*this).dist(p0 + v2 * u);
	}
};

struct l2d {
	p2d s, v;

	l2d(){}
	l2d(p2d p0, p2d p1){
		s = p2d(p0.x, p0.y);
		v = p1 - p0, v = v/v.mod();
	}
	l2d(p2d p, double m) { s = p, v = p2d(cos(m), sin(m)); }
	l2d(double a, double b, double c) { // ax + by = c
		if(fabs(a) < EPS) v = p2d(1, -a/b), s = p2d(0, c/b);
		else v = p2d(-b/a, 1), s = p2d(c/a, 0);
	}
	bool same(l2d l){
		return fabs(v * l.v) < EPS && fabs((l.s - s) * v) < EPS;
	}

	bool point_on_line(p2d p){ return (v * (p - s)) == 0; } // dat = double?
	double slope() { return v.y/(double)v.x; }
};

// cuidado se l1 e l2 forem coincidentes
int l2d_l2d_intersection(l2d l1, l2d l2, p2d &pi){
	p2d p1 = p2d(l1.s.x, l1.s.y), p2 = l1.s + l1.v;
	p2d p3 = p2d(l2.s.x, l2.s.y), p4 = l2.s + l2.v;
	dat den = (p1.x - p2.x) * (p3.y - p4.y) - (p3.x - p4.x) * (p1.y - p2.y);
	if(fabs(den) < EPS) return 0; // linhas paralelas
	dat x = ((p1 * p2) * (p3.x - p4.x) - (p3 * p4) * (p1.x - p2.x));
	dat y = ((p1 * p2) * (p3.y - p4.y) - (p3 * p4) * (p1.y - p2.y));
	pi = p2d(x, y)/den;
	return 1; // pi = ponto de intersecao
}
/* }}} */
int main(void){
	int t; scanf("%d", &t);
	p2d p, pi, q, r, s;
	puts("INTERSECTING LINES OUTPUT");
	FOR(cc, t){
		scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &p.x, &p.y, &q.x, &q.y, &r.x, &r.y, &s.x, &s.y);
		l2d l1 = l2d(p, q), l2 = l2d(r, s);
		int k = l2d_l2d_intersection(l1, l2, pi);
		if(k) printf("POINT %.2lf %.2lf\n", pi.x, pi.y);
		else {
			if(l1.same(l2)) puts("LINE");
			else puts("NONE");
		}
	}
	puts("END OF OUTPUT");
	return 0;
}

