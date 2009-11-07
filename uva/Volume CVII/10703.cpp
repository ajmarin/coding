/////////////////////////////////
// 10703 - Free spots
/////////////////////////////////
#include<cstdio>
#include<cstring>
#define MIN(a,b) (a<b?a:b)
#define MAX(a,b) (a>b?a:b)
bool free[501][501];
unsigned int free_spots,ex,ey,h,i,j,n,sx,sy,w,x1,x2,y1,y2;
int main(void){
	while(scanf("%u %u %u",&w,&h,&n) && w){
		free_spots = w*h;
		memset(free,1,251001);
		while(n--){
			scanf("%u %u %u %u",&x1,&y1,&x2,&y2);
			sx = MIN(x1,x2)-1; ex = MAX(x1,x2);
			sy = MIN(y1,y2)-1; ey = MAX(y1,y2);
			for(i = sx; i != ex; i++)
				for(j = sy; j != ey; j++)
					if(free[i][j]) free[i][j] = 0,free_spots--;
		}
		if(free_spots>1){
			printf("There are %u empty spots.\n",free_spots);
		} else if(free_spots) printf("There is one empty spot.\n");
		else printf("There is no empty spots.\n");
	}	
	return 0;
}

