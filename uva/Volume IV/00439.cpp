/////////////////////////////////
// 00439 - Knight Moves
/////////////////////////////////
#include<cstdio>
#include<cstring>
struct move{	
	char n,x,y;
	move(){}
	move(char a, char b, char c): n ( c ), x( a ), y ( b ){}	
}mov[1000000], aux;
bool alive,t[12][12];
unsigned int head,i,j,tail;
char cx,cy,dx,dy,m,p1[3],p2[3];
void check(char x, char y){
	if(t[x][y]){
		if(x != dx || y != dy) mov[tail++] = move(x,y,m+1);
		else alive = 0;
	}
}
int main(void){
	for(i = 0; i < 12; i++)
		t[0][i] = t[1][i] = t[10][i] = t[11][i] =
		t[i][0] = t[i][1] = t[i][10] = t[i][11] = 0;
	for(i = 2; i < 10; i++) for(j = 2; j < 10; j++) t[i][j] = 1;
	while(scanf("%s %s",&p1,&p2)!=EOF){
		head = tail = 0; m = -1; alive = 1;
		dx = p2[0]-'a'+2; dy = p2[1]-'0'+1;
		check(p1[0]-'a'+2,p1[1]-'0'+1);
		while(alive){
			aux = mov[head++];
			cx = aux.x; cy = aux.y; m = aux.n;
			check(cx+2,cy-1);
			check(cx+2,cy+1);
			check(cx-2,cy-1);
			check(cx-2,cy+1);
			check(cx+1,cy-2);
			check(cx+1,cy+2);
			check(cx-1,cy-2);
			check(cx-1,cy+2);
		}
		printf("To get from %s to %s takes %u knight moves.\n",p1,p2,m+1);
	}
	return 0;
}

