#include <cstdio>
#include <cmath>

struct point {
	double x, y;
	point(double _x=0, double _y=0):x(_x),y(_y){}
	point operator+(const point k){ return point(x + k.x, y + k.y);	}
	point operator-(const point k){	return point(x - k.x, y - k.y);	}
	point operator*(const double k){ return point(k * x, k * y);}
	double operator^(const point k){ return x * k.y - y * k.x;	}
};

point A, B, C, D, E, F, P, Q, R;
point lsi(point a, point b, point c, point d){
	double dx = b.x - a.x, dy = b.y - a.y;
	double da = d.x - c.x, db = d.y - c.y;
	double s = (da * (c.y - a.y) + db * (a.x - c.x)) /
				(double)(da * dy - db * dx);
	return point(a.x + s * dx, a.y + s * dy);
}

int main(void){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%lf%lf%lf%lf%lf%lf",&A.x,&A.y,&B.x,&B.y,&C.x,&C.y);
		D = B + ((C - B)*(1./3));
		E = C + ((A - C)*(1./3));
		F = A + ((B - A)*(1./3));
		P = lsi(A, D, B, E);
		Q = lsi(B, E, C, F);
		R = lsi(A, D, C, F);
		printf("%.0lf\n",fabs((Q - P)^(R - P)) / 2);
	}
	return 0;
}

