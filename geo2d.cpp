#include <cmath>
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

