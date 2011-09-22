#include <cstdio>
#include <cstring>

const char *suits = "SHDC";

int suit(char c){ for(int i = 0; i < 4; ++i) if(suits[i] == c) return i; }

char line[1024];
int main(void){
	while(fgets(line, 1024, stdin)){
		int score = 0, stopped = 0;
		int sc[4] = {0, 0, 0, 0};
		int ace[4] = {0, 0, 0, 0};
		int jack[4] = {0, 0, 0, 0};
		int king[4] = {0, 0, 0, 0};
		int queen[4] = {0, 0, 0, 0};
		for(char *p = strtok(line, " "); p != NULL; p = strtok(NULL, " ")){
			/* Rule 1 */
			if(p[0] == 'A') score += 4;
			else if(p[0] == 'K') score += 3;
			else if(p[0] == 'Q') score += 2;
			else if(p[0] == 'J') score += 1;
			int s = suit(p[1]);
			sc[s]++; 
			ace[s] += p[0] == 'A';
			king[s]+= p[0] == 'K';
			queen[s] += p[0] == 'Q';
			jack[s] += p[0] == 'J';
		}
		for(int i = 0; i < 4; ++i){
			/* Rules 2, 3, 4 */
			if(king[i] && sc[i] < 2) --score;
			if(queen[i] && sc[i] < 3) --score;
			if(jack[i] && sc[i] < 4) --score;
			if(ace[i] || (king[i] && sc[i] >= 2) || (queen[i] && sc[i] >= 3)) stopped++;
		}
		if(score >= 16 && stopped == 4){ // Bid no trump
			puts("BID NO-TRUMP");
		} else {
			int max_sc = 0, play;
			for(int i = 0; i < 4; ++i){
				if(sc[i] == 2) score++; // Rule 5
				if(sc[i] < 2) score += 2; // Rules 6 and 7
				if(sc[i] > max_sc){
					max_sc = sc[i];
					play = i;
				}
			}
			if(score < 14) puts("PASS");
			else printf("BID %c\n", suits[play]);
		}
	}
	return 0;
}

