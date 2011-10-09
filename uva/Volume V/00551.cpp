#include <cstdio>

int stack[3072], top = 0;
char close[128], line[3072], open[128];
void do_open(char c){ stack[top++] = open[c]; }
void try_close(char c, int &inv, int index){
	if(stack[top - 1] == close[c]) --top;
	else inv = index;
}
int main(void){
	for(int i = 0; i < 128; ++i) close[i] = open[i] = 0;
	open['('] = close[')'] = 1;
	open['{'] = close['}'] = 2;
	open['<'] = close['>'] = 3;
	open['['] = close[']'] = 4;
	open['*'] = close['*'] = 5;
	for(int cnt, invalid; gets(line); ){
		for(int i = cnt = invalid = top = 0; !invalid && line[i]; ++i){
			++cnt;
			if(open[line[i]] && (line[i] != '*' || (i && line[i - 1] == '('))){
				do_open(line[i]);
				if(line[i] == '*' && i && line[i - 1] == '(') 
					stack[--top-1] = 5, line[i] = '_', --cnt;
			}
			if(close[line[i]] && (line[i] != '*' || line[i + 1] == ')')){
				try_close(line[i], invalid, cnt);
				if(line[i] == '*' && line[i + 1] == ')') ++i;
			}
		}
		if(invalid || top) printf("NO %d\n", invalid ? invalid : cnt + 1);
		else puts("YES");
	}
	return 0;
}

