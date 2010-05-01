#include <cstdio>

int main(void){
	int R, N;
	for(int cnum = 0; (scanf("%d %d", &R, &N) && R); ){
		printf("Case %d: ", ++cnum);
		int s = (R - 1)/N;
		if(s > 26) printf("impossible\n");
		else printf("%d\n", s);
	}
	return 0;
}	
