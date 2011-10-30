#include <cstdio>

#define FOR(i,n) for(int i = 0; i < n; ++i)
const char *value = "23456789TJQKA";
int getVal(char v){ FOR(i, 13) if(value[i] == v) return i; return -1; }

struct card { int value; card *under; } c[52];
struct player { int cards; card *top, *bottom; } p[2], table; 

void playCard(int player){
	--p[player].cards;
	card *played = p[player].top;
	p[player].top = played -> under;
	played -> under = NULL;
	if(table.bottom != NULL) table.bottom -> under = played;
	else table.top = played;
	table.bottom = played;
}

int main(void){
	char cc[16];
	while(scanf("%s", cc) == 1 && cc[0] != '#'){
		int cp = 1, cnt = 0;
		p[0].bottom = p[0].top = NULL;
		p[1].bottom = p[1].top = NULL;
		p[0].cards = p[1].cards = 26;
		table.bottom = table.top = NULL;
		do {
			c[cnt].value = getVal(cc[1]);
			c[cnt].under = NULL;
			if(p[cp].top == NULL) p[cp].bottom = c + cnt;
			else c[cnt].under = p[cp].top;
			p[cp].top = c + cnt;
			cp = 1 - cp;
		} while(++cnt < 52 && scanf("%s", cc) == 1);
		for(cp = 1; p[cp].cards; cp = 1 - cp){
			if(table.bottom != NULL && table.bottom -> value > 8){ // pay penalty
				int must_pay = table.bottom -> value - 8, paid = 0;
				bool face = false;
				FOR(i, must_pay) if(!face && p[cp].top != NULL){ 
					playCard(cp);
					++paid;
					// if another face card shows up, penalty ends
					face |= table.bottom -> value > 8;
				}
				if(!face && paid < must_pay) break; // ran out of cards
				if(!face){ // other player gets all cards
					if(p[1 - cp].top == NULL){
						p[1 - cp].top = table.top;
						p[1 - cp].bottom = table.bottom;
					} else {
						p[1 - cp].bottom -> under = table.top;
						p[1 - cp].bottom = table.bottom;
					}
					p[1 - cp].cards = 52 - p[cp].cards;
					table.top = table.bottom = NULL;
				}
			} else playCard(cp); // just play top card
		}
		printf("%d%3d\n", 2 - cp, p[1 - cp].cards);
	}
	return 0;
}

