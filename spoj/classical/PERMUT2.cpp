#include <cstdio>

int x[1<<17], y[1<<17];
int main(void){
	for(int n; scanf("%d", &n) && n; ){
		bool ambiguous = true;
		for(int i = 0; i < n; ++i){
			scanf("%d", x + i);
			y[x[i]-1] = i + 1;
		}
		for(int i = 0; i < n; ++i) ambiguous &= x[i] == y[i];
		puts(ambiguous ? "ambiguous" : "not ambiguous");
	}
	return 0;
}
