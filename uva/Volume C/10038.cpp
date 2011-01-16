/////////////////////////////////
// 10038 - Jolly Jumpers
/////////////////////////////////
#include<cstdio>
#include<cstdlib>
int main(void){
	bool used[3000];
	int nums[3000];
	int n,i,val;
	bool jolly;
	while(scanf("%d",&n)!=EOF){		
		for(i = 0; i < n; scanf("%d",&nums[i]),used[i] = false,i++);
		jolly = true;
		for(i = 1; i < n && jolly; i++){
			val = abs(nums[i]-nums[i-1]);
			if(val < 1 || val > n-1 || used[val]) jolly = false;
			else used[val] = true;
		}
		if(jolly) printf("Jolly\n");
		else printf("Not jolly\n");
	}
	return 0;
}
