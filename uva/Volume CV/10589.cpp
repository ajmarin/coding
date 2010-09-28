#include <cstdio>

#include <algorithm> 
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
/* }}} */
int main(void){
	int a, cnt, n;
	double x, y;
	p2d p[4], px;
	while(scanf("%d %d", &n, &a) && n){
		double asq = a * a;
		cnt = 0;
		p[0] = p2d(0., 0.);
		p[1] = p2d(0., (double)a);
		p[2] = p2d((double)a, 0.);
		p[3] = p2d((double)a, (double)a);
		for(int i = 0; i < n; ++i){
			bool ok = 1;
			scanf("%lf %lf", &x, &y);
			px = p2d(x, y);
			for(int j = 0; ok && j < 4; ++j)
				ok &= p[j].dist(px) <= a;
			cnt += ok;
		}
		printf("%.5lf\n", (asq * cnt)/n);
	}
	return 0;
}

