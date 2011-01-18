#include <cmath>
#include <cstdio>
#include <ctime>

struct point {
	int x, y;
	point(int _x = 0, int _y = 0): x(_x), y(_y) {}
	int operator*(const point p){ return x * p.y - y * p.x; }
	point operator -(const point p){ return point(x - p.x, y - p.y); }
} o, A, B, C;
int abs(int a){ return a > 0 ? a : -a; }
int area(point a, point b, point c){ return abs((b - a) * (c - a)); }
int main(void){
	clock_t ini = clock();
	int a1, a2, ans = 0;
	freopen("triangles.txt", "r", stdin);
	while(scanf("%d,%d,%d,%d,%d,%d", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y) == 6)
		ans += area(A, B, C) == area(o, A, B) + area(o, B, C) + area(o, C, A);
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}
