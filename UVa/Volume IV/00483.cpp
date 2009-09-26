/////////////////////////////////
// 00483 - Word Scramble
/////////////////////////////////
#include<cstdio>
#include<cctype>
char stack[100];
int top=-1;

void push(char c){
	stack[++top]=c;
}

char pop(){	
	return stack[top--];
}


int main(void){
	char ch;
	while((ch=getchar())!=EOF){
		if(isspace(ch)){
			while(top > -1)putchar(pop());
			putchar(ch);
			
		}
		else push(ch);
	}
	while(top > -1)
		putchar(pop());
	return 0;
}
