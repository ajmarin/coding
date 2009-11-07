#include <cstdio>
#define _m_(a,b) ((a>b)?(a):(b))
int a, c[101], i, max, v;
int main(void){
	for(int t = 1; scanf("%d%d",&a,&v) && v; t++){
		for(i = 0; i < a; i++) c[i] = 0;
		for(max = i = 0; i < v; i++){
			int _, __;
			scanf("%d %d",&_,&__), ++c[--_], ++c[--__];
			max = _m_(max,_m_(c[_],c[__]));
		}		
		printf("Teste %d\n",t);
		for(i = 0; i < a; i++) if(max == c[i]) printf("%d ",i+1);
		puts("\n");
	}
	return 0;
}
