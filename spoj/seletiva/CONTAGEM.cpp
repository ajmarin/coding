#include <cstdio>
long long c;
char word[60];
void run(char s, int k, long long cost){
	if(s == 'q')
		switch(word[k]){
			case 0: c += cost; return;
			default: run('q',k+1,(cost<<1)); break;
		}
	else
		switch(word[k]){
			case 0: return;
			case 'a': run('p',k+1,cost); break;
			case 'b':
				run('p',k+1,cost);
				run('q',k+1,cost);
				break;
		}
	
}
int main(void){
	for(int i = 1; gets(word); i++){
		c = 0;
		run('p',0,1);
		printf("Palavra %d\n%lld\n\n",i,c);
	}
	return 0;
}
