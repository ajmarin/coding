#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

struct point {
	int x, y;
	point(int _x = 0, int _y = 0): x(_x), y(_y) {}
	int operator*(const point& p) const { return x * p.y - y * p.x; }
	point operator-(const point& p) const { return point(x - p.x, y - p.y); };
	point operator+(const point& p) const { return point(x + p.x, y + p.y); };
	bool operator<(const point& p) const { return x < p.x || (x == p.x && y < p.y); }
	bool operator==(const point& p) const { return x == p.x && y == p.y; }
	bool operator!=(const point& p) const { return !(*this == p); }
};
int cross(const point& O, const point& A, const point& B){
	return (A - O) * (B - O);
}
vector<point> convex_hull(vector<point> P){
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
	r.resize(k - 1);
	return r;
}
int main(void){
	char line[1024];
	for(bool first = true; gets(line); first = false){
		if(!first) puts("");
		int x, y;
		vector < point > ans, p;
		do {
			if(sscanf(line, "%d, %d", &x, &y) != 2) break;
			p.push_back(point(x, y));
		} while(gets(line));
		ans = convex_hull(p);
		int sz = ans.size(), start_at = -1, z = p.size();
		for(int i = 0, j; i < sz; ++i){
			for(j = 0; p[j] != ans[i]; ++j);
			if(j < z) start_at = i, z = j;
		}
		for(int i = 0; i <= sz; ++i){
			point pans = ans[(start_at + i) % sz];
			printf("%d, %d\n", pans.x, pans.y);
		}
	}
	return 0;
}

