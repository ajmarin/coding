#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

template <class _T> bool cmp(_T a, _T b){ return (a > b) - (a < b); }
template <class _T>
struct point {
	_T x, y;
	point(_T _x = 0, _T _y = 0): x(_x), y(_y) {}
	_T dot(const point p){ return x * p.x + y * p.y; }
	_T cross(const point p){ return x * p.y - y * p.x; }
	point operator-(point p){ return point(x - p.x, y - p.y); }
	point operator+(point p){ return point(x + p.x, y + p.y); }
	point operator/(_T div){ return point(x / div, y / div); }
	point operator*(_T mul){ return point(x * mul, y * mul); }
	double mod(){ return sqrt(x * x + y * y); }
	// Clockwise rotation from *this to p in radians [-pi, pi]
	double ang(point p){ return atan2(this -> cross(p), this -> dot(p)); }
	bool operator<(point p) const { return x < p.x || (x == p.x && y < p.y); }
	bool operator>(point p) const { return x > p.x || (x == p.x && y > p.y); }
	bool operator==(point p) const { return cmp(x, p.x) + cmp(y, p.y) == 0; }
};

template <class _T> 
_T cross(point<_T>& O, point<_T>& A, point<_T>& B){
	return (A - O).cross(B - O);
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
	r.resize(k - 1);
	return r;
}

int main(void){
	for(int n; scanf("%d", &n) == 1 && n; ){
		vector < point<int> > p(n), ch;
		for(int i = 0; i < n; ++i) scanf("%d %d", &p[i].x, &p[i].y);
		puts(convex_hull(p).size() == p.size() ? "No" : "Yes");
	}
	return 0;
}

