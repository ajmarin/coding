/////////////////////////////////
// 11364 - Parking
/////////////////////////////////
#include<cstdio>
#include<algorithm>
unsigned int cases,i,store_pos[20],stores;
int main(void){
	scanf("%d",&cases);
	while(cases--){
		scanf("%u\n",&stores);
		for(i = 0; i < stores; i++) scanf("%u ",&store_pos[i]);
		std::sort(store_pos,store_pos+stores);		
		printf("%u\n",(store_pos[stores-1]-store_pos[0])*2);
	}
	return 0;
}
		
