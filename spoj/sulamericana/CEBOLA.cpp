#include <cstdio>
#include <algorithm>

using namespace std;

struct point {
	int x, y; bool used;
	inline int sqr(int x){ return (x*x);}
	int d2(point p){ return sqr(x - p.x) + sqr(y - p.y);}
	point(int _x=0, int _y=0):x(_x),y(_y){}
	point operator-(point p){ return point(x-p.x,y-p.y);}
	int operator*(point p){ return (x*p.y)-(y*p.x);}
}p[2048];
const char *TAKE = "Take this onion to the lab!";
const char *DONT = "Do not take this onion to the lab!";
int N;

bool ord(point a, point b){
	return (a-p[0])*(b-p[0]) > 0;
}
bool grahamScan(){
	int idx, miny = 1<<25, rot, t = 0, x;
	point *q[2048];
	for(int i = 0; i < N; ++i){
		while(i < N && p[i].used) swap(p[i],p[--N]);
		if(i == N) break;
		if(p[i].y < miny || (p[i].y == miny && p[i].x < x))
			miny = p[i].y, x = p[i].x, idx = i;
	}
	if(N < 3) return 0;
	swap(p[0],p[idx]);
	sort(p+1, p+N, ord);
	q[t++] = &p[0];
	q[t++] = &p[1];
	for(int i = 2; i < N; ++i){
		while(t > 1 && ((*q[t-1]- *q[t-2])*(p[i] - *q[t-2])) <= 0) t--;
		q[t++] = &p[i];
	}
	for(int i = 0; i < t; ++i) q[i]->used = 1;
	return N > 0 && t > 2;
}

int main(void){
	while(scanf("%d",&N) && N){
		for(int i = 0; i < N; ++i){
			scanf("%d %d",&p[i].x,&p[i].y);
			p[i].used = 0;
		}
		int layers = 0;
		while(grahamScan()) layers++;
		layers&1? puts(TAKE) : puts(DONT);
	}
	return 0;
}

