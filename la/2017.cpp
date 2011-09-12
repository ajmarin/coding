#include <cstdio>

const char *t[6] = {"athlete", "reserve", "judge", "staff", "press"};
const char *v[2] = {"invalid", "valid"};
int g[10] = {1, 5, 7, 6, 2, 8, 3, 0, 9, 4};
int f(int i, int j){
	if(i == 0) return j;
	if(i == 1) return g[j];
	return f(i - 1, g[j]);
}
int mymod(int x, int y){
	int r = x % y;
	if(r < 0) r += y;
	return r;
}
int p(int i, int j){
	if(i < 5 && j < 5) return mymod(i + j, 5);
	if(i < 5 && j >= 5) return mymod(i + j - 5, 5) + 5;
	if(i >= 5 && j < 5) return mymod(i - 5 - j, 5) + 5;
	return mymod(i - j, 5);
}
int main(void){
	int T; scanf("%d", &T);
	for(char c[16]; T-- && scanf("%s", c) == 1; ){
		int decimal = 0;
		for(int i = 0; c[i]; ++i)
			decimal = 5*decimal + ('Z' - c[i]);
		int cs, d[8];
		for(int i = 0, z = decimal; i < 8; ++i)
			d[i] = z % 10, z /= 10;
		cs = f(0, d[0]);
		for(int i = 1; i < 8; ++i){
			int r2 = f(i, d[i]);
			cs = p(cs, r2);
		}
		int type = decimal / 10000000;
		if(cs == 0)
			printf("%s/%08d is %s %s id number\n", c, decimal, v[cs == 0], t[type/2]);
		else printf("%s/%08d is invalid id number\n", c, decimal);
	}
	return 0;
}

