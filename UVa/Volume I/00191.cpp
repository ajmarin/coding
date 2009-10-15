#include <cstdio>

#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))

struct point {
	int x, y;
	point(int _x=0, int _y=0):x(_x),y(_y){}
	point operator-(const point k){
		return point(x - k.x, y - k.y);
	}
	int operator*(const point k){
		return x * k.y - y * k.x;
	}
} p[6];

int dx, dy, maxx, maxy, minx, miny;
bool inside(point k){
	if(k.x > maxx || k.x < minx || k.y > maxy || k.y < miny) return 0;
	return 1;
}
bool lsi(point c, point d){
	int da = d.x - c.x;
	int db = d.y - c.y;
	double s = (dx * (c.y - p[0].y) + dy * (p[0].x - c.x)) /
				(double)(da * dy - db * dx);
	double t = (da * (p[0].y - c.y) + db * (c.x - p[0].x)) /
				(double)(db * dx - da * dy);
	return (s >= 0 && s <= 1 && t >= 0 && t <= 1);
}
int main(void){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d%d%d%d%d",&p[0].x,&p[0].y,&p[1].x,
				&p[1].y,&p[2].x,&p[2].y,&p[3].x,&p[3].y);
		minx = MIN(p[2].x, p[3].x);
		maxx = MAX(p[2].x, p[3].x);
		miny = MIN(p[2].y, p[3].y);
		maxy = MAX(p[2].y, p[3].y);
		p[4].x = p[3].x;
		p[4].y = p[2].y;
		p[5].x = p[2].x;
		p[5].y = p[3].y;
		dx = p[1].x - p[0].x;
		dy = p[1].y - p[0].y;
		if(inside(p[0]) || inside(p[1]) || 
		 lsi(p[2],p[4]) || lsi(p[2],p[5]) || 
				lsi(p[3],p[4]) || lsi(p[3],p[5]))
			puts("T");
		else puts("F");
	}
	return 0;
}

