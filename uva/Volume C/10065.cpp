#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

template <class _T> _T sqr(_T a){ return a * a; }
template <class _T> struct point {
	_T x, y;
	point(double _x = 0, double _y = 0): x(_x), y(_y) {}
	_T operator*(const point<_T>& p) const { return x * p.y - y * p.x; }
	point operator-(const point<_T>& p) const { return point(x - p.x, y - p.y); };
	point operator+(const point<_T>& p) const { return point(x + p.x, y + p.y); };
	bool operator<(const point<_T>& p) const { return x < p.x || (x == p.x && y < p.y); }
	bool operator==(const point<_T>& p) const { return x == p.x && y == p.y; }
	bool operator!=(const point<_T>& p) const { return !(*this == p); }
	double dist(const point<_T>& p) const { return sqrt(sqr(x - p.x) + sqr(y - p.y)); }
};
template <class _T> 
_T cross(const point<_T>& O, const point<_T>& A, const point<_T>& B){
	return (A - O) * (B - O);
}
template <class _T>
vector< point<_T> > convex_hull(vector< point<_T> >& P){
	int n = P.size(), k = 0;
	vector< point<_T> > r(2*n);
	sort(P.begin(), P.end());
	// Build lower hull
	for(int i = 0; i < n; ++i){
		while(k >= 2 && cross(r[k - 2], r[k - 1], P[i]) <= 0) --k;
		r[k++] = P[i];
	}
	// Build upper hull
	for(int i = n - 2, t = k + 1; i >= 0; --i){
		while(k >= t && cross(r[k - 2], r[k - 1], P[i]) <= 0) --k;
		r[k++] = P[i];
	}
	r.resize(k-1);
	return r;
}
template <class _T>
double get_area(const vector< point<_T> > P){
	int area = 0, n = P.size();
	for(int i = 1; i < (n - 1); ++i) area += cross(P[0], P[i], P[i + 1]);
	return fabs(.5 * area);
}

int main(void){
	for(int c = 1, n; scanf("%d", &n) == 1 && n; ++c){
		double internal, external;
		vector< point<int> > polygon;
		printf("Tile #%d\n", c);
		for(int i = 0, x, y; i < n; ++i){
			scanf("%d %d", &x, &y);
			polygon.push_back(point<int>(x, y));
		}
		internal = get_area(polygon);
		external = get_area(convex_hull(polygon));
		printf("Wasted Space = %.2lf %%\n\n", 100 * (1 - internal / external));
	}
	return 0;
}

