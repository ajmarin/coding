#include <cstdio>

int x[128], d[128];

int main(void){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d %d", &x[i], &d[i]);
	}
	bool y = 0;
	for(int i = 0; i < n; ++i){
		for(int j = i + 1; j < n; ++j){
			int s1 = x[i] + d[i];
			int s2 = x[j] + d[j];
			y |= x[i] == s2 && x[j] == s1;
		}
	}
	if(y) puts("YES");
	else puts("NO");
	return 0;
}

