/////////////////////////////////
// 00531 - Compromise
/////////////////////////////////
#include<cstdio>
#include<cstring>
char w_first[101][32],w_sec[101][32],m,n,i,j;
char lcs[101][101], mov[101][101];
bool first;
void printLCS(char i, char j){
	if(i == 0 || j == 0) return;
	if(mov[i][j]){
		if(mov[i][j]&1) printLCS(i,j-1);
		else printLCS(i-1,j);
	} else {
		printLCS(i-1,j-1);
		if(!first) printf(" %s",w_first[i-1]);
		else first = 0, printf("%s",w_first[i-1]);
	}
}
int main(void){
	while(scanf("%s",&w_first[0])!=EOF){
		m = 1; n = 0;
		while(scanf("%s",&w_first[m++]) && w_first[m-1][0] != '#');
		while(scanf("%s",&w_sec[n++]) && w_sec[n-1][0] != '#');
		for(i = 0; i < m; i++) lcs[i][0] = 0;
		for(j = 0; j < n; j++) lcs[0][j] = 0;
		for(i = 1; i < m; i++){
			for(j = 1; j < n; j++)
				if(strcmp(w_first[i-1],w_sec[j-1])==0)
					lcs[i][j] = lcs[i-1][j-1]+1, mov[i][j] = 0;
				else if(lcs[i][j-1]>lcs[i-1][j])
					lcs[i][j] = lcs[i][j-1], mov[i][j] = 1;
				else
					lcs[i][j] = lcs[i-1][j], mov[i][j] = 2;
		}
		first = 1;
		printLCS(m-1,n-1);
		putchar('\n');
	}
	
	return 0;
}

