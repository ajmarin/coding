/////////////////////////////////
// 00673 - Parentheses Balance
/////////////////////////////////
#include<cstdio>
char line[140];
char stack[140];
int i, valid, top;
int main(void){
	gets(line);
	while(gets(line)){
		for(top = i = 0,valid = 1; line[i]!='\0' && valid; i++){
			if(line[i]=='(') stack[top++] = '(';
			else if(line[i]==')'){
				if(stack[top-1] == '(') top--;
				else valid = 0;
			}
			else if(line[i] == '[') stack[top++] = '[';
			else {
				if(stack[top-1] == '[') top--;
				else valid = 0;
			}
		}
		if(valid && !top) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
