#include <cstdio>

#define MAX 1048576
int x[MAX];

int main(void){
	x[1] = 1; x[2] = 2;
	int cnt = 1, k = 2, pos, sum;
	for(pos = sum = 3; sum < 2001000000; ++pos){
		if(cnt == x[k]) ++k, cnt = 0;
		x[pos] = k;
#ifdef DBG
		printf("v[%d] = %d (%d)\n", pos, x[pos], sum);
#endif
		sum += k;
		cnt++;
	}
	for(int i = 1; i < pos; ++i) x[i] += x[i - 1];
	for(int n; scanf("%d", &n) == 1 && n; ){
		int mid, u, v;
		for(u = 1, v = pos; u < v; ){
			mid = (u + v) >> 1;
			if(x[mid] < n) u = mid + 1; else v = mid;
		}
		printf("%d\n", u);
	}
	return 0;
}

