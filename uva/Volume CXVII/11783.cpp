#include <cctype>
#include <cstdio>
#define MAX 1048576
char buf[MAX], *lim = buf + MAX, *now = lim;
void readint(int *n){	
	while(now != lim && !isdigit(*now)) now++;
	if(now == lim){
		int r = fread(buf, 1, MAX, stdin);
		lim = buf + r - 1;
		while(isdigit(*lim)) ungetc(*lim--, stdin);
		now = buf;
	}
	while(!isdigit(*now)) now++;
	*n = 0;	
	while(isdigit(*now)) *n = *n * 10 + *now++ - '0';
}
struct point {
	int x, y;
	int operator*(point p){ return (x * p.y - y * p.x); }
	point operator-(point p){ return point(x - p.x, y - p.y); }
	point(int _x = 0, int _y = 0){ x = _x, y = _y; }
};
struct segment {
	point a, b;
	int i;
}s[1000];
int signal(int x){
	if(x) return 1 + (x < 0);
	return 0;
}
bool intersect(segment s1, segment s2){
	int r1, r2;
	point v1 = s1.b - s1.a;
	point v2 = s2.b - s2.a;
	r1 = v1 * (s2.a - s1.a);
	r2 = v1 * (s2.b - s1.a);
	if(signal(r1) == signal(r2)) return false;
	r1 = v2 * (s1.a - s2.a);
	r2 = v2 * (s1.b - s2.a);
	return (signal(r1) != signal(r2));
}
int main(void){
	int ans, n, x1, x2, y1, y2;
	for(readint(&n); n; readint(&n)){
		ans = 0;
		for(int i = 0; i < n; ++i) {
			readint(&x1), readint(&y1), readint(&x2), readint(&y2);
			s[i].a = point(x1, y1);
			s[i].b = point(x2, y2);
			s[i].i = 0;
			for(int j = 0; j < i; ++j) if(intersect(s[i], s[j])) ++s[i].i, ++s[j].i;
		}
		for(int i = 0; i < n; ++i){
			if(s[i].i) ans += s[i].i;
			else ans += 4;
		}
		printf("%d\n", ans >> 1);
	}	
	return 0;
}
