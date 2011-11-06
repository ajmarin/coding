#include <cmath>
#include <cstdio>

int dx[6] = {-1, -1, 0, 1, 1, 0};
int dy[6] = {1, 0, -1, -1, 0, 1};

int min(int a, int b){ return a < b ? a : b; }

int main(void){
	for(int n, s, x, y, z; scanf("%d", &z) == 1; ){
		n = ceil( (-3 + sqrt(12 * z - 3)) / 6 );
		x = n - (n > 0);
		y = n > 0;
		z -= 3 * (n - 1) * n + 1 + (n > 0);
		for(int i = 0; z && i < 6; ++i){
			s= min(n - (i == 0), z);
			z -= s;
			x += dx[i] * s;
			y += dy[i] * s;
		}
		printf("%d %d\n", x, y);
	}

	return 0;
}

