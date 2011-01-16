/////////////////////////////////
// 10041 - Vito's Family
/////////////////////////////////
#include<cstdio>
#include<cstdlib>
#include<algorithm>
int cases, i, median, relatives, street[499], sum;
int main(void){
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&relatives);
		for(i = 0; i < relatives; scanf("%d",&street[i]),i++);
		std::sort(street,street+relatives);		
		median = street[relatives/2];
		for(sum = 0,i = 0; i < relatives; i++)
			sum += abs(median-street[i]);
		printf("%d\n",sum);
	}
	return 0;
}
