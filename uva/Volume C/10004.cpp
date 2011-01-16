/////////////////////////////////
// 10004 - Bicoloring
/////////////////////////////////
#include<cstdio>
#define MAX 200
bool c[MAX][MAX];
int nodes[MAX];
int i,j,a,n, A,B,colored;
bool able;
void bicolor(int a, int b){	
	if(able){
		if(nodes[a] == -1){
			nodes[a] = b;
			for(i = 0; i < n; i++)
				if(c[a][i]){c[a][i] = 0;	bicolor(i,!b);}
			
		}
		else if(nodes[a] != b) able = false;		
	}
}	
int main(){
	scanf("%d",&n);
	while(n){
		scanf("%d",&a);
		able = 1;
		for(i = 0; i < n; i++) nodes[i] = -1;
		for(i = 0; i < n; i++) for(j = 0; j < n; j++) c[i][j] = 0;
		for(i = 0; i < a; i++){
			scanf("%d %d",&A,&B);
			c[A][B] = c[B][A] = 1;
		}
		bicolor(0,1);
		if(able) printf("BICOLORABLE.\n");
		else printf("NOT BICOLORABLE.\n");	
		scanf("%d",&n);		
	}
	
}
