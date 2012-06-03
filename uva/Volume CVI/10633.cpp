#include <cstdio>

int main(void){
	for(long long z; scanf("%lld", &z) == 1 && z; ){
		long long n = z + z/9;
		bool first = true;
		for(long long i = n - 10; i <= n + 10; ++i){
			if(i - i/10 == z){
				if(!first) putc(32, stdout);
				printf("%lld", i);
				first = false;
			}
		}
		puts("");
	}
	return 0;
}

