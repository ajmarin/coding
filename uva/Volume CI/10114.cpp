#include <cstdio>

int month[128];
double pct[128];
int main(void){
	double dp, amt;
	for(int m, z; scanf("%d %lf %lf %d", &m, &dp, &amt, &z) == 4 && m > 0; ){
		double car_value = amt + dp;
		double owing = amt;
		double monthly_payment = amt / m;
		int c_month = 0, midx = 0;
		for(int i = 0; i < z; ++i) scanf("%d %lf", month + i, pct + i);
		month[z] = 1 << 20;
		while(1){
			car_value *= (1 - pct[midx]);
			if(owing < car_value) break;
			owing -= monthly_payment;
			if(month[midx + 1] <= ++c_month) ++midx;
		}
		printf("%d month", c_month);
		puts(c_month != 1 ? "s" : "");
	}
	return 0;
}

