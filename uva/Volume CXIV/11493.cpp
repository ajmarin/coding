/////////////////////////////////
// 11493 - The Club Ballroom
/////////////////////////////////
#include<cstdio>
#define MAX(a,b) (a<b?b:a)
#define oo 1<<30
int width,height,plank_width, n_planks, max_plank_length,current,count[2][10001],currIdx,full,planks_used,test_planks,i,needed;
void tryit(int a,int b,bool ean){
	currIdx = b-1;
	full = test_planks = 0;
	needed = (a*100)/plank_width;
	while(count[ean][b] && full != needed){
		count[ean][b]--;
		test_planks++;
		full++;
	}
	while(full != needed){
		while(currIdx && (!count[ean][currIdx] || !count[ean][b-currIdx])) currIdx--;
		if(currIdx == 0) break;
		if(currIdx == b-currIdx && count[ean][currIdx] < 2) {currIdx--;continue;}
		test_planks+=2;
		count[ean][currIdx]--;count[ean][b-currIdx]--;
		full++;
	}
	if(full == needed && test_planks < planks_used) planks_used = test_planks;
}
int main(void){
	while(scanf("%d %d",&width,&height) && width){
		max_plank_length = MAX(width,height)+1;
		planks_used = oo;
		for(i = 0; i < max_plank_length; i++) count[0][i] = count[1][i] = 0;
		scanf("%d%d",&plank_width,&n_planks);
		for(i = 0; i < n_planks; i++){
			scanf("%d",&current);
			count[0][current] = count[1][current] = count[0][current]+1;
		}
		if((100*width)%plank_width == 0)	tryit(width,height,0);			
		if((100*height)%plank_width == 0) tryit(height,width,1);
		if(planks_used!=oo) printf("%d\n",planks_used);
		else printf("impossivel\n");		
	}
}
