#include <cmath>
#include <cstdio>

int n;
bool used[16];
int m[16];
double h[16], r[16], rh[16], R[16];
double minH;

double max(double a, double b){ return a > b ? a : b; }

double fit(double r1, double R1, double H1, double r2, double R2, double H2){
	double hB = 0, hT = 0, hM = 0;
	// bottom-height
	if(r1 > R2) hB = H2;
	else if(r1 < r2) hB = 0;
	else hB = (H2 / (R2 - r2)) * (r1 - r2);
	// top-height
	if(R1 < r2) hT = 0;
	else if(R1 > R2) hT = H2;
	else hT = (H2 / (R2 - r2)) * (R1 - r2);
	hB = max(hB, hT - H1);
	// mid-height
	if(r1 < R2 && R1 > R2){
		hM = (H1 / (R1 - r1)) * (R2 - r1);
		hB = max(hB, H2 - hM);
	}
	return hB;
}

void bt(int d){
	if(d == n){
		double maxH = 0;
		for(int i = 0; i < d; ++i) maxH = max(maxH, rh[m[i]] + h[m[i]]);
		if(maxH < minH) minH = maxH;
		return;
	}
	for(int i = 0; i < n; ++i){
		if(used[i]) continue;
		used[i] = true;
		double addH = rh[i] = 0;
		for(int j = 0; j < d; ++j){
			int p = m[j];
			addH = fit(r[i], R[i], h[i], r[p], R[p], h[p]);
			rh[i] = max(rh[i], rh[p] + addH);
		}
		m[d] = i;
		bt(d + 1);
		used[i] = false;
	}
}

int main(void){
	int T; scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i = 0; i < n; ++i){
			scanf("%lf %lf %lf", &h[i], &r[i], &R[i]);
			used[i] = false;
		}
		minH = 1e10;
		bt(0);
		printf("%d\n", int(floor(minH)));
	}
	return 0;
}

