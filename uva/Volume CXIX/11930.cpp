#include <algorithm>
#include <cstdio>
#define FOR(i,n) for(int i = 0; i < n; ++i)
#define DIAG(i,x) ((i << 2) + (x << 1))
using namespace std;
typedef long long LL;
const int NN = 2000;

/* Geometry {{{ */
// Returns 1 if a > b, 0 if a == b and -1 if a < b
template <typename _T> int Cmp(_T a, _T b){ return (a > b) - (a < b); }

template <typename _T>
struct Point {
	_T x, y;
	Point(_T _x = 0, _T _y = 0): x(_x), y(_y) {}
	Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }
	Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
	_T Dot(const Point& p) const { return x * p.x + y * p.y; }
	_T Cross(const Point& p) const { return x * p.y - y * p.x; }
	bool operator==(const Point& p) const { return !Cmp(x, p.x) && !Cmp(y, p.y); }
	bool operator!=(const Point& p) const { return !( *this == p ); }
	bool operator<(const Point& p) const {
		int c = Cmp(x, p.x);
		return c < 0 || (!c && Cmp(y, p.y) < 0);
	}
};

template <typename _T>
bool InInterval(Point<_T>& p, Point<_T>& b, Point<_T>& e){
	if(p.x < min(b.x, e.x) || p.x > max(b.x, e.x)) return false;
	if(p.y < min(b.y, e.y) || p.y > max(b.y, e.y)) return false;
	return true;
}

template <typename _T>
bool SegmentIntersect(Point<_T>& p1, Point<_T>& p2, Point<_T>& p3, Point<_T>& p4){
	Point<_T> _u = p2 - p1, _v = p4 - p3;
	int d1 = Cmp( _u.Cross(p3 - p1), _T(0)), d2 = Cmp( _u.Cross(p4 - p1), _T(0));
	int d3 = Cmp( _v.Cross(p1 - p3), _T(0)), d4 = Cmp( _v.Cross(p2 - p3), _T(0));
	if(d1 * d2 < 0 && d3 * d4 < 0) return true;
	if(d1 == 0 && InInterval(p3, p1, p2)) return true;
	if(d2 == 0 && InInterval(p4, p1, p2)) return true;
	if(d3 == 0 && InInterval(p1, p3, p4)) return true;
	if(d4 == 0 && InInterval(p2, p3, p4)) return true;
	return false;
}

template <typename _T>
struct Rectangle {
	Point<_T> p[4];
	Rectangle(){}
};
/* }}} */

/* Edges {{{ */
int next[NN], ecnt;
struct edge {
	int from, to, next;
} e[NN*NN];
void insert_edge(int from, int to){
	e[ecnt].from = from;
	e[ecnt].to = to;
	e[ecnt].next = next[from];
	next[from] = ecnt++;
}
/* }}} */

/* Tarjan's SCC {{{ */
int n;
int num[NN], low[NN], scc[NN];
int cnt, scccnt;
int s[NN], top;

void dfs(int u) {
	num[u] = low[u] = cnt++;
	s[top++] = u;
	for(int i = next[u]; i != -1; i = e[i].next) {
		int v = e[i].to;
		if(num[v] == -1) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else if(scc[v] == -1) {
			low[u] = min(low[u], num[v]);
		}
	}

	if(low[u] == num[u]) {
		for(int v = -1; v != u; ) scc[v = s[--top]] = scccnt;
		scccnt++;
	}
}

void findscc(void) {
	for(int i = 0; i < n; i++) num[i] = scc[i] = -1;
	scccnt = top = 0;
	for(int i = 0; i < n; i++)
		if(num[i] == -1) cnt = 0, dfs(i);
}
/* }}} */

int main(void){
	Rectangle<LL> vr[1024];
	while(scanf("%d", &n) == 1 && n){
		bool possible = true;
		for(int i = 0; i < (n<<1); ++i) next[i] = -1;
		ecnt = 0;
		FOR(i, n){
			FOR(j, 4) scanf("%lld %lld", &vr[i].p[j].x, &vr[i].p[j].y);
			sort(vr[i].p, vr[i].p + 4);
			FOR(j, i) FOR(k, 2) FOR(l, 2)
				if(SegmentIntersect(vr[i].p[k], vr[i].p[3-k], vr[j].p[l], vr[j].p[3-l])){
					insert_edge(2*i + k, 2*j + !l);
					insert_edge(2*j + l, 2*i + !k);
				}
		}
		n <<= 1;
		findscc();
		for(int i = 0; possible && i < n; i += 2) possible &= scc[i] != scc[i + 1];
		puts(possible ? "YES" : "NO");
	}
	return 0;
}

