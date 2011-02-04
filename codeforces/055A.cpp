#include <cstdio>

bool v[1024];
int main(void){
	int n; scanf("%d", &n);
	for(int i = 0; i < n; ++i) v[i] = 0;
	int vc = 0;
	for(int at = 0, c = 0; c < n; ++c){		
		vc += !v[at];
		v[at] = 1;
		at = (at + c + 1) % n;
	}
	puts(vc == n ? "YES" : "NO");
	return 0;
}	
	