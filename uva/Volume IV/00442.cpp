#include <cstdio>
char map[128], u[128];
struct matrix {
	int r, c;
	matrix(int _r = 0, int _c = 0){
		r = _r, c = _c;
	}
} m[1024];
char line[2048];
int mtop, stack[1024], top;
long long r;

int main(void){
	int a, b, n; scanf("%d", &n);
	char name[16]; bool error;
	for(int i = 0; i < 128; ++i) map[i] = -1, u[i] = 0;
	for(char c = 'A'; c <= 'Z'; ++c) u[c] = 1;
	for(int i = 0; i < n; ++i){
		scanf("%s %d %d", &name, &a, &b);
		map[*name] = i;
		m[i] = matrix(a, b);
	}
	while(scanf("%s", line) == 1){		
		error = r = top = 0;
		mtop = n;
		for(char *l = line; *l; ++l){
			if(*l == ')'){
				b = stack[--top];
				a = stack[--top];
				if(m[a].c == m[b].r){
					r += m[a].r * m[b].c * m[a].c;
					m[mtop++] = matrix(m[a].r, m[b].c);
					stack[top++] = n++;
				} else { error = 1; break; }
			} else if(u[*l] && map[*l] != -1){
				stack[top++] = map[*l];
			}
		}
		if(error) printf("error\n");
		else printf("%lld\n", r);		
	}
	return 0;
}
