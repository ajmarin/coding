/////////////////////////////////
// 10305 - Ordering Tasks
/////////////////////////////////
#include<cstdio>
#include<cstring>
#include<vector>
#define tr(c,it) for(typeof(c.begin())it=c.begin();it!=c.end();it++)
unsigned int d, dd[101], i, n, s, shown, tasks, top_ord[101];
bool v[101];
int main(void){
	while(scanf("%u%u",&tasks,&n) && tasks){
		std::vector< std::vector<int> > adj(tasks+1);
		shown = 0;
		memset(dd,0,sizeof(dd));
		memset(v,0,tasks+1);
		for(i = 0; i < n; i++)
			scanf("%u%u",&s,&d), adj[s].push_back(d), dd[d]++;
		while(shown != tasks)
			for(i = 1; i <= tasks; i++)
				if(!v[i] && dd[i]==0){
					v[i] = 1;
					top_ord[shown++] = i;
					tr(adj[i],it) dd[(*it)]--;
				}
		printf("%u",top_ord[0]);
		for(i = 1; i < shown; i++) printf(" %u",top_ord[i]);
		putchar('\n');
	}
	return 0;
}

