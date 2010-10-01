#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
double minl, r[8], x[8];
int idx[8];
int n;
bool used[8] = {0, 0, 0, 0, 0, 0, 0, 0};

void bt(int k, double maxxr){
	if(k == n){
		if(maxxr < minl) minl = maxxr;
		return;
	}
	double maxx, nx;
	for(int i = 0; i < n; ++i)
		if(!used[i]){
			used[i] = 1;
			maxx = 0;
			for(int j = 0; j < k; ++j){
				nx = x[idx[j]] + 2*sqrt(r[idx[j]] * r[i]);
				if(nx > maxx) maxx = nx;
			}
			if(r[i] > maxx) maxx = r[i];
			idx[k] = i;
			x[i] = maxx;
			if(x[i] + r[i] > maxxr) bt(k + 1, x[i] + r[i]);
			else bt(k + 1, maxxr);
			used[i] = 0;
		}
}
int main(void){
	int t;
	for(scanf("%d", &t); t-- && scanf("%d", &n) == 1; ){
		for(int i = 0; i < n; ++i) scanf("%lf", &r[i]);
		minl = 1e15;
		bt(0, 0);
		printf("%.3lf\n", minl);
	}
	return 0;
}

