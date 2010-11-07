#include <cstdio>
#include <cmath>
#define EPS 1e-12
int signal[32]; double sum[32];
int main(void){
	for(int m, n; scanf("%d %d", &m, &n) == 2; ){
		double max = -(1e15), z;
		int col = -1, sm = -1;
		for(int i = 0; i < m; ++i) sum[i] = 0., signal[i] = 1;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j){
				scanf("%lf", &z);
				if(z == 0) signal[j] = 0;
				if(z < 0) signal[j] = -signal[j], z = -z;
				if(z) sum[j] += log(z);
			}
		for(int i = 0; i < m; ++i){
			double t = 0;
			if(max < EPS && (!signal[i] || !sum[i])){
				if(signal[i] >= sm){
					sm = signal[i];
					max = 0;
					col = i;
				}
			} else {
				t = sum[i] * signal[i];
				if(t - max > -EPS) max = t, col = i;
			}
		}
		printf("%d\n", col + 1);
	}
	return 0;
}

