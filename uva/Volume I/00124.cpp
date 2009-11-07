#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

char let[25], line[1024], ord[25];
map < char, int > m;
vector < int > adj[25];
int TC, deg[25];
bool used[25];

void bt(int k){
	if(k == TC){
		ord[k] = 0;
		puts(ord);
		return;
	}
	vector < int > :: iterator it;
	for(int i = 0; i < TC; ++i)
		if(!used[i] && !deg[i]){
			used[i] = 1;
			ord[k] = let[i];
			for(it = adj[i].begin(); it != adj[i].end(); it++)
				--deg[*it];
			bt(k+1);
			for(it = adj[i].begin(); it != adj[i].end(); it++)
				++deg[*it];
			used[i] = 0;
		}
}

int main(void){
	int a, b, len;
	char *p;
	bool f = 1;
	while(fgets(line, 1024, stdin)){
		if(!f) putc(10, stdout);
		f = 0;
		m.clear();
		len = strlen(line);
		line[--len] = TC = 0;
		sort(line, line + len);
		for(p = line; *p == ' '; ++p);
		while(*p){
			let[TC] = *p;
			m[*p] = TC;
			adj[TC].clear();
			deg[TC] = 0;
			used[TC++] = 0;
			*p++;
		}
		fgets(line, 1024, stdin);
		p = line;
		while(*p && !isalpha(*p)) p++;
		while(*p){
			a = m[*p++];
			while(*p && !isalpha(*p)) p++;
			b = m[*p++];
			deg[b]++;
			adj[a].push_back(b);
			while(*p && !isalpha(*p)) p++;
		}
		bt(0);
	}
	return 0;
}

