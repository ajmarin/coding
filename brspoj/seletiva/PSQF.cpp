#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <set>
#include <string>
using namespace std;
struct CAT {
	char n[50];
	int match, need;
	bool in;
	set < string > s;
} c[20];
int main(void){
	int cnt, i, j, n, newn, t, words;
	char line[1300];
	bool dbg = 0, notn, dbgGETS = 0;
	set < string > ::iterator it;
	scanf("%d\n",&t);
	while(t--){
		scanf("%d\n",&n);
		notn = 1;
		for(i = 0; i < n; i++){
			c[i].s.clear();
			c[i].match = c[i].in = 0;
			scanf("%s %d %d\n",c[i].n,&words,&c[i].need);
			for(j = 0; j < words; j++){
				scanf("%s\n",line);
				c[i].s.insert(string(line));
			}
			if(c[i].need == 0) c[i].in = 1;
		}
		while(fgets(line,1300,stdin) && line[0]!='\n'){
			int stw = 0, enw, l = strlen(line)-1, wlen;
			string str;
			line[l] = 0;
			while(true){
				for(enw = stw; isalpha(line[enw]); enw++);
				wlen = enw - stw;
				str = string(line, stw, wlen);
				stw= enw+1;
				for(i = 0; i < n; i++)
					if(!c[i].in && (it=c[i].s.find(str)) != c[i].s.end())
						c[i].in = (++c[i].match >= c[i].need),
						c[i].s.erase(it);
					
				if(stw < l){ 
					while(line[stw] && !isalpha(line[stw])) stw++;
					if(line[stw] == 0) break;
				}

				else break;
			}
		}
		for(cnt = i = 0; i < n; i++)
			if(c[i].in){
				if(cnt) putchar(',');
				printf("%s",c[i].n);
				cnt++;
			}
		
		if(!cnt) puts("SQF Problem");
		else putchar('\n');
	}
	return 0;
}

