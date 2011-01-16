/////////////////////////////////
// 10137 - The Trip
/////////////////////////////////
#include<cstdio>
#include<cmath>
#define MAX(a,b) (a < b? b : a)
int i, students;
double spent_money[1000], mean,hmean, lmean,exlo,exup;
int main(void){
	while(scanf("%d",&students) && students){
		mean = exlo = exup =  0;
		for(i = 0; i < students; i++){
			scanf("%lf",&spent_money[i]);
			mean += spent_money[i];
		}
		hmean = ceil(mean/students*100)/100;
		lmean = floor(mean/students*100)/100;
		for(i = 0; i < students; i++){
			if(spent_money[i] >= hmean)exup += spent_money[i]-hmean;
			else	exlo += lmean - spent_money[i];
		}
		printf("$%.2lf\n", MAX(exup,exlo));
	}
}
