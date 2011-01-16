#include <cstdio>
#include <cstring>
#include <algorithm>
struct team{
	char name[25];
	int p;
};
bool cmp(team a, team b){
	return ((a.p > b.p) || (a.p == b.p && strcmp(a.name,b.name) < 0));
}
team t[100];
int main(void){
	int i, n, inst = 1;
	while(scanf("%d",&n)==1){
		for(i = 0; i < n; i++)
			scanf("%s %d",&t[i].name,&t[i].p);
		std::sort(t,t+n,cmp);
		printf("Instancia %d\n%s\n\n",inst++,t[n-1].name);
	}
	return 0;
}
