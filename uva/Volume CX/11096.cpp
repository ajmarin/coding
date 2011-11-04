#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long int LL;
LL sqr(LL a){ return a * a; }
struct point {
	LL x, y;
	point(LL _x = 0, LL _y = 0): x(_x), y(_y) {}
	LL operator*(const point& p) const { return x * p.y - y * p.x; }
	point operator-(const point& p) const { return point(x - p.x, y - p.y); };
	point operator+(const point& p) const { return point(x + p.x, y + p.y); };
	bool operator<(const point& p) const { return x < p.x || (x == p.x && y < p.y); }
	bool operator==(const point& p) const { return x == p.x && y == p.y; }
	bool operator!=(const point& p) const { return !(*this == p); }
	double dist(const point& p) const { return sqrt(sqr(x - p.x) + sqr(y - p.y)); }
};
LL cross(const point& O, const point& A, const point& B){
	return (A - O) * (B - O);
}
vector<point> convex_hull(vector<point>& P){
	int n = P.size(), k = 0;
	vector<point> r(2*n);
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
int main(void){
	int n, t; scanf("%d", &t);
	double len;
	while(t-- && scanf("%lf%d", &len, &n) == 2){
		vector < point > ans, p;
		long long x, y;
		for(int i = 0; i < n; ++i){
			scanf("%lld %lld", &x, &y);
			p.push_back(point(x, y));
		}
		ans = convex_hull(p);
		double dist = 0;
		for(int i = 1; i < int(ans.size()); ++i) dist += ans[i].dist(ans[i - 1]);
		printf("%.5lf\n", max(len, dist));
	}
	return 0;
}

