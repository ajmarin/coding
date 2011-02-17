#include <cstdio>
int x[10005];
int main(void){
	for(int mean, n, s = 0, t; scanf("%d", &n) && n != -1; ){
		s = 0;
		for(int i = 0; i < n; ++i) scanf("%d", x + i), s += x[i];
		mean = s / n;
		if(!(s % n)){
			mean = s / n; s = 0;
			for(int i = 0; i < n; ++i) s += x[i] > mean ? x[i] - mean : 0;
			printf("%d\n", s);
		} else puts("-1");
	}
	return 0;
}
