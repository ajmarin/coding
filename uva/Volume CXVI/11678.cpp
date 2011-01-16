#include <cstdio>
#include <cstring>

#define NN 100032
#define MM 10032

bool h1[NN], h2[NN];
int v1[MM], v2[MM];

int main(void){
	int i, A, B;
	int t1, t2;
	while(scanf("%d%d",&A,&B) && (A||B)){
		memset(h1,0,NN);
		memset(h2,0,NN);
		t1 = t2 = 0;
		for(i = 0; i < A; i++){
			scanf("%d",&v1[i]), h1[v1[i]] = 1;
			if(i && v1[i] == v1[i-1]) i--, A--;
		}
		for(i = 0; i < B; i++){
			scanf("%d",&v2[i]), h2[v2[i]] = 1;
			if(i && v2[i] == v2[i-1]) i--, B--;
		}
		for(i = 0; i < A; i++)
			if(!h2[v1[i]]) t1++;
		for(i = 0; i < B; i++)
			if(!h1[v2[i]]) t2++;
		printf("%d\n",(t2<t1 ? t2: t1));
	}
	return 0;
}
