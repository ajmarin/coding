/////////////////////////////////
// 00104 - Arbitrage
/////////////////////////////////
#include<cstdio>
#include<cstring>
unsigned int curr;
double t[20][20][21], temp;
char found, i, j, k, p[20][20][21], w;
bool sm = 0;
const char *NASE = "no arbitrage sequence exists";
void trace(char x, char y, char l){
	if(l) trace(x,p[x][y][l],l-1),printf(" %u",y+1);
	else printf("%u",x+1);
}
int main(void){
	while(scanf("%u",&curr)!=EOF){
		memset(p,0,sizeof(p));
		for(i = 0; i < curr; t[i][i][1] = 1.00,i++)
			for(j = 0; j < curr; j++){
				for(k = 2; k <= curr; k++) t[i][j][k] = 0;
				if(i != j) 
					scanf("%lf",&t[i][j][1]);
			}
		found = 0;		
		for(w = 2; w <= curr; w++){		
			for(k = 0; k < curr; k++){
				for(i = 0; i < curr; i++){
					for(j = 0; j < curr; j++)
						if(t[i][j][w] < t[i][k][w-1]*t[k][j][1])
							t[i][j][w] = t[i][k][w-1]*t[k][j][1],
							p[i][j][w] = k;
					if(t[i][i][w] > 1.01){
						found = i; break;
					}
				}
				if(found){							
					trace(found,found,w);
					putchar('\n');
					break;
				}
			}
			if(found) break;
		}
		if(!found) puts(NASE);
	}
	return 0;
}
