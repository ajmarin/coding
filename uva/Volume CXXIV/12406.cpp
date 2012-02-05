#include <cstdio>

int end;
long long list[1 << 18];

int main(void){
	list[0] = 0;
	end = 1;
	for(int i = 0; i < (1 << 17) - 1; ++i){
		list[end++] = list[i] * 10 + 1;
		list[end++] = list[i] * 10 + 2;
	}
	scanf("%*d");
	for(int c = 0, p, q; scanf("%d %d", &p, &q) == 2; ){
		long long max_div = 0, min_div = (1LL << 63) - 1;
		for(int a = (1 << p) - 1; a < (1 << (p + 1)) - 1; ++a){
			if(!(list[a] & ((1 << q) - 1))){
				if(list[a] < min_div) min_div = list[a];
				if(list[a] > max_div) max_div = list[a];
			}
		}
		printf("Case %d: ", ++c);
		if(min_div <= max_div){
			if(min_div != max_div) printf("%lld %lld\n", min_div, max_div);
			else printf("%lld\n", min_div);
		} else puts("impossible");
	}
	return 0;
}

