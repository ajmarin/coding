#include <cstdio>

int main(void){
	for(char c = getc( stdin ); c != EOF; c = getc( stdin )){
		int steps, z;
		for(int cnt = z = 0; c != 10; c = getc( stdin )){
			if(c == ' ') ++cnt;
			else {
				z = cnt > z ? cnt : z;
				cnt = 0;
			}
		}
		for(steps = z > 1; (z = (z + 1) >> 1) > 1; ++steps);
		printf("%d\n", steps);
	}
	return 0;
}

