#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define NN 1024
#define EPS 1E-12

typedef struct { double x, y; } point;
typedef struct { point p[NN]; int n; } polygon;

point pivot;

double distsqr(point a, point b) {
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

double cross(point a, point b, point c) {
	return (b.x - a.x)*(c.y - a.y) - (c.x - a.x)*(b.y - a.y);
}

bool graham_cmp(point a, point b) {
	double t = cross(pivot, b, a);
	if(t < -EPS) return true;
	if(fabs(t) < EPS) return distsqr(pivot, a) < distsqr(pivot, b);
	return false;
}

void graham_scan(polygon &q, polygon &p) {
	vector<point> s(p.p, p.p+p.n);
	int i;

	pivot = p.p[0];
	for(i = 1; i < p.n; i++)
		if(p.p[i].y - pivot.y < EPS || (fabs(p.p[i].y - pivot.y) < EPS && p.p[i].x - pivot.x < EPS))
			pivot = p.p[i];

	sort(s.begin(), s.end(), graham_cmp);

	for(i = 2; i < (int)s.size(); i++)
		if(fabs(cross(pivot, s[i], s[i-1])) < EPS)
			s.erase(s.begin() + --i);

	q.p[0] = s[0];
	q.p[1] = s[1];
	q.p[2] = s[2];
	q.n = 3;
	for(i = 3; i < (int)s.size(); i++) {
		while(cross(q.p[q.n-2], q.p[q.n-1], s[i]) < EPS) q.n--;
		q.p[q.n++] = s[i];
	}
}

struct P{
	int x,y,z;
}p[NN];

double polygon_area(polygon q) {
	double r = 0.0;
	int i;
	for(i = 1; i < q.n-1; i++){
		double x1 = q.p[i].x - q.p[0].x;
		double y1 = q.p[i].y - q.p[0].y;
		double x2 = q.p[i+1].x - q.p[0].x;
		double y2 = q.p[i+1].y - q.p[0].y;
		r += x1*y2 - x2*y1;
	}
	return fabs(r/2.0);
}

polygon pts;
polygon ch;
int main(void){
	int i, N; 
	while(scanf("%d",&N) && N){
		for(i = 0; i <= N; i++)
			scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
		swap(p[0],p[N]);
		pts.n = N;
		for(i = 0; i < N; i++){
			double k = -p[i].z/((double)(p[N].z-p[i].z));
			pts.p[i].x = p[i].x + k*(p[N].x-p[i].x);
			pts.p[i].y = p[i].y + k*(p[N].y-p[i].y);
			//printf("k = %.3lf, %.2lf %.2lf\n", k, pts.p[i].x, pts.p[i].y);
		}

		// computa ch
		graham_scan(ch, pts);
		// computa area
		printf("%.2lf\n", polygon_area(ch));
	}

	return 0;
}
