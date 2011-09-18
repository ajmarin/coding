
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int N, R, ts[3];
struct tower {
	int x, y, p;
	int team;
	vector < int > ck;
	inline int sqr(int x){ return (x*x);}
	int d2(tower kk){ return sqr(x - kk.x) + sqr(y - kk.y);}
	tower(int _x=0, int _y=0):x(_x),y(_y){}
	tower operator-(tower t2){ return tower(x-t2.x,y-t2.y);}
	int operator*(tower t2){ return (x*t2.y)-(y*t2.x);}
	bool operator<(const tower x) const{
		return ts[team] < ts[x.team];
	}
}t[312];
bool ccw(tower A, tower B, tower C){
	return ((C - A) * (B - A) < 0);
}

/* {{{ Hopcroft-Karp */
#define tr(vec) for(typeof(vec.begin())it = vec.begin(); it != vec.end(); it++)
#define NN 312
//#define DEBUG
int d[NN], p[NN], q[NN];

bool BFS(int n, int m){
	bool f = 0;
	int i, h = 0, tail = 0;
	memset(d,0,(n+m)*4);
	for(i = 0; i < n; i++) if(p[i] == -1) q[tail++] = i;
	while(h < tail){
		int x = q[h++];
		vector < int > :: iterator it = t[x].ck.begin();
		while(it != t[x].ck.end()){
			if(!d[*it]){
				d[*it] = d[x] + 1;
				if(p[*it] == -1) f = 1;
				else d[p[*it]] = d[*it]+1, q[tail++] = p[*it];
			}
			it++;
		}
	}
	return f;
}
bool DFS(int x){
	vector < int > :: iterator it = t[x].ck.begin();
	while(it != t[x].ck.end()){
		if(d[(*it)] == d[x]+1){
			d[*it] = 0;
			if(p[*it] == -1 || DFS(p[*it]))
				return p[x] = *it, p[*it] = x, true;
		}
		it++;
	}
	return false;
}
int hopcroft_karp(int n, int m){
	int i, mm = 0;
	memset(p,-1,(n+m)*4);
	while(BFS(n, m))
		for(i = 0; i < n; i++)
			mm += (p[i] == -1 && DFS(i));
	return mm;
}
/* }}} */
int main(void){
	int a, b, c2;
	ts[2] = 1500;
	for(int cnum = 0; scanf("%d",&N) && N; ){
		printf("Case %d: ",++cnum);
		ts[0] = ts[1] = 0;
		for(int i = 0; i < N; ++i){
			scanf("%d%d%d",&t[i].x,&t[i].y,&t[i].p);
			t[i].ck.clear();
		}
		scanf("%d%d%d",&a,&b,&R), --a, --b;
		R*=R;
		t[a].team = t[b].team = c2 = 2;
		for(int i = 0; i < N; ++i){
			if(i == a || i == b) continue;
			if(t[i].p == 0) t[i].team = 2, c2++;
			else if(ccw(t[a],t[b],t[i])){
				ts[0]++;
				t[i].team = 0;
			} else{
				ts[1]++;
				t[i].team = 1;
			}
		}
		sort(t, t + N);
		N -= c2;
		int AA, BB;
		if(ts[0] < ts[1]) AA = ts[0], BB = ts[1];
		else AA = ts[1], BB = ts[0];
		for(int i = 0; i < AA; ++i)
			if(t[i].p != 0)
				for(int j = AA; j < N; ++j)
					if(t[i].p > t[j].p && t[i].d2(t[j]) <= R){
						t[i].ck.push_back(j);
					}
		printf("%d\n",hopcroft_karp(AA,BB));

	}
	return 0;
}
