#include <cstdio>
typedef long long LL;
const int N = 100048;
int l[N], s[N], top = 0;
LL h[N], maxa;
LL max(LL a, LL b){ return a > b ? a : b; }
int main(void){
	for(int n; scanf("%d", &n) == 1 && n; ){
		maxa = 0; top = -1;
		for(int i = 0; i < n; ++i){
			scanf("%lld", h + i);
			bool popped = top >= 0 && h[i] < h[s[top]];
			while(top >= 0 && h[i] < h[s[top]])
				maxa = max(maxa, h[s[top]] * (i - l[top--]));
			if(top == -1 || h[i] > h[s[top]]){
				s[++top] = i;
				if(!popped) l[top] = i;
			}
		}
		while(top >= 0) maxa = max(maxa, h[s[top]] * (n - l[top--]));
		printf("%lld\n", maxa);
	}
	return 0;
}

