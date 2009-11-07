#include <cstdio>

int main(void){
	int a, az, i, r, z, N;
	register char c;
	while(scanf("%d\n",&N) && N){
		for(a = i = r = z = 0, az = 1; i < N; i++){
			c = getc( stdin );
			if(c == '0') z++;
			else {
				if(i - z) r += (z>>1);
				else a += z;
				az = z = 0;
			}
			getc( stdin );
		}
		if(!az)	r += ((a+z)>>1);
		else r = (z+1)>>1;
		printf("%d\n",r);
	}
	return 0;
}

