#include <cstdio>
char l[128];
int main(void){
	int ans = 0, c = 0;
	while(fgets(l, 128, stdin)){
		if(*l == '+' || *l == '-') c += ((*l == '+') << 1) - 1;
		else {
			char *p = l, *q;
			while(*p && *p++ != ':'); q = p; while(*p++ > 30);
			ans += (p - q - 1) * c;
		}
	}
	printf("%d\n", ans);
	return 0;
}

