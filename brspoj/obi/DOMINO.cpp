#include <cstdio>
#include <cstring>
bool f[7][7], match[56], dbg = 0;
int cnt, m[7][8];
void bt(int i){;
	if(i == 56){ cnt++; return; }
	if(match[i]){ bt(i+1); return;}
	int x = i/8, y = i%8;
	if(y != 7 && !match[i+1] && !f[m[x][y]][m[x][y+1]]){		
		match[i] = match[i+1] =
		f[m[x][y]][m[x][y+1]] =
		f[m[x][y+1]][m[x][y]] = 1;
		bt(i+2);
		match[i] = match[i+1] =
		f[m[x][y]][m[x][y+1]] =
		f[m[x][y+1]][m[x][y]] = 0;
	}
	if(x != 6 && !match[i+8] && !f[m[x][y]][m[x+1][y]]){	   
		match[i] = match[i+8] =
		f[m[x][y]][m[x+1][y]] =
		f[m[x+1][y]][m[x][y]] = 1;
		bt(i+1);
		match[i] = match[i+8] =
		f[m[x][y]][m[x+1][y]] =
		f[m[x+1][y]][m[x][y]] = 0;
	}
}
		
int main(void){
	int i, j, n;
	scanf("%d",&n);
	memset(f,0,sizeof(f));
	memset(match,0,sizeof(match));
	for(int t = 1; n--; t++){
		for(i = 0; i < 7; i++)
			for(j = 0; j < 8; j++)
				scanf("%d",&m[i][j]);
		cnt = 0;
		bt(0);
		printf("Teste %d\n%d\n\n",t,cnt);
	}
	return 0;
}
