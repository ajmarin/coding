#include <cstdio>

int op[128], T = 0;
char s[512];
char top(){ return s[T - 1]; }
char pop(){ return s[--T]; }
int main(void){
	int t;
	for(int i = 0; i < 128; ++i) op[i] = 0;
	op['('] = op[')'] = 1;
	op['+'] = op['-'] = 2;
	op['*'] = op['/'] = 3;
	op['^'] = 4;
	scanf("%d", &t);
	while(t--){
		scanf("%s", s);
		for(char *p = s; *p; ++p)
			if(op[*p]){
				if(*p == '(') s[T++] = '(';
				else if(*p == ')') while(s[--T] != '(') putc(s[T], stdout);
				else {
					while(T && op[s[T - 1]] >= op[*p]) putc(s[--T], stdout);
					s[T++] = *p;
				}				
			} else putc(*p, stdout);
		while(T) putc(s[--T], stdout);
		putc(10, stdout);
	}
	return 0;
}
