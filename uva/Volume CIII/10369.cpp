#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#define PP 512
#define FORI(a,b,c) for(int a = b; a < c; ++a)
#define FOR(a,b) FORI(a,0,b)

struct point {
	int x, y;
	inline int sqr(int x){ return x*x;}
	int d2(point a){ return sqr(x - a.x) + sqr(y - a.y);}
}pt[PP];
struct edge {
	int x, y, v;
	bool operator<(const edge a) const {
		return v < a.v;
	}
	edge(int _x=0, int _y=0, int _v=0): x(_x),y(_y),v(_v){}
}e[125000];

int P, S, T, CC, e_num, res;
int p[PP];

bool union_find(int x, int y){
	while(p[x] != -1) x = p[x];
	while(p[y] != -1) y = p[y];
	if(x == y) return 0;
	else return p[x] = y, 1;
}
int main(void){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&S, &P);
		e_num = 0;
		FOR(i, P){
			scanf("%d %d",&pt[i].x,&pt[i].y);
			p[i] = -1;
			FOR(j, i) e[e_num++] = edge(i, j, pt[i].d2(pt[j]));
		}
		sort(e, e + e_num);
		CC = P;
		FOR(i, e_num)
			if(union_find(e[i].x, e[i].y) && --CC == S){
				res = e[i].v; break;
			}
		printf("%.2lf\n",sqrt(res));

	}
	return 0;
}

