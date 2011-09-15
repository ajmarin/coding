#include <algorithm>
#include <cstdio>
using namespace std;
const int NN = 128;
#define FOR(i,n)	for(int i = 0; i < n; ++i)
#define FORI(i,s,n)	for(int i = s; i < n; ++i)
struct point {
	int x, y;
	point(int _x = 0, int _y = 0): x(_x), y(_y) {}
	point operator-(const point& p) const { return point(x - p.x, y - p.y); }
	int cross(const point& p) const { return (x * p.y) - (y * p.x); }
} pL[NN], pR[NN];

int match[NN];

bool ccw(point& a, point& b, point& c){
	return ((b - a).cross(c - a) < 0);
}
bool intersect(point& a, point& b, point& c, point& d){
	return(ccw(a,c,d) != ccw(b,c,d) && ccw(a,b,c) != ccw(a,b,d));
}

int main(void){
	for(int f(0), n; scanf("%d", &n) == 1; ++f){
		if(f) puts("");
		FOR(i, n) scanf("%d %d", &pL[i].x, &pL[i].y);
		FOR(i, n) scanf("%d %d", &pR[i].x, &pR[i].y);
		FOR(i, n) match[i] = i;
		while(true){
			bool done = true;
			FOR(i, n) FORI(j, i + 1, n)
				if(intersect(pL[i], pR[match[i]], pL[j], pR[match[j]]))
					swap(match[i], match[j]), done = false;
			if(done) break;
		}
		FOR(i, n) printf("%d\n", match[i]+1); } 
	return 0;
}

