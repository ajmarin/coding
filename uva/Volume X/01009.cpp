#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
#define FOR(i,n)	for(int i = 0; i < n; ++i)
const double comp = 4*acos(-1)/3;
double d[8][8], r[8], maxv;
int x[8], y[8], z[8], n, xx, yy, zz;
bool used[8];

double abs(double a){ return a < 0 ? -a : a; }
double cube(double x){ return x * x * x; }
double min(double a, double b){ return a < b ? a : b; }
int sqr(int x){ return x * x; }

void bt(int k){
	if(k == n){
		double v = 0.0;
		for(int i = 0; i < n; ++i) v += cube(r[i]);
		v *= comp;
		if(v > maxv) maxv = v;
		return;
	}
	FOR(i, n) if(!used[i]){
		r[i] = min(x[i], xx - x[i]);
		r[i] = min(r[i], min(y[i], yy - y[i]));
		r[i] = min(r[i], min(z[i], zz - z[i]));
		bool usable = true;
		FOR(j, n){
			usable &= !used[j] || d[i][j] > r[j];
			if(used[j]) r[i] = min(r[i], d[i][j] - r[j]);
		}
		if(!usable) r[i] = 0.0;
		used[i] = true;
		bt(k + 1);
		used[i] = false;
	}
}

int main(void){
	for(int box = 0; scanf("%d", &n) == 1 && n; ){
		int xb, yb, zb, xt, yt, zt;
		FOR(i, 8) used[i] = false;
		scanf("%d %d %d", &xb, &yb, &zb);
		scanf("%d %d %d", &xt, &yt, &zt);
		if(xb > xt) swap(xb, xt);
		if(yb > yt) swap(yb, yt);
		if(zb > zt) swap(zb, zt);
		xx = xt - xb;
		yy = yt - yb;
		zz = zt - zb;
		FOR(i, n){
			scanf("%d %d %d", &x[i], &y[i], &z[i]);
			if(x[i] < xb || x[i] > xt || y[i] < yb || y[i] > yt || z[i] < zb || z[i] > zt){
				--n, --i;
				continue;
			}
			x[i] -= xb;
			y[i] -= yb;
			z[i] -= zb;
			FOR(j, i)
				d[i][j] = d[j][i] = sqrt(sqr(x[i] - x[j]) + sqr(y[i] - y[j]) + sqr(z[i] - z[j]));
			d[i][i] = 0.0;
		}
		maxv = -1;
		bt(0);
		printf("Box %d: %.0lf\n\n", ++box, xx*yy*zz - maxv);
	}
	return 0;
}

