#include <cstdio>
#include <cmath>

int v[4];

int main(void){
	for(int a = 1; a < 126; ++a){
		int blim = (2002 - a) / 3;
		for(int b = a; b <= blim; ++b){
			int clim = (2001 - (a + b)) / 2;
			for(int c = b; c <= clim; ++c){
				int sum = a + b + c;
				long long div = (long long)(a) * b * c;
				if(div <= 1000000) continue;
				double d = sum * 1e6 / (div - 1e6);
				if(d < c) continue;
				if(d - floor(d) < 1e-6){
					sum = a + b + c + d;
					if(sum <= 2000)
						printf("%.2lf %.2lf %.2lf %.2lf\n", a/100.0, b/100.0, c/100.0, d/100.0);
				}
			}
		}
	}

	return 0;
}

