#include <cstdio>
#define MAXB 1024
char b[MAXB];
int bidx = 0;
void flushb(){
	fwrite(b, 1, bidx, stdout);
	bidx = 0;
}
void bufchar(char c){
	b[bidx++] = c;
	if(bidx == MAXB) flushb();
}
void bufstr(char *s){ while(*s) bufchar(*s++); }
void bufcase(int x){
	bufstr("Case ");
	char num[10], nidx = 0;
	for(nidx = 0; x; ++nidx, x /= 10) num[nidx] = (x % 10) + '0';
	while(nidx--) bufchar(num[nidx]);
	bufstr(":\n");	
}
int main(void){
	int t; scanf("%d", &t);
	for(int cnum = 0, n; cnum++ < t && scanf("%d", &n) == 1; ){
		for(char c = getc( stdin ); c != '\n'; c = getc( stdin ));
		bufcase(cnum);
		for(int i = 0; i < n; ++i){
			for(char p = -1, c = getc( stdin ); c != EOF; c = getc( stdin )){
				if(c != ' ' || p != ' ') bufchar(c);
				if((p = c) == '\n') break;
			}
		}
		if(cnum != t) bufchar('\n');
	}
	if(bidx) flushb();
	return 0;
}

