#include <cctype>
#include <cstdio>
#define IN getc(stdin)
int pos[8] = {0, 1, 4, 11, 26, 57, 120, 247, };
char msg[512];
int main(void){
	char c;
	while(fgets(msg, 256, stdin)){
		while(1){
			int seg = 0;
			for(int dc = 0; dc < 3; ){
				c = IN;
				if(isdigit(c)) seg = (seg << 1) + (c - '0'), dc++;
			}
			if(!seg) break;
			int b = pos[seg - 1], end = (1 << seg) - 1, n = 0;
			while(1){
				n = 0;
				for(int dc = 0; dc < seg; ){
					c = IN;
					if(isdigit(c)) n = (n << 1) + (c - '0'), dc++;
				}
				if(n == end) break;
				putc(msg[b + n], stdout);
			}
		}
		putc(10, stdout);
		while(c != 10) c = IN;
	}
	return 0;
}

