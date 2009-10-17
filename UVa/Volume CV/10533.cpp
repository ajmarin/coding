#include <cctype>
#include <cstdio>

#define MAXN 1<<20
#define SQM  1025
#define IN getc(stdin)
bool p[MAXN + 1];
int tree[MAXN + 1], f[MAXN + 1];
void fastint( register int *n ){
	register char c;
	*n = 0;
	while(!isdigit(c = IN));
	do{ (*n) = (*n) * 10 + c - '0'; c = IN; } while(isdigit(c));
}
void update(int idx){
	while (idx <= MAXN)	++tree[idx], idx += (idx & -idx);
}
int read(int idx){
	if(f[idx]) return f[idx];
	int sum = 0;
	if(idx > MAXN) idx = MAXN;
	while(idx > 0) sum += tree[idx], idx -= (idx & -idx);
	f[idx] = sum;
	return f[idx];
}
bool digitprime(int x){
	int s =  0;
	while(x) s += x % 10, x /= 10;
	return p[s];
}
int main(void){
	for(int i = 0; i < MAXN; i++) tree[i] = f[i] = 0, p[i] = 1;
	p[0] = p[1] = 0; p[2] = 1;
	for(int i = 4; i < MAXN; i+=2) p[i] = 0;
	update(2);
	for(int i = 3; i < SQM; i += 2)
		if(p[i]){
			if(digitprime(i)) update(i);
			for(int j = i * i; j < MAXN; j += i) p[j] = 0;
		}
	for(int i = SQM; i < MAXN; i += 2)
		if(p[i] && digitprime(i)) update(i);
	int a, b, T;
	scanf("%d",&T);
	while(T--){
		fastint(&a); fastint(&b);
		printf("%d\n", read(b) - read(a) + (p[a] && digitprime(a)));
	}
	return 0;
}

