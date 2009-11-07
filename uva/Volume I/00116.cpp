/////////////////////////////////
// 00116 - Unidirectional TSP
/////////////////////////////////
#include<cstdio>
#define MAXINT 2147483647
int matrix[10][100], mincost;
char goesto[10][100];
char i,j,k,line,m,n,p1,p2,p3;
int findmin(char a, char b){
	if(a == 0) p1 = 0, p2 = 1, p3 = m-1;
	else if(a == m-1) p1 = 0, p2 = m-2, p3 = m-1;
	else p1 = a-1, p2 = a, p3 = a+1;
	if(matrix[p1][b+1] <= matrix[p2][b+1] && matrix[p1][b+1] <= matrix[p3][b+1]) k = p1;
	else if(matrix[p2][b+1] <= matrix[p3][b+1]) k = p2;
	else k = p3;
	return matrix[k][b+1];
}
void traceback(char a,char b){
	if(b == n-1) printf("%d",a+1);
	else printf("%d ",a+1),traceback(goesto[a][b], b+1);
}
void analyze(){
	for(j = n-2; j != -1; j--)
		for(i = 0; i < m; i++)
			matrix[i][j] += findmin(i,j), goesto[i][j] = k;	
	mincost = MAXINT;
	for(i = 0; i < m; i++)
		if(matrix[i][0] < mincost) line = i, mincost = matrix[i][0];
	traceback(line,0);
	printf("\n%d\n",mincost);
}
int main(void){
	while(scanf("%u %u",&m,&n)==2){
		for(i = 0; i < m; i++)
			for(j = 0; j < n; j++)
				scanf("%d",&matrix[i][j]);
		for(j = 0; j < n; j++) matrix[m][j] = MAXINT;
		analyze();
		/*
		// Prints the resulting matrix
		for(i = 0; i < m; putchar('\n'),i++)
			for(j = 0; j < n; j++)
				printf("%d ",matrix[i][j]);
		// Prints the line each cell goes to
		for(i = 0; i < m; putchar('\n'),i++)
			for(j = 0; j < n; j++)
				printf("%d ",goesto[i][j]);
		putchar('\n');
		*/
	}
	return 0;
}