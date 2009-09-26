/////////////////////////////////
// 10684 - The jackpot
/////////////////////////////////
#include<cstdio>
int curr,k,max,n;
int main(void){
	while(scanf("%u",&n) && n){
		curr = max = 0;
		while(n--){
			scanf("%d",&k);
			curr += k;
			if(curr > max) max = curr;
			if(curr < 0) curr = 0;
		}
		if(max) printf("The maximum winning streak is %u.\n",max);
		else printf("Losing streak.\n");
	}
}

