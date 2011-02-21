#include <cstdio>
#include <cstring>
int main(void){
	char w[1024];
	for(int l, n, p; scanf("%s %d", w, &n) == 2; ){
		p = (l = strlen(w))*n;
		for(int i = 0; i < l; ++i){
			for(int j = 0; j < p; ++j) putc(w[(i+j)%l], stdout);
			puts("");
		}
	}
	return 0;
}

