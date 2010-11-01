#include <cstdio>
#include <cstring>
#include <algorithm>
#define ABS(a) (((a)<0)?(-a):(a))
using namespace std;
struct POINT {
	int r, x, y;
	POINT(int a1, int a2): x(a1),y(a2) {}
	POINT(){}
} INF[1000], RAD[30], BOR[1000];
struct BACKEDGE {
	int a, b, dd;
	BACKEDGE(int a1, int a2, int a3): a(a1),b(a2),dd(a3) {}
	BACKEDGE(){}
	const bool operator<(const BACKEDGE x) const {
		return dd > x.dd;
	}
} be[435];
struct POLYGON {
	POINT p[30];
	int n;
} pol;
int be_num, dep, mask, M;
int d[30], p[30];
const char *mi = "Mission impossible";

int sqdist(POINT a, POINT b){
	int d = a.x-b.x, ret = 0;
	ret += d*d;
	d = a.y-b.y;
	ret += d*d;
	return (ret);
}
bool over(POINT A, POINT B){
	int dist = sqdist(A,B);
	int x = (B.r - A.r)*(B.r - A.r);
	return (dist < ABS(x));
}
void dfs(int k, int b4){
	mask |= (1<<k);
	p[k] = b4;
	d[k] = dep++;
	for(int j = 0; j < M; j++){
		if(j == b4 || j == k) continue;
		int sqradsum = RAD[j].r + RAD[k].r;
		if(sqdist(RAD[k],RAD[j]) < sqradsum*sqradsum){			
			if(!((1<<j) & mask)) dfs(j, k);
			else if(d[j] < d[k]) be[be_num++] = BACKEDGE(j,k,d[k]-d[j]);
		}
	}
	dep--;
}
bool ccw(POINT A, POINT B, POINT C){
	return ((C.y-A.y)*(B.x-A.x) > (B.y-A.y)*(C.x-A.x));
}
bool line_intersect(POINT A, POINT B, POINT C, POINT D){
	return (ccw(A,C,D) != ccw(B,C,D) && ccw(A,B,C) != ccw(A,B,D));
}
bool point_in_pol(POINT X, POLYGON P){
	int intersections = 0;
	POINT ref = POINT(2000,2000);
	for(int i = 0; i < P.n; i++)
		intersections += line_intersect(P.p[i],P.p[(i+1)%P.n],X,ref);
	return intersections&1;
}
/* point line segment distance */
double plsd(POINT A, POINT B, POINT C){
	POINT V = POINT(B.x-A.x,B.y-A.y);
	double distAB = (double)sqdist(A,B);
	double u = ((C.x-A.x)*(B.x-A.x)+(C.y-A.y)*(B.y-A.y))/distAB;
	double xx = (A.x + u*V.x), yy = (A.y + u*V.y);
	double dist, dist2;
	u = (xx-A.x); dist = u*u;
	u = (yy-A.y); dist += u*u;
	u = (xx-B.x); dist2 = u*u;
	u = (yy-B.y); dist2 += u*u;
	if(dist > distAB) return sqdist(B,C);
	if(dist2 > distAB) return sqdist(A,C);
	return (C.x-xx)*(C.x-xx)+(C.y-yy)*(C.y-yy);
}
int main(void){
	int i, j, B, N;
	while(scanf("%d",&B) && B){
		for(i = 0; i < B; i++) scanf("%d%d",&BOR[i].x,&BOR[i].y);
		scanf("%d",&N);
		for(i = 0; i < N; i++) scanf("%d%d",&INF[i].x,&INF[i].y), INF[i].r = i+1;
		scanf("%d",&M);
		for(i = 0; i < M; i++) scanf("%d%d%d",&RAD[i].x,&RAD[i].y,&RAD[i].r);
		mask = 0;
		memset(p,-1,M<<2);
		/* ELIMINA RADARES "DENTRO" DOS OUTROS */
		for(i = 0; i < M; i++)
			for(j = i+1; j < M; j++)
				if(over(RAD[i],RAD[j])){
					if(RAD[i].r < RAD[j].r){ swap(RAD[i--],RAD[--M]); break; }
					else swap(RAD[j--],RAD[--M]);
				}
		/* ELIMINA INFORMANTES NO ALCANCE DOS RADARES */
		for(i = 0; i < N; i++)
			for(j = 0; j < M; j++)
				if(sqdist(INF[i],RAD[j]) <= RAD[j].r*RAD[j].r){
					swap(INF[i--],INF[--N]);
					break;
				}
		if(N){
			/* DFS PARA ACHAR CICLOS */
			be_num = 0; /* numero de BACKEDGE'S */
			for(i = 0; i < M; i++)
				if(!((1<<i) & mask)) dep = 0, dfs(i, -1);
			sort(be,be+be_num);
			/* Constroi os polígonos */
			for(i = 0; i < be_num; i++){
				mask = pol.n = 0;
				for(j = (*be).b; ; j = p[j]){
					mask |= (1<<j);
					pol.p[pol.n++] = POINT(RAD[j].x,RAD[j].y);
					if(j == (*be).a) break;
				}
				for(j = 0; j < N; j++)
					if(point_in_pol(INF[j],pol))
						swap(INF[j--],INF[--N]);
				for(j = i+1; j < be_num; j++){
					int vis = ((1<<be[j].a)|(1<<be[j].b));
					if((vis & mask) == vis)	swap(be[j--],be[--be_num]);
				}
			}
		}
		if(N){
			/* ACHA O INFORMANTE COM MAIOR INSIDER COEFFICIENT */
			int idx = 0;
			double min, gmin = 0, temp;
			for(i = 0; i < N; i++){
				min = 1E20;
				for(j = 0; j < B; j++){					
					temp = plsd(BOR[j],BOR[(j+1)%B],INF[i]);
					if(temp < min) min = temp;
				}
				if(min > gmin) gmin = min, idx = INF[i].r;
			}
			printf("Contact informer %d\n",idx);
		} else puts(mi);
	}
	return 0;
}
