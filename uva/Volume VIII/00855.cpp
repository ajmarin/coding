#include <algorithm>
#include <cstdio>

const int N = 50001;
int x[N], y[N];

int main(void){
	scanf("%*d");
	for(int s, a, f; scanf("%d %d %d", &s, &a, &f) == 3; ){
		int h = (f - 1) >> 1;
		for(int i = 0; i < f; ++i) scanf("%d %d", x + i, y + i);
		std::nth_element(x, x + h, x + f);
		std::nth_element(y, y + h, y + f);
		printf("(Street: %d, Avenue: %d)\n", x[h], y[h]);
	}
	return 0;
}

