#include <cstdio>
#include <algorithm>
int a, d, i, pa[11],pd[11];
bool offside;
int main(void){
	while(scanf("%d%d",&a,&d) && (a || d)){
		for(i = 0; i < a; i++)
			scanf("%d",&pa[i]);		
		for(i = 0; i < d; i++)
			scanf("%d",&pd[i]);
		std::sort(pa,pa+a);
		std::sort(pd,pd+d);
		for(offside = i = 0; !offside && i < a; i++)
			if(pa[i] < pd[1]) offside = 1;
		if(offside) putchar('Y');
		else putchar('N');
		putchar('\n');
	}
	return 0;
}
