#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define IN getc( stdin )
#define OUT(x) putc(x, stdout)

char map[128];

bool lit[30];
int adj[30][30], deg[30];

int main(void){
	register char c;
	int k, TM;
	char m, t;
	for(char c = 'A'; c <= 'Z'; ++c) map[c] = c - 'A';
	while((c = IN) != '#'){
		ungetc(c, stdin);
		for(char i = 0; i < 30; ++i) deg[i] = lit[i] = 0;
		while(c != '.'){
			char o = map[IN];
			IN; c = IN;
			while(isalpha(c))
				adj[o][deg[o]++] = map[c], c = IN;
		}
		while(!isalpha(c = IN)); m = map[c];
		while(!isalpha(c = IN)); t = map[c];
		scanf("%d\n",&k);
		TM = 0;
		while(1){
			char mp = m;
			for(c = 0; c < deg[m]; ++c)
				if(!lit[adj[m][c]] && adj[m][c] ^ t) break;
			if(c == deg[m]){ OUT('/'), OUT(m + 'A'), OUT(10); break; }
			m = adj[m][c];
			t = mp;
			if(!(++TM % k)) lit[t] = 1, OUT(t + 'A'), OUT(' ');
		}
	}
}

