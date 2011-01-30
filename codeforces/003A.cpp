#include <cstdio>

int moves = 0, ox, oy, wx, wy;
void path(int x, int y){
	if(x == wx && y == wy){
		printf("%d\n", moves);
		return;
	}
	++moves;
	if(x == wx){
		if(y > wy) path(x, y - 1), puts("D");
		else path(x, y + 1), puts("U");
	} else if(y == wy){
		if(x > wx) path(x - 1, y), puts("L"); 
		else path(x + 1, y), puts("R");
	} else if(x > wx && y > wy) path(x - 1, y - 1), puts("LD");
	else if(x > wx && y < wy) path(x - 1, y + 1), puts("LU");
	else if(x < wx && y > wy) path(x + 1, y - 1), puts("RD");
	else path(x + 1, y + 1), puts("RU");
}
char ip[4], fp[4];
int main(void){
	scanf("%[a-h1-8]\n", ip);// printf("ip = %s\n", ip);
	scanf("%[a-h1-8]\n", fp);// printf("fp = %s\n", fp);
	ox = ip[0] - 'a' + 1; oy = ip[1] - '0';
	wx = fp[0] - 'a' + 1; wy = fp[1] - '0';
	//printf("FROM (%d, %d) TO (%d, %d)\n", ox, oy, wx, wy);
	path(ox, oy);
	return 0;
}

