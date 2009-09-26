#include <cstdio>
int main(void){
	for(int n, max; scanf("%d",&n) && n; ){
		max = -1;
		for(int i = 0, x, sum = 0; i < n; i++){
			scanf("%d",&x);
			sum += x;
			if(sum > max) max = sum;
			else if(sum < 0) sum = 0;
		}
		if(max > 0) printf("The maximum winning streak is %d.\n",max);
		else printf("Losing streak.\n");
	}
	return 0;
}

