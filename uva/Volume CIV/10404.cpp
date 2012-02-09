#include <cstdio>

int result[1048576], v[16];

int main(void){
	for(int i = 0; i < 1048576; ++i) result[i] = 0;
	for(int m, n; scanf("%d", &n) == 1; ){
		scanf("%d", &m);
		for(int i = 0; i < m; ++i) scanf("%d", v + i);
		for(int i = 0; i <= n; ++i)
			if(result[i] == 0) for(int j = 0; j < m; ++j)
				if(i + v[j] <= n) result[i + v[j]] = 1;
		puts(result[n] ? "Stan wins" : "Ollie wins");
		for(int i = n; i >= 1; --i) result[i] = 0;
	}
	return 0;
}
