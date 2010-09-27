#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>
using namespace std;
/* Point 2d {{{ */
typedef int pdata;
struct p2d {
	pdata x, y;
	p2d operator+(p2d p){ return p2d(x + p.x, y + p.y); }
	p2d operator-(p2d p){ return p2d(x - p.x, y - p.y); }
	p2d operator*(pdata k){ return p2d(k * x, k * y); }
	p2d operator/(pdata k){ return p2d(x / k, y / k); }
	pdata  operator*(p2d p){ return (x * p.y - y * p.x);}
	pdata operator^(p2d p){ return (x * p.x + y * p.y);}
	bool operator==(p2d p){ return (x == p.x && y == p.y);}
	bool operator<(p2d p) const { return (x < p.x || (x == p.x && y < p.y));}
	bool operator>(p2d p) const { return (x > p.x || (x == p.x && y > p.y));}
	bool point_on_line(p2d p0, p2d p1){ return ((p1 - p0) * (*this - p0)) == 0;}
	double mod(){ return sqrt(x * x + y * y); }
	double point_line_distance(p2d p0, p2d p1){
		/* d = | v dot r |/ | v | */
		p2d v = p1 - p0, r = *this - p0;
		pdata temp = v.x;
		v.x = -v.y;
		v.y = temp;
		return (v ^ r)/v.mod();
	}

	p2d(pdata _x = 0, pdata _y = 0): x(_x), y(_y) {};
};
/* }}} */

p2d p[512];
bool adj[512][512];
int line[32];

int main(void){
	int a, b, pc, ls;
	bool found, third;
	while(scanf("%d %d", &a, &b) && (a || b)){
		p[0] = p2d(a, b);
		pc = 1; found = 0;
		while(scanf("%d %d", &a, &b) && (a || b)) p[pc++] = p2d(a, b);
		for(int i = 0; i < pc; ++i)
			for(int j = i + 1; j < pc; ++j)
				adj[i][j] = 0;
		sort(p, p + pc);
		for(int i = 0; i < pc; ++i)
			for(int j = i + 1; j < pc; ++j){
				if(adj[i][j]) continue;
				p2d v = p[j] - p[i];
				if(v.x && v.y) v = v/__gcd(v.x, v.y);
				line[0] = i;
				line[1] = j;
				third = 0;
				ls = 2;
				for(int k = j + 1; k < pc; ++k){
					if(p[k].point_on_line(p[i], p[j])){
						if(!third){
							adj[i][j] = 1;
							if(!found) puts("The following lines were found:"), found = 1;
							printf("(%4d,%4d)(%4d,%4d)", p[i].x, p[i].y, p[j].x, p[j].y);
							third = 1;
						}
						for(int l = 0; l < ls; ++l) adj[line[l]][k] = 1;
						line[ls++] = k;
						printf("(%4d,%4d)", p[k].x, p[k].y);
					}
				}
				if(third) putc(10, stdout);
			}
		if(!found) puts("No lines were found");
	}
	return 0;
}

