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
	r.resize(k);
	return r;
}

