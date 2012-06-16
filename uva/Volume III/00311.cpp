#include <algorithm>
#include <cstdio>
using namespace std;

#define FOR(i,n) for(int i = 1; i <= n; ++i)
int main(void){
	for(int s = 0, v[8]; ; s = 0){
		FOR(i, 6) scanf("%d", v + i), s += v[i];
		if(!s) break;
		int a3l = 0, a4l = 0, h = v[6] + v[5] + v[4] + (v[3] + 3) / 4;
		v[3] %= 4;
		v[1] = max(0, v[1] - 11 * v[5]);
		a4l = 20 * v[4] - min(5 * v[4], v[2]) * 4;
		v[2] = max(0, v[2] - 5 * v[4]);
		if(v[2] && v[3]){
			switch(v[3]){
				case 1:
					a3l = 27 - min(v[2], 5) * 4;
					v[2] = max(0, v[2] - 5);
					break;
				case 2:
					a3l = 18 - min(v[2], 3) * 4;
					v[2] = max(0, v[2] - 3);
					break;
				case 3:
					a3l = 5;
					--v[2];
					break;
			}
		}
		v[1] = max(0, v[1] - a3l - a4l);
		h += (4*v[2]+v[1]+35) / 36;
		printf("%d\n", h);
	}
	return 0;
}

