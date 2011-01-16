#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <vector>
#define INF 1<<25
using namespace std;
map < string, int > m;
struct NODE {
	vector < int > adj;
	vector < int > w;
	vector < int > next;
	vector < char > ccon;
	bool has[27];
} nodes[4000];
int len, n;
char l1[64], l2[64], word[64];
bool dbg = 0;
void clear(int k){
	nodes[k].adj.clear();
	nodes[k].w.clear();
	nodes[k].next.clear();
	nodes[k].ccon.clear();
	memset(nodes[k].has,0,27);
}
int check(string x){
	map < string , int > :: iterator it;
	if((it=m.find(x)) == m.end()){
		m[x] = n;
		clear(n);
		return n++;
	}
	return (*it).second;
}
void add_edge(int x, int y){
	nodes[x].adj.push_back(y);
	nodes[x].w.push_back(len);
	nodes[x].ccon.push_back(word[0]-'a');
	nodes[x].has[word[0]-'a'] = 1;
}
void check(int *x){;
	if(nodes[(*x)].has[word[0]-'a']){
		clear(n);
		nodes[(*x)].next.push_back(n);
		nodes[(*x)].adj.push_back(n);
		nodes[(*x)].w.push_back(0);
		nodes[(*x)].ccon.push_back(-1);
		nodes[n].adj.push_back((*x));
		nodes[n].w.push_back(0);
		nodes[n].ccon.push_back(-1);
		(*x) = n++;
	} 
}

/* Heap Binario {{{ */
#define MAX_ELEM 1<<12

#define pai(i) (((i)-1)/2)
#define esq(i) (2*(i)+1)
#define dir(i) (2*(i)+2)

struct heapitem {
	int u, d;
	heapitem() { u = d = 0; }
	heapitem(int no, int dis) { u = no, d = dis; }
	bool operator>(const heapitem &i) const { return d < i.d; }
} h[MAX_ELEM];			/* heap (de maximo) */
int hn;					/* numero de elementos */

void sobe(int i) {
	if(i > 0 && h[i] > h[pai(i)]) { /* MUDEI! */
		heapitem t = h[pai(i)];
		h[pai(i)] = h[i];
		h[i] = t;
		sobe(pai(i));
	}
}

void desce(int i) {
	int filho;

	if(dir(i) < hn && h[dir(i)] > h[esq(i)])
		filho = dir(i);
	else
		filho = esq(i);

	if(filho < hn && h[filho] > h[i]) {
		heapitem t = h[filho];
		h[filho] = h[i];
		h[i] = t;
		desce(filho);
	}
}

heapitem pop() {
	heapitem r = h[0];
	h[0] = h[--hn];
	desce(0);
	return r;
}

void push(heapitem v) {
	h[hn] = v;
	sobe(hn++);
}
/* }}} */

int dijkstra(int s, int t) {
	if(dbg) printf("De %d quero ir ate %d\n",s,t);
	int in[n], d[n];
	char r[n];
	int i, u;
	for(i = 0; i < n; i++)
		d[i] = INF, in[i] = 0, r[i] = -1;
	vector< int >:: iterator ADJ, W;
	vector< char >::iterator CC;
	NODE C = nodes[s];
	ADJ = C.adj.begin();
	W = C.w.begin();
	hn = 0; /* limpa heap */
	CC = C.ccon.begin();
	for(;ADJ != C.adj.end(); ADJ++,W++,CC++) {
		d[(*ADJ)] = (*W), r[(*ADJ)] = (*CC);
		push(heapitem(*ADJ, *W));
	}
	d[s] = 0;
	push(heapitem(s, 0));
	while(!in[t]) {
		if(hn == 0) break;
		heapitem hi = pop();
		int best = hi.d;
		u = hi.u;
		if(best == INF) break;

		in[u] = 1;
		C = nodes[u];
		ADJ = C.adj.begin();
		CC = C.ccon.begin();
		W = C.w.begin();
		for(; ADJ != C.adj.end(); ADJ++, W++,CC++)
			if(!in[(*ADJ)] && r[u] != (*CC) && d[(*ADJ)] > d[u] + (*W)) {
				d[(*ADJ)] = d[u] + (*W),
				r[(*ADJ)] = (((*CC)==-1)? (r[u]):(*CC));
				push(heapitem(*ADJ, d[*ADJ]));
			}
			
	}
	return ((in[t])?(d[t]):-1);
}
int main(void){
	int a, b, E, i;
	char O[64],D[64];
	string SL1, SL2; 
	while(scanf("%d",&E) && E){
		scanf("%s %s",O,D);
		m.clear();
		for(n = i = 0; i < E; i++){
			scanf("%s %s %s\n",l1,l2,word);
			SL1 = string(l1);
			SL2 = string(l2);
			len = strlen(word);
			a = check(SL1); b = check(SL2);
			check(&a); check(&b);
			add_edge(a,b);
			add_edge(b,a);
		}
		if(m.find(string(O))==m.end()|| m.find(string(D))==m.end()){
			printf("impossivel\n"); continue;
		}
		int dist = dijkstra(m[string(O)],m[string(D)]);
		if(dist > 0) {printf("%d\n",dist);continue;}
		dist = dijkstra(m[string(D)],m[string(O)]);
		if(dist > 0) printf("%d\n",dist);		
		else printf("impossivel\n");
			
	}
	return 0;
}

