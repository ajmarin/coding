#include <cstdio>
bool mark[100000] = {0};
int main(void){
	int a[20], i, j;
	a[0] = 1; a[1] = 2;
	for(i = 2; i < 20; ++i){
		for(j = a[i - 1] + 1; ; j++){
			bool ok = 1;
			for(int k = 0; ok && k < i; ++k) ok &= !mark[a[k] + j];
			if(ok) break;
		}
		a[i] = j;
		for(int k = 0; k < i; ++k) mark[a[k] + j] = 1;
	}
	int n; scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(j) putc(32, stdout);
			printf("%d", i == j ? 0 : a[i] + a[j]);
		}
		putc(10, stdout);
	}
	return 0;
}

