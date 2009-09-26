/////////////////////////////////
// 00114 - Simulation Wizardry
/////////////////////////////////
#include<cstdio>
#include<cstring>
char brd[52][52];
int val[52][52];
int cost[52][52];
unsigned int bnum, c, d, i, j, l, ox, oy, x, y, wc;
int life, score, total_score;
bool showw = 0;
void rotate(){
	if(d) d--;
	else d+=3;
}
void move(int A,int B){	
	if(brd[A][B] == '.') x = A, y = B;
	else score += val[A][B], life -= cost[A][B], rotate();
}
void do_move(){
	switch(d){
		case 0: move(x+1,y);break;
		case 1: move(x,y+1);break;
		case 2: move(x-1,y);break;
		case 3: move(x,y-1);break;
	}	
	life--;
}
int main(void){
	memset(val,0,sizeof(val));
	memset(cost,0,sizeof(cost));
	scanf("%d %d %d %d",&c,&l,&wc,&bnum);
	for(i = 1; i <= c; i++)
		brd[1][i] = brd[l][i] = 'W',
		cost[1][i] = cost[l][i] = wc;
	for(i = 1; i <= l; i++)
		brd[i][1] = brd[i][c] = 'W',
		cost[i][1] = cost[i][c] = wc;
	for(i = 2; i < c; i++)
		for(j = 2; j < l; j++)
			brd[j][i] = '.';	
	for(i = 0; i < bnum; i++){
		scanf("%d %d ",&x,&y),
		brd[x][y] = 'B',
		scanf("%d %d",&val[x][y],&cost[x][y]);
	}	
	total_score = 0;
	while(scanf("%d %d %d %d",&x,&y,&d,&life)!=EOF){
		score = 0;
		while(life > 1)	do_move();
		total_score += score;
		printf("%d\n",score);
	}
	printf("%d\n",total_score);
	return 0;
}
	
