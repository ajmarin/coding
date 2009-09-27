#include <cstdio>
#include <cstring>
char digits(unsigned int x){
	register char ret = 0;
	while(x) x/=10, ret++;
	return ret;
}
int main(void){
	register char c;
	unsigned int cnt;
	bool mark;
	while((c = getc( stdin )) != 'E'){
		cnt = mark = 1;
		if(c == '1') mark = 0;
		while((c = getc( stdin )) != '\n') cnt++;
		if(cnt == 1) printf("%d\n",cnt+mark);
		else if(cnt < 10) printf("%d\n",3);
		else printf("%d\n",4);
	}
	return 0;
}


