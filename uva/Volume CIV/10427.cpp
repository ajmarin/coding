#include <cstdio>

int t9p10[10], p10[10];

int len(int x){
	int r = 0, tam;
	for(tam = 1; p10[tam] <= x; ++tam){
		r += t9p10[tam] * tam;
	}
	return r += (x - p10[tam - 1] + 1) * tam;
}

int main(void){
	t9p10[1] = 9;
	p10[0] = 1;
	p10[1] = 10;
	for(int i = 2; i < 10; ++i){
		t9p10[i] = 10 * t9p10[i - 1];
		p10[i] = 10 * p10[i - 1];
	}
	for(int n; scanf("%d", &n) == 1; ){
		int low = 1, high = n + 1, mid;
		while(low < high){
			mid = (low + high) >> 1;
			if(len(mid) < n) low = mid + 1;
			else high = mid;
		}
		int at = len(low);
		while(at-- > n) low /= 10;
		printf("%d\n", low % 10);
	}

	return 0;
}

