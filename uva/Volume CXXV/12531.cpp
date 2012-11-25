#include <cstdio>

bool has_diff[512];
int main(void){
	for(int i = 0; i < 512; ++i) has_diff[i] = false;
	int angm, angh, diff;
	for(int i = 0; i < 720; ++i){
		angm = (6 * i) % 360;
		angh = (6 * (i / 12)) % 360;
		diff = (angm - angh + 360) % 360;
		if(diff > 180) diff = 360 - diff;
		has_diff[diff] = true;
	}
	for(int n; scanf("%d", &n) == 1; puts(has_diff[n] ? "Y" : "N"));
	return 0;
}

