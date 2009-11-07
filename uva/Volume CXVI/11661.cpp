#include <cstdio>

int main(void){
	register char c;
	int d, i, ld, lr, temp, L;
	while(scanf("%d\n",&L) && L){
		d = 1<<25;
		lr = ld = -1;
		for(i = 0; i < L; i++){
			c = getc( stdin );
			if(c == '.') continue;
			if(c == 'R'){
				if(ld != -1){
					temp = i - ld;
					if(temp < d) d = temp;
				}
				lr = i;
			} else if(c == 'D'){
				if(lr != -1){
					temp = i - lr;
					if(temp < d) d = temp;
				}
				ld = i;
			} else if(c == 'Z'){
				d = 0;
				break;
			}
		}
		while(++i <= L) getc( stdin );

		printf("%d\n",d);

	}
	return 0;
}


