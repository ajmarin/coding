#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
const int N = 1005;
int f[40];
float e[N];
int main(void){
	int n;
	f[0] = 1; f[1] = 2;
	for(int i = 2; i < 16; ++i) f[i] = f[i - 1] + f[i - 2];
	e[0] = 0;
	for(int i = 1; i < 1001; ++i) e[i] = 1000000;
	for(int i = 0; i < 15; ++i){
		float error = f[i + 1] - f[i] * 1.6;
		for(int j = f[i]; j < 1001; ++j){
			float ne = e[j - f[i]] + error;
			if(fabs(ne) < fabs(e[j])) e[j] = ne;
		}
	}
	while(scanf("%d", &n) && n) printf("%.2f\n", fabs(e[n]));
	return 0;
}
