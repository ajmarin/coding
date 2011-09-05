#include <cassert>
#include <cmath>
#include <cstdio>

template <typename _T> bool cmp(_T a, _T b){ return (a > b) - (a < b); }
template <typename _T>
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

template <typename _T>
struct line {
	point<_T> p0, v;
	bool operator==(line l){ return p0 == l.p0 && v == l.v; }
};

template <typename _T>
struct circle {

};

int main(void){
	// Orthogonal vectors have dot product 0
	assert(point<int>(1,0).dot(point<int>(0,1)) == 0);
	assert(point<int>(2,-3).dot(point<int>(3,2)) == 0);
	// Parallel vectors have cross product 0
	assert(point<int>(1,1).cross(point<int>(3,3)) == 0);
	// Simple operations + comparison tests
	assert(point<int>(1,1) + point<int>(2,5) == point<int>(3,6));
	assert(point<int>(5,2) - point<int>(2,5) == point<int>(3,-3));
	assert(point<int>(5,5)/5 == point<int>(1,1));
	assert(point<int>(2,3) * 7 == point<int>(14,21));
	assert(point<int>(1,2) > point<int>(0,99));
	assert(point<int>(1,3) > point<int>(1,2));
	assert(point<int>(0,99) < point<int>(1,1));
	assert(point<int>(0,1) < point<int>(0,3));
	// Vector (1,0) rotated cw 90 degrees is vector (1,0)
	assert(!cmp(point<int>(1,0).ang(point<int>(0,1)), acos(-1)/2.0));
	// Vector (0,1) rotated ccw 90 degrees is vector (1,0)
	assert(!cmp(point<int>(0,1).ang(point<int>(1,0)), -acos(-1)/2.0));
	puts("TEST SUCCEEDED");
	return 0;
}

