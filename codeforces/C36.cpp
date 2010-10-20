#include <algorithm>
#include <cstdio>
using namespace std;
#define FOR(a,b)	for(int a = 0; a < b; ++a)
double maxh = 0;
struct bowl {
	int H, r, R;
	double base;
	void pile(bowl &b){
		if(r >= b.R) base = max(base, b.base + b.H);
		else {
			double b1 = -1, b2 = -1, b3 = -1, dh;
			if(R >= b.R){
				dh = (H * (b.R - r))/(double)(R - r);
				b1 = b.base + b.H - dh;
				if(b1 < b.base) b1 = -1;
			}
			if(r >= b.r){
				dh = (b.H * (r - b.r))/(double)(b.R - b.r);
				b2 = b.base + dh;
			}
			if(R <= b.R && R >= b.r){
				dh = (b.H * (R - b.r))/(double)(b.R - b.r);
				b3 = b.base + dh - H;
				if(b3 < b.base) b3 = -1;
			}
			base = max(base, max(max(b1, b2), max(b3, b.base)));
		}
	}
} bowls[3072];

int main(void){
#ifdef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	FOR(i, n){
		scanf("%d %d %d", &bowls[i].H, &bowls[i].r, &bowls[i].R);
		bowls[i].base = 0;
		FOR(j, i) bowls[i].pile(bowls[j]);
		maxh = max(maxh, bowls[i].base + bowls[i].H);
	}
	printf("%.9lf\n", maxh);
	return 0;
}
