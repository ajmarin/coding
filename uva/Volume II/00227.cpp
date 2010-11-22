#include <cstdio>
#define IN getc(stdin)
char game[8][8];
int main(void){
	for(int pn = 0; fgets(game[0], 8, stdin) && game[0][0] != 'Z'; ){
		bool valid = 1;
		char in, *q, *s, t;
		int r, c; 
		if(pn) putc(10, stdout);
		for(int i = 1; i < 5; ++i) fgets(game[i], 8, stdin);
		for(int i = 0; i < 5; ++i) for(int j = 0; j < 5; ++j)
			if(game[i][j] == ' ') r = i, c = j;
		for(in = IN; in != '0'; in = IN){
			q = &game[r][c];
			if(in == 'A') --r;
			else if(in == 'B') ++r;
			else if(in == 'R') ++c;
			else if(in == 'L') --c;
			else continue;
			valid &= (r >= 0 && c >= 0 && r < 5 && c < 5);
			if(!valid) continue;
			s = &game[r][c];
			t = *q;
			*q = *s;
			*s = t;
		}
		while(in != 10) in = IN;
		printf("Puzzle #%d:\n", ++pn);
		if(!valid) puts("This puzzle has no final configuration.");
		else for(int i = 0; i < 5; ++i){
			for(int j = 0; j < 5; ++j){
				if(j) putc(32, stdout);
				putc(game[i][j], stdout);
			}
			putc(10, stdout);
		}
	}
	return 0;
}

