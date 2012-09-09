#include <cstdio>
using namespace std;
#define FOR(i,n)	for(int i = 0; i < n; ++i)
struct point {
	int x, y;
	point(int _x = 0, int _y = 0): x(_x), y(_y) {}
	point operator-(const point& p) const { return point(x - p.x, y - p.y); }
	int cross(const point& p) const { return (x * p.y) - (y * p.x); }
} p[1024], wildcard;

bool ccw(point& a, point& b, point& c){
	return ((b - a).cross(c - a) < 0);
}
bool intersect(point& a, point& b, point& c, point& d){
	return(ccw(a,c,d) != ccw(b,c,d) && ccw(a,b,c) != ccw(a,b,d));
}

int main(void){
	for(int cnt, n; scanf("%d", &n) == 1 && n; ){
		FOR(i, n) scanf("%d %d", &p[i].x, &p[i].y);
		scanf("%d %d", &p[n].x, &p[n].y);
		wildcard = point(p[n].x, -10002);
		cnt = 0;
		FOR(i, n) cnt += intersect(p[i], p[(i + 1) % n], p[n], wildcard);
		puts(cnt & 1 ? "T" : "F");
	}
	return 0;
}

