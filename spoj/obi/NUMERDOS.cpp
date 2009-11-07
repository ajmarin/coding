#include<cstdio>
#include<cstring>
#include<map>
#include<queue>
#include<string>
#include<vector>
#define tr(c,it) for(typeof(c.begin())it=c.begin();it!=c.end();it++)
using namespace std;
map<string, int> m;
vector< vector<int> > adj(128);
int i, j, n;
string erdos("P. Erdos"), name;
struct Author {
	char abbr, ln[30];
	int e;
	bool operator()(Author a1, Author a2){
		int cmp = strcmp(a1.ln,a2.ln);
		return (cmp < 0 || cmp == 0 && a1.abbr < a2.abbr);
	}
} A[128];

void read_paper(){
	register char ppr[2000];
	int ath[10];
	gets(ppr);
	char FL[3], * name = strtok(ppr,",. ");
	FL[1] = '.'; FL[2] = '\0';
	string nnn;
	for(int i = 0; name != NULL; i++){
		FL[0] = *name;		
		name = strtok(NULL, ",. ");
		nnn = string(FL)+" "+string(name);
		if(m.find(nnn) == m.end()){
			m[nnn] = ++n;
			A[n].abbr = FL[0];
			strcpy(A[n].ln, name);
		}
		ath[i] = m[nnn];
		for(j = 0; j < i; j++) 
			adj[ath[i]].push_back(ath[j]),
			adj[ath[j]].push_back(ath[i]);		
		name = strtok(NULL, ",. ");
	}
}
void bfs(){
	queue< pair<int, int> > q;
	bool v[n]; memset(v,0,n);
	int aux, e;
	q.push( make_pair(0,0) );
	v[0] = 1;
	while(!q.empty()){
		aux = q.front().first;	e = q.front().second;
		q.pop(); A[aux].e = e;
		tr(adj[aux],it)
			if(!v[(*it)]) v[(*it)] = 1, q.push(make_pair((*it),e+1));
	}
}
int main(void){
	for(int i, papers, t = 1; scanf("%d\n",&papers) && papers; t++){
		m.clear(); adj[0].clear();
		m[erdos] = 0;
		for(n = i = 0; i < papers; i++)	read_paper();
		++n; bfs();
		printf("Teste %d\n",t);
		std::sort(&A[1],&A[n],Author());
		for(i = 1; i < n; i++){			
			if(A[i].e) printf("%c. %s: %d\n",A[i].abbr,A[i].ln,A[i].e);
			else printf("%c. %s: infinito\n",A[i].abbr,A[i].ln);
			A[i].e = 0;
			adj[i].clear();
		}
		putchar('\n');
	}
	return 0;
}
