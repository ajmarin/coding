/////////////////////////////////
// 11498 - Division of Nlogonia
/////////////////////////////////
#include<cstdio>
int k,cx,cy,x,y;
char c[3];
int main(void){
	while(scanf("%d",&k)){
		if(k==0) break;
		scanf("%d %d",&cx,&cy);
		for(int i = 0; i < k; i++){
			scanf("%d %d",&x,&y);
			if(x == cx || y == cy) printf("divisa\n");
			else{
				c[0] = (y > cy? 'N':'S');
				c[1] = (x > cx? 'E':'O');
				printf("%s\n",c);
			}
		}
	}
	return 0;
}
