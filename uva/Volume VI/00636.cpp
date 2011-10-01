#include <cmath>
#include <cstdio>

int sqr(int x){ return x * x; }
bool IsSquare(int x){ return sqr(int(sqrt(x))) == x; }
int ToBase10(char *n, int base){
	int r = 0;
	for(r = 0; *n; r = (r * base) + (*n++ - '0'));
	return r;
}
int main(void){
	for(char n[32]; scanf("%s", n) == 1 && *n != '0'; ){
		int mb = 1;
		for(int i = 0; n[i]; ++i) if(n[i] - '0' > mb) mb = n[i] - '0';
		++mb;
		for(int base = mb; base < 100; ++base)
			if(IsSquare(ToBase10(n, base))){
				printf("%d\n", base);
				break;
			}
	}
	return 0;
}

