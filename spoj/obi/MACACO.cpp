#include <cstdio>
int n;
struct P { int x, y;} PTL, PBR, ITL, IBR;
int main(void){
	for(int t = 1; scanf("%d",&n) && n ; t++){
		ITL.x = IBR.y = -10000;
		ITL.y = IBR.x = 10000;
		while(n--){
			scanf("%d%d%d%d",&PTL.x,&PTL.y,&PBR.x,&PBR.y);				
			if(PTL.x > ITL.x) ITL.x = PTL.x;
			if(PTL.y < ITL.y) ITL.y = PTL.y;
			if(PBR.x < IBR.x) IBR.x = PBR.x;
			if(PBR.y > IBR.y) IBR.y = PBR.y;
		}
		printf("Teste %d\n",t);
		if(ITL.x > IBR.x || ITL.y < IBR.y) puts("nenhum\n");
		else printf("%d %d %d %d\n\n",ITL.x,ITL.y,IBR.x,IBR.y);
	}
	return 0;
}
