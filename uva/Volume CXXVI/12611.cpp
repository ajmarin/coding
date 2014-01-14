#include <cstdio>

int main(void){
	int n; scanf("%d", &n);
	int L, W, xL, xR, yB, yT;
	for(int c = 0, r; c++ < n; ){
		scanf("%d", &r);
		L = 5 * r;
		W = (L * 3) / 5;
		xR = (L * 55) / 100;
		xL = xR - L;
		yT = W >> 1; 
		yB = -yT;
		printf("Case %d:\n%d %d\n%d %d\n%d %d\n%d %d\n", c, xL, yT, xR, yT, xR, yB, xL, yB);
	}
	return 0;
}

