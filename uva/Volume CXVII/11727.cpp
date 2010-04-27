#include <cstdio>

int main(void){
	int a, ans, b, c, cnum = 0, t;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d", &a, &b, &c);
		if(a > b){
			if(b > c) ans = b;
			else if(a > c) ans = c;
			else ans = a;
		} else if(a > c) ans = a;
		else if(b > c) ans = c;
		else ans = b;
		printf("Case %d: %d\n", ++cnum, ans);
	}
}

