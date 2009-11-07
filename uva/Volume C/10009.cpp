/////////////////////////////////
// 10009 - All Roads Lead Where?
/////////////////////////////////
#include<cstdio>
#include<cstring>
#include<list>
#include<map>
#include<queue>
#define tr(c, it) for(typeof(c.begin()) it = c.begin(); it!=c.end();it++)
using namespace std;
map<char, int> m;
vector<char> rname;
vector< vector<int> > adj(100);
unsigned int c, i, n, roads, queries;
char s[1000], t[1000];
void check(char k){
	if(m.count(k)==0) rname.push_back(k),m.insert(pair<char,int>(k,n++));
}
void getroad(){
	register char a, b, bufa[1024], bufb[1024];
	scanf("%s %s",&bufa,&bufb);
	a = bufa[0]; b = bufb[0];
	check(a); check(b);
	adj[m[a]].push_back(m[b]);
	adj[m[b]].push_back(m[a]);
}
void traverse(int idx, char p[]){
	if(p[idx]) traverse(m[p[idx]],p);
	putchar(rname[idx]);
}
void bfs(char s, char t){
	queue< int > q;
	bool v[n]; char prev[n]; int idx;
	memset(v,0,n);
	memset(prev,0,sizeof(char)*n);
	q.push( m[s] );
	prev[m[s]] = 0; v[m[s]] = 1;
	while(rname[q.front()] != t){
		idx = q.front();
		q.pop();
		tr(adj[idx],it)
			if(!v[(*it)])
				prev[(*it)] = rname[idx],
				v[(*it)] = 1,
				q.push( (*it) );
	}
	traverse(q.front(),prev);
	putc('\n',stdout);
}
int main(void){
	scanf("%u",&c);
	while(c--){
		for(i = 0; i < n; i++) adj[i].clear();
		m.clear();
		rname.clear();
		scanf("%u %u",&roads,&queries);
		for(n = i = 0; i < roads; i++) getroad();
		for(i = 0; i < queries; i++)
			scanf("%s %s",&s,&t),
			bfs(s[0],t[0]);
		if(c) putc('\n',stdout);
	}
	return 0;
}

