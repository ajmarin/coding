#include <cstdio>
#include <cstdlib>

bool op[128];
char ans[128], line[128], s[128];
int p[128];

int main(void){
	int t; fgets(line, 128, stdin); t = atoi(line);
	for(int i = 0; i < 128; ++i) op[i] = false;
	for(char c = '0'; c <= '9'; ++c) op[c] = true;
	op['('] = op[')'] = true;
	op['+'] = op['-'] = op['*'] = op['/'] = true;
	p['('] = 0;
	p['+'] = p['-'] = 1;
	p['*'] = p['/'] = 2;
	fgets(line, 128, stdin);
	for(int top = 0; t--; ){
		int cans = 0;
		while(fgets(line, 128, stdin) && op[*line]){
			if(*line >= '0' && *line <= '9') ans[cans++] = *line;
			else if(*line == ')'){
				while(top && s[top - 1] != '(') ans[cans++] = s[--top];
				if(top) --top;
			} else if(*line == '(') s[top++] = *line; 
			else {
				if(top) while(top && p[s[top - 1]] >= p[*line])
					ans[cans++] = s[--top];
				s[top++] = *line;
			}
		}
		while(top) ans[cans++] = s[--top];
		ans[cans] = 0;
		puts(ans);
		if(t) puts("");
	}
	return 0;
}

