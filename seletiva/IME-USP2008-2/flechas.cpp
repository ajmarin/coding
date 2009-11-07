#include<cstdio>
char dname[8][3] = { " N", "NE", " E", "SE", " S", "SW", " W", "NW" };
int fdir[32], m[8][8], t[8][8];
int cnum = 1, i, j, n, sum;
bool done;
void bt(int f);
void fill(int f, int WHERE, int xo, int yo, int vx, int vy){
	int x,y; bool fudeu = 0;
	if(done) return;
	for(x = xo, y = yo; !fudeu && x >= 0 && x < n && y >= 0 && y < n ; x+=vx, y+=vy)
		t[x][y]++, sum--, fudeu = t[x][y] > m[x][y];
	if(!fudeu && (sum <= (4*n-f-1)*n)) fdir[f] = WHERE, bt(f+1);	
	for(x-=vx, y-=vy ; x >= 0 && x < n && y >= 0 && y < n; x-=vx, y-=vy)
		t[x][y]--, sum++;
}
bool possoAplicarF(){
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			if(t[i][j] != m[i][j]) return 0;
	return 1;
}
void bt(int f){
	//if(done) return;	
	int side = f/n, an = f%n;
	if(side == 0){
		fill(f, 4, 0, an, +1, 0);
		if(an < n-1) fill(f, 3, 0, an+1, +1, +1);
		if(an) fill(f, 5, 0, an-1, +1, -1);
	} else if(side == 1){
		fill(f, 6, an, n-1, 0, -1);
		if(an < n-1) fill(f, 5, an+1, n-1, +1, -1);
		if(an) fill(f, 7, an-1, n-1, -1, -1);
	} else if(side == 2){
		fill(f, 0, n-1, n - (an+1), -1, 0);
		if(an < n-1) fill(f, 7, n-1, n - (an+2), -1, -1);
		if(an) fill(f, 1, n-1, n - an, -1, +1);
	} else if(side == 3){
		fill(f, 2, n - (an+1), 0, 0, +1);
		if(an < n-1) fill(f, 1, n - (an+2), 0, -1, +1);
		if(an) fill(f, 3, n - an, 0, +1, +1);
	} else {
		done = possoAplicarF();
	}
}
int main(void){
	while(scanf("%d",&n) && n){
		done = 0;
		for(sum = i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				  scanf("%d",&m[i][j]), sum += m[i][j], t[i][j] = 0;
		bt(0);		
		printf("Instancia #%d:\n",cnum++);
		if(!done) puts("sem solucao");
		else {
			printf("   ");
			for(i = 0; i < n; i++) printf("%s ",dname[fdir[i]]); puts("  ");
			for(i = 0; i < n; i++){
				printf("%s",dname[fdir[4*n-i-1]]);
				for(j = 0; j < n; j++) printf(" %2d",m[i][j]);
				printf(" %s\n",dname[fdir[n+i]]);
			}
			printf("   ");
			for(i = 0; i < n; i++) printf("%s ",dname[fdir[3*n-i-1]]); puts("  ");
		}
		putchar('\n');
	}
	return 0;
}
