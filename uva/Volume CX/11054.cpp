#include <cstdio>

int main(void){
	for(int n; scanf("%d", &n) && n; ){
		long long balance = 0, mov = 0, x;
		while(n--){
			scanf("%lld", &x);
			x = x + balance;
			mov += (x < 0 ? -x:x);
			balance = x;
		}
		printf("%lld\n", mov);
	}
	return 0;
}

