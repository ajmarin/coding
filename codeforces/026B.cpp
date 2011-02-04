#include <cstdio>
int main(void){
	int ans = 0, bal = 0;
	for(char c = getc(stdin); c == '(' || c == ')'; c = getc(stdin)){
		if(c == '(') ++ans, ++bal;
		if(c == ')' && bal) ++ans, --bal;
	}
	printf("%d\n", ans - bal);
	return 0;
}
	