/////////////////////////////////
// 10267 - Graphical Editor
/////////////////////////////////
#include<cstdio>
#define MIN(a,b) (a < b? a : b)
#define MAX(a,b) (a < b? b : a)
int c,i,j,l,x,x2,y,y2,startx,starty;
char cmd,color,pic[251][251],name[12],bkp,line[600];
void fill(int x, int y){
	if(x < 1 || x > c || y > l || y < 1 || pic[x][y] != bkp) return;
	pic[x][y] = color;
	fill(x-1,y);
	fill(x,y-1);
	fill(x,y+1);
	fill(x+1,y);
}
void clear(){
	for(i = 1; i <= c; i++) for(j = 1; j <= l; j++) pic[i][j] = 'O';	
}
int main(void){
	while(true){
		cmd = getchar();
		if(cmd == 'I'){
			scanf("%d %d\n",&c,&l);
			clear();
		}
		else if(cmd == 'C'){
			clear();
			getchar();
		}
		else if(cmd == 'L'){
			scanf("%d %d %c\n",&x,&y,&color);			
			pic[x][y] = color;
		}
		else if(cmd == 'V'){
			scanf("%d %d %d %c\n",&x,&y,&y2,&color);			
			starty = MIN(y,y2);
			y2 = MAX(y,y2);
			if(y2 > l) y2 = l;
			for(i = starty; i <= y2; i++) pic[x][i] = color;			
		}
		else if(cmd == 'H'){
			scanf("%d %d %d %c\n",&x,&x2,&y,&color);			
			startx = MIN(x,x2);
			x2 = MAX(x,x2);
			if(x2 > c) x2 = c;
			for(i = startx; i <= x2; i++) pic[i][y] = color;			
		}
		else if(cmd == 'K'){
			scanf("%d %d %d %d %c\n",&x,&y,&x2,&y2,&color);
			startx = MIN(x,x2);
			x2 = MAX(x,x2);
			starty = MIN(y,y2);
			y2 = MAX(y,y2);
			if(x2 > c) x2 = c;
			if(y2 > l) y2 = l;
			for(i = startx; i <= x2; i++) for(j = starty; j <= y2; j++) pic[i][j] = color;			
		}
		else if(cmd == 'F'){
			scanf("%d %d %c\n",&x,&y,&color);
			bkp = pic[x][y];
			if(bkp == color) continue;		
			fill(x,y);			
		}
		else if(cmd == 'S'){
			scanf("%s\n",&name);
			printf("%s\n",name);
			for(j = 1; j <= l; putchar('\n'),j++) for(i = 1; i <= c; i++) putchar(pic[i][j]);			
		}
		else if(cmd == 'X') break;
		else gets(line);
	}
	return 0;
}