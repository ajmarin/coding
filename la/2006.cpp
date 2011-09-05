#include <cctype>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
using namespace std;
map< string, int > m;
char line[1048576];
int main(void){
	while(fgets(line, 1048576, stdin)){
		m.clear();
		string ans;
		int maxocc = 0;
		while(true){
			int len = strlen(line);
			line[--len] = 0;
#ifdef DBG
			printf("%s --> %d\n", line, len);
#endif
			for(int i = 0; i < len; ){
				while(i < len && !isalpha(line[i])) ++i;
				if(i >= len) break;
				string s = "";
				while(isalpha(line[i])) s += tolower(line[i++]);
#ifdef DBG
				printf("word -> %s\n", s.c_str());
#endif
				if(++m[s] > maxocc){
					maxocc = m[s];
					ans = s;
				}
			}
			fgets(line, 1048576, stdin);
			if(line[0] == '#') break;
		}
		if(maxocc == 0) break;
		printf("%4d %s\n", m[ans], ans.c_str());
	}
	return 0;
} 

