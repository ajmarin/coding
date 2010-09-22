#include <cstdio>

int a, b;
int v[128];

int main(void){
	int a, b, n;
	bool found = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d", &v[i]);
	for(a = 0; a < 10001; ++a){
		for(b = 0; b < 10001; ++b){
			for(int i = 0; !found; ++i){
				if(i == n - 1) found = 1;
				if(found) break;
				int r = (v[i] * a + b) % 10001;
				int s = (r * a + b) % 10001;
				if(s != v[i + 1]) break;
			}
			if(found) break;
		}
		if(found) break;
	}
	for(int i = 0; i < n; ++i)
		printf("%d\n", (v[i] * a + b) % 10001);
	return 0;
}
