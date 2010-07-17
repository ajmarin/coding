#include <cstdio>
#include <cstdlib>
#include <cmath>
#define EPS 0.0001
#define pi acos(-1)
struct point{
	double x, y;
	point(double _x = 0, double _y = 0){x = _x, y = _y;}	
	void norm(){
		double div = hypot(x, y);
		x /= div, y /= div;
	}
	point operator+(point p){return point(x + p.x, y + p.y);}
	point operator-(point p){return point(x - p.x, y - p.y);}
	double operator*(point p){return (x * p.x + y * p.y);}
	double operator^(point p){return (x * p.y - y * p.x);}
	point operator*(double k){return point(x * k, y * k);}
	double ang(point k){return acos(*this * k);}
	double d(point p){return hypot(x - p.x, y - p.y);}
	point rot(double a){
		double ca = cos(a), sa = sin(a);
		return point(x * ca - y * sa, x * sa + y * ca);
	}
	
};
inline double sqr(double x){ return x * x; }
point intersect(point p0, point v0, point p1, point v1){
	double aux, k;
	if(fabs(v0.x) > EPS){
		aux = v0.y / v0.x;
		k = (p0.y + (p1.x - p0.x) * aux - p1.y) / (v1.y - v1.x * aux);
		return p1 + (v1 * k);
	}
	else {
		aux = v1.y / v1.x;
		k = (p1.y + (p0.x - p1.x) * aux - p0.y) / (v0.y - v0.x * aux);
		return p0 + (v0 * k);
	}
}
double area(point A, point B, point C){
	double a = A.d(B), b = A.d(C), c = B.d(C);
	double s = (a + b + c)/2.;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}
double pld(point P, point O, point V){
	point VL = point(V.y, -V.x);
	return VL * (P - O);
}
double sa(double r, double a){
	return a * sqr(r) / 2;
}
int main(void){
	int n1, n2, n3;
	double a, b, x, y, r1, r2, r3;
	for(int cnum = 0; scanf("%d %d %d", &n1, &n2, &n3) && n1; ){
		point A, AB, AC, B, BA, BC, C, CA, CB, C1, C2, C3, V0, V1;
		A = point(0, 0);
		B = point(n1, 0);
		x = (sqr(n1) + sqr(n2) - sqr(n3))/(n1 << 1);
		y = sqrt(sqr(n2) - sqr(x));
		C = point(x, y);
		AB = B - A;
		AC = C - A;
		BC = C - B;
		BA = A - B;
		CA = A - C;
		CB = B - C;
		AB.norm(), AC.norm(), BC.norm();
		BA.norm(), CA.norm(), CB.norm();
		a = -AB.ang(CA)/2.;
		b = BA.ang(CB)/2.;
		V0 = AB.rot(a);	
		V1 = BA.rot(b);
		C1 = intersect(A, V0, B, V1);
		r1 = pld(C1, A, AB);
		a = AC.ang(BA)/2.;
		b = -CA.ang(BC)/2.;
		V0 = AC.rot(a);
		V1 = CA.rot(b);
		C2 = intersect(A, V0, C, V1);
		r2 = pld(C2, A, AC);
		a = -BC.ang(AB)/2.;
		b = CB.ang(AC)/2.;
		V0 = BC.rot(a);
		V1 = CB.rot(b);
		C3 = intersect(B, V0, C, V1);
		r3 = pld(C3, B, BC);
		point C1A = A - C1;
		point C1B = B - C1;
		point C2A = A - C2;
		point C2C = C - C2;
		point C3B = B - C3;
		point C3C = C - C3;
		C1A.norm();C1B.norm();C2A.norm();C2C.norm();C3B.norm();C3C.norm();
		double ss = sa(r1, C1A.ang(C1B)) + sa(r2, C2A.ang(C2C)) + sa(r3, C3B.ang(C3C));
		printf("Case %d: %.2f %.2f\n", ++cnum, area(C1, C2, C3), ss);
	}
	
	return 0;
}