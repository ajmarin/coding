#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
#define EPS	1e-9
struct point { int x, y; } p[100];
double kkk[100];
int sqr(int x){ return x * x; }
double circle(point p1, point p2, point p3){
	int den = (p3.y - p2.y) * (p1.x - p2.x) - (p2.x - p3.x) * (p2.y - p1.y);
	int num = (p3.y - p1.y) * (p2.y - p1.y) - (p3.x - p1.x) * (p1.x - p2.x);
	return num / (den * 2.);
}
bool collinear(point p1, point p2, point p3){
	return (p2.x - p1.x) * (p3.y - p2.y) == (p2.y - p1.y) * (p3.x - p2.x);
}
int main(void){
	for(int N; scanf("%d", &N) == 1 && N; ){
		int ans = min(N, 2);
		for(int i = 0; i < N; ++i) scanf("%d %d", &p[i].x, &p[i].y);
		for(int i = 0; i < N; ++i)
			for(int j = i + 1; j < N; ++j){
				int cc = 0;
				for(int k = i + 1; k < N; ++k)
					if(!collinear(p[i], p[j], p[k])) kkk[cc++] = circle(p[k], p[i], p[j]);
				sort(kkk, kkk + cc);
				for(int r = 0, z = 0; r < cc && z < cc; ){
					while(z < cc && fabs(kkk[z] - kkk[r]) < EPS) ++z;
					ans = max(ans, z - r + 2);
					r = z;
				}
			}
		printf("%d\n", ans);
	}
	return 0;
}

