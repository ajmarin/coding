#include <stdio.h>
#define FOR(i,n)	for(i = 0; i < n; ++i)
#define DIGITS 10000
#define BASE 1000
#define BP10 3

int num1[DIGITS], num2[DIGITS];
int res[DIGITS];
int i, j;
int get_last(int* a){
	int i;
	for(i = DIGITS; i-- && !a[i]; );
	return i + 1 + (i == -1);
}
void carry(int* a){
	int c = 0;
	FOR(i, DIGITS){
		c = (a[i] += c) / BASE;
		a[i] %= BASE;
	}
}
void add(int* a, int *b){
	FOR(i, DIGITS) a[i] += b[i];
	carry(a);
}
void mul(int *a, int *b){
	int lim_i = get_last(a), lim_j = get_last(b);
	FOR(i, lim_i) FOR(j, lim_j) res[i+j] += a[i] * b[j];
	carry(res);
}
void read(char *n, int *d){
	char *last = n;
	int j = 0, base = 1, x;
	while(*last) ++last; --last;
	while(last >= n){
		base = 1, x = 0;
		FOR(i, 3){
			x += (*last-- - '0') * base;
			base *= 10;
			if(last < n) break;
		}
		d[j++] = x;
	}
}
void show(int *n){
	i = get_last(n);
	printf("%d", n[--i]);
	while(i--) printf("%03d", n[i]);
	puts("");
}
char n1[DIGITS], n2[DIGITS];
int main(void){
	int t; scanf("%d", &t);
	while(t--){
		for(i = 0; i < DIGITS; ++i) num1[i] = num2[i] = res[i] = 0;
		scanf("%s %s", n1, n2);
		read(n1, num1);
		read(n2, num2);
		//show(num1); puts("*"); show(num2);
		mul(num1, num2);
		show(res);
		//puts("-------------------");
	}
	return 0;
}

