/////////////////////////////////
// 00336 - A Node Too Far
/////////////////////////////////
#include<cstdio>
#include<cstring>
#include<map>
#include<queue>
#define tr(c, it) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)
using namespace std;
unsigned int a,b,cnum,cttl,current,i,ida,idb,n,s,t,ttl,visited;
vector< vector<int> > adj(50);
bool v[50];
map <int, int> m;
queue< pair<int, int> >q;
void bfs(){
	while(!q.empty()){
		current = q.front().first;
		cttl = q.front().second;
		q.pop();
		if(cttl)
			tr(adj[current], it)
				if(!v[(*it)]){					
					v[(*it)] = 1;
					visited++;
					q.push( pair<int, int>((*it),cttl-1));
				}
	}
	printf("Case %u: %u nodes not reachable from node %u with TTL = %u.\n",
		++cnum,n-visited,s,ttl);
}		
int main(void){
	while(scanf("%u",&t) && t){
		for(i = 0; i < n; i++)adj[i].clear();
		m.clear();
		for(n = i = 0; i < t; i++){
			scanf("%u %u",&a,&b);
			if(m.count(a) == 0) m.insert( pair<int, int>(a,n++));
			if(m.count(b) == 0) m.insert( pair<int, int>(b,n++));
			ida = m[a]; idb = m[b];
			adj[ida].push_back(idb);
			adj[idb].push_back(ida);
		}
		while(scanf("%u %u",&s,&ttl) && s)
				q.push( pair<int, int>(m[s],ttl)),
				memset(v,0,n),
				v[m[s]] = visited = 1,
				bfs();		
	}
}
