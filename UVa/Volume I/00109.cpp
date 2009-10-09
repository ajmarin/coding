#include <cstdio>
#include <algorithm>
#include <vector> 

using namespace std;

#define NN 128
struct point {
	int x, y;
	inline int sqr(int x){ return (x*x);}
	int d2(point p){ return sqr(x - p.x) + sqr(y - p.y);}
	point(int _x=0, int _y=0):x(_x),y(_y){}
	point operator-(point p){ return point(x-p.x,y-p.y);}
	int operator*(point p){ return (x*p.y)-(y*p.x);}
};
struct kingdom {
	vector < point > p;
	point power;
	int N, A;
	bool off;
}k[32];
int KDM, N;
bool ord(point a, point b){return (a-k[KDM].p[0])*(b-k[KDM].p[0]) > 0;}
int grahamScan(){
	int idx, miny = 1<<25, t = 2, x;
	for(int i = 0; i < N; ++i){
		if(k[KDM].p[i].y < miny || (k[KDM].p[i].y == miny && k[KDM].p[i].x < x))
			miny = k[KDM].p[i].y, x = k[KDM].p[i].x, idx = i;
	}
	if(N < 3) return 0;
	swap(k[KDM].p[0],k[KDM].p[idx]);
	sort(k[KDM].p.begin()+1, k[KDM].p.end(), ord);
	for(int i = 2; i < N; ++i){
		while(t > 1 && ((k[KDM].p[t-1]- k[KDM].p[t-2])*(k[KDM].p[i] - k[KDM].p[t-2])) <= 0) t--;
		swap(k[KDM].p[t],k[KDM].p[i]);
		t++;
	}
	k[KDM].A = 0; k[KDM].N = t;
#ifdef DEBUG
	printf("Points in CONVEX HULL\n");
	for(int i = 0; i < t; ++i)
		printf("(%d,%d),",k[KDM].p[i].x,k[KDM].p[i].y);
	printf("\n");
#endif
	for(int i = 0; i < t; ++i) 
		k[KDM].A += k[KDM].p[i] * k[KDM].p[(i+1)%t];
	if(k[KDM].A < 0) k[KDM].A = -k[KDM].A;
}
bool ccw(point A, point B, point C){
	return ((C - A) * (B - A) < 0);
}
bool line_intersect(point A, point B, point C, point D){
	return (ccw(A,C,D) != ccw(B,C,D) && ccw(A,B,C) != ccw(A,B,D));
}
bool point_in_pol(point X, kingdom K){
	int intersections = 0;
	point ref = point(2000,2000);
	for(int i = 0; i < K.N; i++)
		intersections += line_intersect(K.p[i],K.p[(i+1)%K.N],X,ref);
#ifdef DEBUG
	if(intersections == 0)  printf("FFFFFFFUUUUUUUUu\n");
#endif
	return intersections&1;
}
int main(void){
	int ta = 0,x,y;
	for(KDM = 0; scanf("%d",&N) && N != -1; KDM++){
		k[KDM].off = 0;
		for(int i = 0; i < N; ++i){
			scanf("%d%d",&x,&y);
			k[KDM].p.push_back(point(x,y));
		}
		grahamScan();
#ifdef DEBUG
		printf("Kingdom %d has %d sides, area = %d\n",KDM,k[KDM].N,k[KDM].A);
#endif
	}
	while(scanf("%d%d",&x,&y) == 2){
		point missile = point(x,y);
#ifdef DEBUG
		printf("Missile ATTACK!!! (%d,%d)\n",missile.x,missile.y);
#endif
		for(int i = 0; i < KDM; ++i)
			if(!k[i].off && point_in_pol(missile, k[i])){
#ifdef DEBUG
				printf("Kingdom %d hit by missile\n",i);
#endif
				k[i].off = 1;
				ta += k[i].A;
				break;
			}
	}

	if(ta&1) printf("%d.50\n",ta>>1);
	else printf("%d.00\n",ta>>1);
	return 0;
}

