/////////////////////////////////
// 00383 - Shipping Routes
/////////////////////////////////
#include<cstdio>
#include<cstring>
#include<map>
#include<queue>
#include<vector>
#include<string>
#define tr(c,it) for(typeof(c.begin())it=c.begin();it!=c.end();it++)
using namespace std;
map<string, int> m;
vector< vector<int> > adj(50);
unsigned int cnum,i,M,N,P,size,total;
char buf[25],destiny[25],source[25];
void get_edge(){
	register char buf1[25],buf2[25];
	int a,b;
	scanf("%s%s",&buf1,&buf2);
	a = m[string(buf1)]; b = m[string(buf2)];
	adj[a].push_back(b);
	adj[b].push_back(a);
}
void bfs(int s, int t){
	queue< pair<int, int> > q;
	bool v[M]; memset(v,0,M);
	q.push( pair<int,int>(s,0) );
	int aux, legs;
	while(!q.empty() && q.front().first != t){
		aux = q.front().first;
		legs = q.front().second;
		q.pop();
		tr(adj[aux],it)
			if(!v[(*it)]) 
				v[(*it)] = 1, q.push( pair<int,int>((*it),legs+1) );
	}
	if(q.empty()) printf("NO SHIPMENT POSSIBLE\n");
	else printf("$%u\n",100*size*q.front().second);
}
int main(void){
	printf("SHIPPING ROUTES OUTPUT\n");
	scanf("%u",&total);
	while(total--){		
		cnum++;
		printf("\nDATA SET  %u\n\n",cnum);
		scanf("%u%u%u",&M,&N,&P);
		for(i = 0; i < M; i++)
			scanf("%s",&buf),adj[i].clear(),
			m.insert(pair<string,int>(string(buf),i));
		for(i = 0; i < N; i++) get_edge();
		for(i = 0; i < P; i++) 
			scanf("%u%s%s",&size,&source,&destiny),
			bfs(m[string(source)],m[string(destiny)]);
	}
	printf("\nEND OF OUTPUT\n");
	return 0;
}
