/////////////////////////////////
// 10205 - Stack 'em Up
/////////////////////////////////
#include<cstdio>
const char *suit_names[] = {"Clubs","Diamonds","Hearts","Spades"};
const char *value_names[] = {"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};
int deck[53];
int shuffle[101][53];
int old[53];
int cases,i,j,number, pos,shuffles_known, shuffling_now;
char line[100];
int main(void){
	scanf("%d\n",&cases);
	while(cases){
		cases--;
		for(i = 1; i < 53; i++) deck[i] = i;
		scanf("%d",&shuffles_known);
		for(i = 1; i <= shuffles_known; i++)
			for(j = 1; j < 53; j++)
				if(scanf("%d",&number) && number != j)	shuffle[i][number] = j;					
				else shuffle[i][j] = 0;
		getchar();
		while(gets(line)){
			if(line[0] == 0) break;
			sscanf(line,"%d",&shuffling_now);
			for(i = 1; i < 53; i++)
				if(shuffle[shuffling_now][i]){
					pos = shuffle[shuffling_now][i];
					if(pos > i) old[pos] = deck[pos];
					if(old[i]){
						deck[pos] = old[i];
						old[i] = 0;
					}
					else deck[pos] = deck[i];
				}
		}
		for(i = 1; i < 53; i++) printf("%s of %s\n",value_names[(deck[i]-1)%13],suit_names[(deck[i]-1)/13]);
		if(cases) putchar('\n');		
	}
}