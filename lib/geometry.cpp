#include <cassert>
#include <cmath>
#include <cstdio>

template <typename _T>
struct point {
	_T x, y;
	point(_T _x = 0, _T _y = 0): x(_x), y(_y) {}
	_T dot(const point p){ return x * p.x + y * p.y; }
	_T cross(const point p){ return x * p.y - y * p.x; }
	point operator-(point p){ return point(x - p.x, y - p.y); }
};

int main(void){
	// Ortogonal vectors have dot product 0
	assert(point<int>(1,0).dot(point<int>(0,1)) == 0);
	assert(point<int>(2,-3).dot(point<int>(3,2)) == 0);
	// Parallel vectors have cross product 0
	assert(point<int>(1,1).cross(point<int>(3,3)) == 0);
	puts("TEST SUCCEEDED");
	return 0;
}

