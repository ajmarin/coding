#include <algorithm>
#include <cmath>
#include <cstdio>

const double EPS = 1e-6;
const int NN = 10048;
double L[NN], R[NN];
int iord[NN];

bool cmp(int a, int b){	return L[a] < L[b]; }

int main(void){
	for(int h, n, w; scanf("%d %d %d", &n, &w, &h) == 3; ){
		double d, hsquf = (h * h) / 4.0, new_right, right = 0;
		int cnt, i, j, pos, r;
		for(i = 0; i < n; ++i){
			scanf("%d %d", &pos, &r);
			d = sqrt(double(r) * r - hsquf);
			L[i] = pos - d;
			R[i] = pos + d;
			iord[i] = i;
		}
		std::sort(iord, iord + n, cmp);
		for(cnt = i = j = 0; i < n; i = j){
			new_right = 0;
			while(j < n && L[iord[j]] <= right){
				if(R[iord[j]] > new_right) new_right = R[iord[j]];
				++j;
			}
			right = new_right;
			++cnt;
			if(right + EPS > w || j == i) break;
		}
		printf("%d\n", right + EPS > w ? cnt : -1);
	}	
	return 0;
}

