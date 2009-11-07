#include <cstdio>
#include <cstring>

#define NN 1500

int f[NN];
char k[1000024];

/* Bignum {{{ */
void rev(char v[]) {
	int l = strlen(v);
	int i; char cc;
	for(i = 0; i < l-1-i; i++) {
		cc = v[i];
		v[i] = v[l-1-i];
		v[l-i-1] = cc;
	}
}

int div(char v[], int q) {
	int i, l = strlen(v);
	int c = 0, d;
	for(i = l - 1; i >= 0; i--) {
		d = c*10 + (v[i] - '0');
		c = d%q; d /= q; v[i] = '0'+d;
	}
	i = l - 1;
	while(i > 0 && v[i] == '0') i--;
	v[i+1] = '\0';
	return c;
}
/* }}} */

int main(void) {
	int i;

	f[0] = 0, f[1] = 1;
	for(i = 2; i < NN; i++) f[i] = (f[i-1] + f[i-2]) % 1000;

	scanf("%d", &i);
	while(i--) {
		scanf("%s", k);
		rev(k);
		printf("%03d\n", f[div(k, NN)]);
	}

	return 0;
}
