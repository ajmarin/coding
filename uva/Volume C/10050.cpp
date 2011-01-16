/////////////////////////////////
// 10050 - Hartals
/////////////////////////////////
#include<cstdio>
bool h[3655];
int cases,hp,hi,i,j,N,hartals;
int main(void){
	scanf("%d",&cases);
	while(cases){
		cases--;
		scanf("%d",&N);
		N++;
		scanf("%d",&hp);
		for(i = 0; i < N; h[i] = 0,i++);
		for(hartals = i = 0; i < hp; i++){
			scanf("%d",&hi);
			for(j = hi; j < N; j+=hi)
				if(!h[j] && j%7 != 6 && j%7){
					h[j] = 1;
					hartals++;
				}
		}
		printf("%d\n",hartals);
	}
}
