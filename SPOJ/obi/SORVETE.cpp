#include <cstdio>
#include <algorithm>
#define max(a,b) ((a>b)?(a):(b))
struct SORVETEIRO {
	int l, r;
	bool operator()(SORVETEIRO a, SORVETEIRO b){
		return a.l < b.l;
	}
} s[5000];
int main(void){
	for(int i, t = 1, P, S; scanf("%d%d",&P,&S) && P; t++){
		for(i = 0; i < S; i++) scanf("%d%d",&s[i].l,&s[i].r);
		std::sort(s,s+S,SORVETEIRO());
		int start = s[0].l, end = s[0].r;
		printf("Teste %d\n",t);
		for(i = 1; i < S; i++)
			if(s[i].l > end){
				printf("%d %d\n",start,end);
				start = s[i].l;
				end = s[i].r;
			} else end = max(end,s[i].r);
		printf("%d %d\n\n",start,end);
	}
	return 0;
}
