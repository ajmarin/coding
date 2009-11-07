#include <cstdio>
#include <cctype>
#include <cstring>

char map[5][5], whereis[128], row[128], col[128];
bool seen[128];
char phrase[2048], tocipher[2048], cipherTIME[2048];
void encrypt(char a, char b){
	if(row[a] == row[b]){
		a = map[row[a]][(col[a]+1)%5];
		b = map[row[b]][(col[b]+1)%5];
	} else if(col[a] == col[b]){
		a = map[(row[a]+1)%5][col[a]];
		b = map[(row[b]+1)%5][col[b]];
	} else {
		int r1 = row[a], r2 = row[b];
		int c1 = col[a], c2 = col[b];
		a = map[r1][c2];
		b = map[r2][c1];
	}
	putc(a, stdout);
	putc(b, stdout);
}

int main(void){
	int N, map_pos;
	scanf("%d\n",&N);
	while(N--){
		memset(seen, 0, sizeof(seen));
		memset(phrase, 0, 2048);
		memset(tocipher, 0, 2048);
		fgets(phrase, 2048, stdin);
		fgets(tocipher, 2048, stdin);
		char *c = phrase;
		map_pos = 0;
		for(char *c = phrase; *c; ++c){
			if(islower(*c)) *c -= 32;
			if(!isupper(*c) || seen[*c]) continue;
			map[map_pos/5][map_pos%5] = *c;
			row[*c] = map_pos/5;
			col[*c] = map_pos%5;
			seen[*c] = 1;
			map_pos++;
		}
		for(char c = 'A'; c <= 'Z'; ++c){
			if(seen[c] || c == 'Q') continue;
			map[map_pos/5][map_pos%5] = c;
			row[c] = map_pos/5;
			col[c] = map_pos%5;
			map_pos++;
		}
		/*
		for(int i = 0; i < 5; ++i){
			for(int j =  0; j < 5; ++j)
				printf("%c",map[i][j]);
			putc(10, stdout);
		}
		putc(10, stdout);
		*/
		/* cipher time */
		char *ct = cipherTIME;
		for(c = tocipher; *c; ++c) if(islower(*c)) *ct++ = (*c)-32;
		*ct = *(ct+1) = 0;
		//puts(cipherTIME);
		for(char *c = cipherTIME, *n; ; ){
			if(!(*c)) break;
			n = c+1;
			if(*c == *n || (*n == 0)){
				encrypt(*c,'X');
				--n;
			} else encrypt(*c, *n);
			c = n+1;
		}
		putc(10, stdout);
	}
	return 0;
}
			


