#include <cstdio>
#include <cstdlib>
#include <cstring>

int main(void){
	char card[64], value[16];
	int t; scanf("%d", &t);
	for(int hn = 0, n; t-- && scanf("%d", &n) == 1; ){
		int oudlers = 0, score = 0, half = 0, wanted;
		while(getc(stdin) != 10);
		for(int i = 0; i < n; ++i){
			fgets(card, 64, stdin);
			card[strlen(card) - 1] = 0;
			++half;
			if(!strcmp(card, "fool") || !strcmp(card, "twenty-one of trumps") || 
				!strcmp(card, "one of trumps")){
				++oudlers;
				score += 4;
			} else {				
				sscanf(card, "%s", value);
				if(!strcmp(value, "king")) score += 4; 
				else if(!strcmp(value, "queen")) score += 3;
				else if(!strcmp(value, "knight")) score += 2;
				else if(!strcmp(value, "jack")) score += 1;
			}
		}
		switch(oudlers){
			case 0: wanted = 56; break;
			case 1: wanted = 51; break;
			case 2: wanted = 41; break;
			case 3: wanted = 36; break;
		}
		score += half >> 1;
		//printf("Score = %d, WANTED = %d\n", score, wanted);
		printf("Hand #%d\nGame %s by %d point(s).\n", 
			++hn, score < wanted ? "lost" : "won", abs(score - wanted));
		if(t) puts("");
	}
	return 0;
}
