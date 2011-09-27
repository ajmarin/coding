#include <cstdio>

int v[1024];
int main(void){
	for(int n; scanf("%d", &n) == 1 && n; ){
		bool showed = false;
		for(int i = 0; i < n; ++i){
			scanf("%d", v + i);
			if(v[i] > 0){
				if(showed) putc(32, stdout);
				printf("%d", v[i]);
				showed = true;
			}
		}
		if(!showed) putc('0', stdout);
		puts("");
	}
	return 0;
}

