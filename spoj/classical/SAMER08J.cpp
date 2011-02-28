#include <cstdio>
int p_cards[10][300], deck[300], card_num[10];
int best, deck_top, dir, didx, i, j, M, N, P, rnum, top, tnum, tsuit, winner;
char rsuit;
bool pen;
char ss(int a){
	switch(a){
		case 0: return 'C';
		case 1: return 'D';
		case 2: return 'H';
		case 3: return 'S';
	}
}
int SUIT(char s){
	switch(s){
		case 'C': return 0;
		case 'D': return 1;
		case 'H': return 2;
		case 'S': return 3;
	}
}
void read_card(int *x){
	scanf("%d %c",&rnum,&rsuit);
	*x = ((rnum*4)+SUIT(rsuit));
}
void buy(int k, int hm){
	while(hm--)	p_cards[k][card_num[k]++] = deck[deck_top++];
}
void update_discard(int x, int idx){
	if((x/4 == tnum || x%4 == tsuit) && x > best) best = x, didx = idx;
}
void play(int k){
	best = - 1;
	if(k < 0) k += P;
	k %= P;
	if(!pen){
		pen = 1;
		if(tnum == 7) 		buy(k, 2), k += dir;
		else if(tnum == 1) 	buy(k, 1), k += dir;
		else if(tnum == 11)	k += dir;
	}
	if(k < 0) k += P;
	k %= P;
	for(i = 0; i < card_num[k]; i++)
		update_discard(p_cards[k][i], i);
	if(best == -1)
		buy(k,1), update_discard(p_cards[k][card_num[k]-1],card_num[k]-1);
	if(best != -1){
		top = best;
		pen = 0;
		tnum = top/4; tsuit = top%4;
		if(tnum == 12) dir = -dir;
		p_cards[k][didx] = p_cards[k][--card_num[k]];
		if(card_num[k] == 0){ winner = k; return; }
	}
	play(k+dir);
}
int main(void){
	while(scanf("%d%d%d",&P,&M,&N) && (P || M || N)){
		dir = 1; pen = 0;
		for(i = 0; i < P; i++){
			card_num[i] = M;
			for(j = 0; j < M; j++) read_card(&p_cards[i][j]);
		}
		read_card(&top);
		tnum = top/4; tsuit = top%4;
		if(tnum == 12) dir = -dir;
		N -= (P * M + 1);
		for(deck_top = i = 0; i < N; i++) read_card(&deck[i]);
		play(0);
		printf("%d\n",winner+1);
	}
}

