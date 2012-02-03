#include <cstdio>

int c[16] = { 4, 6, 3, 5, 2, 4, 2, 4, 2, 3, 2, 3, 1 };
int v[16] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
int main(void){
	for(int cnt(0), n; scanf("%d", &n) == 1; cnt = 0){
		for(int i = 0; n; ++i)
			while(n >= v[i]){
				cnt += c[i];
				n -= v[i];
			}
		printf("%d\n", cnt);
	}
	return 0;
}

