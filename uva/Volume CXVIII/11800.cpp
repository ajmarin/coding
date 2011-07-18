#include <algorithm>
#include <cmath>
#include <cstdio>

int sqr(int a){ return a * a; }

struct point {
	int x, y;
	point(int _x = 0, int _y = 0): x(_x), y(_y) {}
	int dist(point& p){ return sqr(dx(p)) + sqr(dy(p)); }
	int dx(point& p){ return x - p.x; }
	int dy(point& p){ return y - p.y; }
	double mod(){ return sqrt(sqr(x) + sqr(y)); }
	double angle(point p){
#ifdef DBGANGLE
		printf("(%d, %d).(%d, %d) = ", x, y, p.x, p.y);
		double dotmod = (*this ^ p) / mod() / p.mod();
		printf(" %.3lf --> %.3lf\n", dotmod, acos(dotmod));
#endif
		return acos((*this ^ p) / mod() / p.mod());
	}
	int parallel(point p){ return !(*this * p); }
	int operator^(point p){ return x * p.x + y * p.y; }
	int operator*(point p){ return x * p.y - y * p.x; }
	point operator-(point& p){ return point(x - p.x, y - p.y); }
	bool operator<(point& p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
} p[6];


const double conv = 180 / acos(-1);
const double EPS = 1e-8;
int d[4];
double angle[4];
bool ccw(point a, point b){
	return (a - p[0]) * (b - p[0]) > 0;
}
bool eq(double a, double b){
	return fabs(a - b) < EPS;
}
int main(void){
	int t; scanf("%d", &t);
	for(int cnum = 0; cnum++ < t; ){
		bool sqr = true, rct = true, rhb = true, plg = true, tpz = true;
		for(int i = 0; i < 4; ++i) scanf("%d %d", &p[i].x, &p[i].y);
		point pivot = point(1<<20, 1<<20); int idx = -1;
		for(int i = 0; i < 4; ++i) if(p[i] < pivot) pivot = p[i], idx = i;
		std::swap(p[0], p[idx]);
		std::sort(p + 1, p + 4, ccw);
		p[4].x = p[0].x, p[4].y = p[0].y;
		for(int i = 0; i < 4; ++i){
			d[i] = p[i].dist(p[i + 1]);
			if(i < 3) angle[i] = conv * (p[i + 1] - p[i]).angle(p[i + 2] - p[i + 1]);
			else angle[i] = 360 - (angle[0] + angle[1] + angle[2]);
#ifdef DBGANGLE
			printf("angle[i] = %.3lf\n", angle[i]);
#endif
			sqr &= (!i || d[i] == d[i - 1]) && eq(90, angle[i]);
			rct &= eq(90, angle[i]);
			rhb &= (!i || d[i] == d[i - 1]) && !eq(90, angle[i]);
			plg &= !eq(90, angle[i]);
		}
		bool pll1 = (p[1] - p[0]).parallel(p[2] - p[3]);
		bool pll2 = (p[2] - p[1]).parallel(p[3] - p[0]);
		rct &= d[0] == d[2] && d[1] == d[3];
		rhb &= eq(angle[0], angle[2]) && eq(angle[1], angle[3]);
		plg &= d[0] == d[2] && d[1] == d[3];
		tpz &= (pll1 && !pll2) || (pll2 && !pll1);
		printf("Case %d: ", cnum);
		if(sqr) puts("Square");
		else if(rct) puts("Rectangle");
		else if(rhb) puts("Rhombus");
		else if(plg) puts("Parallelogram");
		else if(tpz) puts("Trapezium");
		else puts("Ordinary Quadrilateral");
	}
	return 0;
}
