/////////////////////////////////
// 10714 - Ants
/////////////////////////////////
#include<cstdio>
#define MAX(a,b) (a>b?a:b)
unsigned int ant,ant_num,c,cnum,half,i,min_time,max_time,pole_size,u,v;
int main(void){
	scanf("%u",&cnum);
	while(cnum--){
		scanf("%u %u",&pole_size,&ant_num);
		half = pole_size/2;
		min_time = max_time = 0;
		for(i = 0; i != ant_num;i++){
			scanf("%u",&ant);
			if(ant <= half)
				min_time = MAX(min_time,ant),
				max_time = MAX(max_time,pole_size-ant);
			else
				min_time = MAX(min_time,pole_size-ant),
				max_time = MAX(max_time,ant);
			
		}
		
		printf("%u %u\n",min_time,max_time);
	}
	return 0;
}
