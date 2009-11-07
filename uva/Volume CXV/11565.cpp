/////////////////////////////////
// 11565 - Simple Equations
/////////////////////////////////
#include<cstdio>
#include<cstdlib>
int A,B,C,cases;
int k,x,y,z,v1,v2,v3;
void solve(){	
	for(x = -B; x < B; x++){
		if(!x || B%x) continue;
		k = B/abs(x);
		for(y = x+1; y < k; y++){
			if(!y || B%y) continue;
			v1 = (A-x-y);v1 *= v1;
			v2 = B/x/y; v2*=v2;
			v3 = C-x*x-y*y;
			if(v1 == v2 && v2 == v3){ printf("%d %d %d\n",x,y,A-x-y); return;}
		}
	}
	printf("No solution.\n");
}
int main(void){
	scanf("%u\n",&cases);
	while(cases--){
		scanf("%d %d %d\n",&A,&B,&C);
		solve();		
	}
	return 0;
}
