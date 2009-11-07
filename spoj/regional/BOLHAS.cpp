#include<cstdio>
#include<cstring>
int E, i, swaps, T;
int c[100001], v[100001];
int main(void){
	while(scanf("%d%d",&E,&T) && E){
		memset(c,0,sizeof(c));
		i = 0;
		while(i < T){
			scanf("%d",&swaps);
			v[swaps+c[swaps]++] = ++i;
			if(c[swaps+c[swaps]]) c[swaps]+= c[swaps+c[swaps]];
		}
		while(i < E){
			v[c[0]++] = ++i;
			if(c[c[0]]) c[0] += c[c[0]];
		}
		printf("%d",v[0]);
		for(i = 1; i < E; i++)
			printf(" %d",v[i]);
		putchar('\n');
	}
	return 0;
}