#include <cmath>
#include <cstdio>

//const int NN = 1 << 20;
//double ls[NN];
int ans[21] = {3, 5, 8, 12, 20, 34, 57, 98, 170, 300, 536,
	966, 1754, 3210, 5910, 10944, 20366, 38064, 71421, 134480, 254016};

int main(void){
	/* Code used to generate ans array
	ls[0] = ls[1] = 0;
	for(int i = 2; i < NN; ++i) ls[i] = log(i) + ls[i - 1];
	for(int m, u, v, y; scanf("%d", &y) == 1 && y; ){
		double lim = (1 << (y - 1940) / 10) * log(2);
		for(u = -1, v = NN - 1; u < v; ){
			m = (u + v + 1) >> 1;
			if(ls[m] > lim) v = m - 1;
			else u = m;
		}
		printf("%d\n", v);
	}
	*/
	for(int y; scanf("%d", &y) == 1 && y; printf("%d\n", ans[(y - 1960) / 10]));

	return 0;
}

