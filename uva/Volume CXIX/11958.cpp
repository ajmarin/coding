#include <cstdio>

int main(void){
	int cnum = 0, t; scanf("%d", &t);
	for(int k, h, m, d; t-- && scanf("%d %d:%d", &k, &h, &m) == 3; ){
		int min_time = 1<<30, now = 60*h + m, tmp;
		for(int i = 0; i < k; ++i){
			scanf("%d:%d %d", &h, &m, &d);
			if((tmp = 60 * h + m) < now) tmp += 1440;
			tmp += d;
			if(tmp < min_time) min_time = tmp;
		}
		printf("Case %d: %d\n", ++cnum, min_time - now);
	}
	return 0;
}
			
