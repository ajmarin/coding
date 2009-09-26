#include<cstdio>
#include<cstring>
int COLUMNS, i, j, LINES, max;
int m[25][25];
void F(int xpos, int ypos, int t_owned){
	//printf("%d,%d, t_owned = %d\n",xpos,ypos,t_owned);
	/* baixo esquerda */
	if(t_owned > max) max = t_owned;
	if(xpos>1 && ypos>1 && m[xpos-1][ypos-1]==2 && m[xpos-2][ypos-2]==0){
		m[xpos-1][ypos-1] = m[xpos][ypos] = 0;
		m[xpos-2][ypos-2] = 1;	
		F(xpos-2,ypos-2, t_owned+1);
		m[xpos-2][ypos-2] = 0;
		m[xpos][ypos] = 1;
		m[xpos-1][ypos-1] = 2;
	}
	/* baixo direita */
	if(xpos>1 && ypos<COLUMNS-2 && m[xpos-1][ypos+1]==2 && m[xpos-2][ypos+2]==0){
		m[xpos-1][ypos+1] = m[xpos][ypos] = 0;
		m[xpos-2][ypos+2] = 1;
		F(xpos-2,ypos+2, t_owned+1);
		m[xpos-2][ypos+2] = 0;
		m[xpos][ypos] = 1;
		m[xpos-1][ypos+1] = 2;
	}
	/* cima esquerda */
	if(xpos<LINES-2 && ypos>1 && m[xpos+1][ypos-1]==2 && m[xpos+2][ypos-2]==0){
		m[xpos+1][ypos-1] = m[xpos][ypos] = 0;
		m[xpos+2][ypos-2] = 1;
		F(xpos+2,ypos-2, t_owned+1);
		m[xpos+2][ypos-2] = 0;
		m[xpos][ypos] = 1;
		m[xpos+1][ypos-1] = 2;
	}
	/* cima direita */
	if(xpos<LINES-2 && ypos<COLUMNS-2 && m[xpos+1][ypos+1]==2 && m[xpos+2][ypos+2]==0){
		m[xpos+1][ypos+1] = m[xpos][ypos] = 0;
		m[xpos+2][ypos+2] = 1;
		F(xpos+2,ypos+2, t_owned+1);
		m[xpos+2][ypos+2] = 0;
		m[xpos][ypos] = 1;
		m[xpos+1][ypos+1] = 2;
	}	
}
int main(void){
	while(scanf("%d%d",&LINES,&COLUMNS) && LINES){
		memset(m,0,sizeof(m));
		max = 0;
		for(i = 0; i < LINES; i++)
			for(j = i&1; j < COLUMNS; j+=2)
				scanf("%d",&m[i][j]);			
		for(i = 0; i < LINES; i++)
			for(j = i&1; j < COLUMNS; j+=2)
				if(m[i][j] == 1)					
					F(i,j,0);
		printf("%d\n",max);
	}
	return 0;
}
	
