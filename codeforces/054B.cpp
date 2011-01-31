#include <cstdio>

int reduce(int n){
	if(!(n & 1)) return n >> 1;
	if(!(n % 3)) return n / 3;
	for(int i = 6; ; i += 6){
		int t1 = i + 1, t2 = i - 1;
		if(!(n % t2)) return n / t2;
		if(!(n % t1)) return n / t1;
		if(t1 * t1 > n) return 1;
	}
}
int main(void){
	int n; scanf("%d", &n);
	while(n != 1){
		printf("%d ", n);
		n = reduce(n);
	}
	printf("1\n");
}

