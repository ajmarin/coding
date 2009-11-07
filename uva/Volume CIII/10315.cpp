/////////////////////////////////
// 10315 - Poker Hands
/////////////////////////////////
#include<cstdio>
#include<cstring>
const char suits[] = "CDHS";
const char values[] = "A23456789TJQK";
int i,p1 = 0, p2 = 0,aux,p1wins = 0, p2wins = 0;
bool com = 0,com2 = 0;
char line[500], *card;
int cards[2][5];
void qsort(int k,int e,int d){
	if(d > e){
		int pivo = cards[k][d], i = e -1, j = d,t;		
		do {
			do ++i; while(cards[k][i] < pivo);
			do --j; while(cards[k][j] > pivo && j != e);
			t = cards[k][i];
			cards[k][i] = cards[k][j];
			cards[k][j] = t;
		} while (j > i);
		cards[k][j] = cards[k][i];
		cards[k][i] = cards[k][d];
		cards[k][d] = t;
		qsort(k,e,i-1);
		qsort(k,i+1,d);
	}	
}
int rank_card()
{
	int i,j;
	char value = card[0],suit = card[1];
	for (i=0; ; i++)
		if (values[i]==value)
			for (j=0; ; j++)
				if (suits[j]==suit)
					return (i*4+j);
}
char suit(int card){
	return( suits[card % 4] );
}
char value(int card){
	return( values[card/4] );
}
int royalflush(int k){
	for(i = 0; i < 4; i++) if(cards[k][i]%4 != cards[k][i+1]%4) return 0;
	if(cards[k][0]/4 != 0) return 0;
	for(i = 1; i < 5; i++) if(cards[k][i]/4 != (8+i)) return 0;
	return 10000;
}
int straightflush(int k){
	int v = cards[k][0]/4, s = cards[k][0]%4;
	for(i = 1; i < 5; i++) if(v+i != cards[k][i]/4 || cards[k][i]%4 != s) return 0;
	return (9000+(cards[k][0]/4?cards[k][4]/4:13));
}
int fourofakind(int k){
	return((cards[k][0]/4 == cards[k][3]/4 || cards[k][1]/4 == cards[k][4]/4)? 8000+cards[k][2]/4:0);
}
int fullhouse(int k){
	bool has = false;
	if(cards[k][0]/4 == cards[k][2]/4 && cards[k][3]/4 == cards[k][4]/4) has = true;
	else if(cards[k][0]/4 == cards[k][1]/4 && cards[k][2]/4 == cards[k][4]/4) has = true;
	return (has? 7000+(cards[k][2]/4?cards[k][2]/4:13):0);
}
int flush(int k){
	int suit = cards[k][0]%4;
	for(i = 1; i < 5; i++) if(cards[k][i]%4 != suit) return 0;
	return (6000+(cards[k][0]/4?cards[k][4]/4:13));
}
int straight(int k){
	int v = cards[k][0]/4;
	for(i = 1; i < 5; i++) if(v+i != cards[k][i]/4) return 0;
	return (5000+(cards[k][0]/4?cards[k][4]/4:13));
}
int threeofakind(int k){
	bool has = false;
	if(cards[k][0]/4 == cards[k][2]/4) has = true;
	else if(cards[k][1]/4 == cards[k][3]/4) has = true;
	else if(cards[k][2]/4 == cards[k][4]/4) has = true;
	return(has? 4000+(cards[k][2]/4?cards[k][2]/4:13):0);
}

int twopairs(int k){
	bool has = false;
	if((cards[k][0]/4 == cards[k][1]/4) && (cards[k][2]/4 == cards[k][3]/4)) has = true;
	else if((cards[k][0]/4 == cards[k][1]/4) && (cards[k][3]/4 == cards[k][4]/4)) has = true;
	else if((cards[k][1]/4 == cards[k][2]/4) && (cards[k][3]/4 == cards[k][4]/4)) has = true;
	int inc = (cards[k][1]/4?cards[k][1]/4:13),inc2 = (cards[k][3]/4?cards[k][i]/4:13);
	return (has?3000+inc+10*inc2:0);
}
int pair(int k){
	for(int i = 0; i < 4; i++) 
		if(cards[k][i]/4 == cards[k][i+1]/4)			
			return 2000+(cards[k][i]/4?cards[k][i]/4:13);		
	return 0;
}
int getscore(int k){
	int score = 0;
	score = royalflush(k);
	if(score) return score;
	score = straightflush(k);
	if(score) return score;
	score = fourofakind(k);
	if(score) return score;
	score = fullhouse(k);
	if(score) return score;
	score = flush(k);
	if(score) return score;
	score = straight(k);
	if(score) return score;
	score = threeofakind(k);
	if(score) return score;
	score = twopairs(k);
	if(score) return score;
	score = pair(k);	
	return score;
}
int main(void){
	int gamen = 0;
	while(gets(line)){
		gamen++;
		card = strtok(line," ");
		for(i = 0; i < 10; card = strtok(NULL," "),i++)
			cards[i/5][i%5] = rank_card();			
		qsort(0,0,4);
		qsort(1,0,4);
		p1 = getscore(0);
		p2 = getscore(1);		
		aux = 4;
		if(p1 == p2){
			if(cards[0][0]/4==0){
				cards[0][0] = 52;
				qsort(0,0,4);
			}
			if(cards[1][0]/4 == 0){
				cards[1][0] = 52;
				qsort(1,0,4);
			}				
			while(p1 == p2 && aux > -1){
				p1 += cards[0][aux]/4;
				p2 += cards[1][aux]/4;
				aux--;
			}
		}		
		if(p1 == p2) printf("Tie.\n");
		else if(p1>p2) printf("Black wins.\n");
		else printf("White wins.\n");
	}
}
