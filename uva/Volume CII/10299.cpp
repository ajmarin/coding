#include <cstdio>

void phi_red(int &n, int &r, int d){
	if(n % d) return;
	do { n /= d; } while(!(n % d));
	r = (r / d) * (d - 1);
}

int phi(int n){
	int r = n - (n == 1);
	phi_red(n, r, 2);
	phi_red(n, r, 3);
	for(int i = 5; ; i += 6){
		int i2 = i + 2;
		phi_red(n, r, i);
		phi_red(n, r, i2);
		if(i * i > n) break;
	}
	if(n != 1) phi_red(n, r, n);
	return r;
}

int main(void){
	for(int n; scanf("%d", &n) == 1 && n; printf("%d\n", phi(n)));
	return 0;
}

