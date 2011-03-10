#include <cstdio>
int d[4], v[128];
char r[4] = {'i', 'x', 'c', 'm'};
int main(void){
	char n1[16], n2[16], *p;
	int i, m, t, n;
	for(int i = 0; i < 128; ++i) v[i] = 0;
	v['m'] = 1000; v['c'] = 100; v['x'] = 10; v['i'] = 1;
	for(scanf("%d", &t); t--; ){
		scanf("%s %s", n1, n2);
		n = 0; m = 1;
		for(p = n1; *p; ++p){
			if(v[*p]) n += v[*p] * m, m = 1;
			else m = *p - '0';
		}
		for(p = n2; *p; ++p){
			if(v[*p]) n += v[*p] * m, m = 1;
			else m = *p - '0';
		}
		for(i = 0; n; ++i){ d[i] = n % 10; n /= 10; }
		while(i--){
			if(d[i] > 1) printf("%d", d[i]);
			if(d[i]) putc(r[i], stdout);
		}
		puts("");
	}
	return 0;
}

