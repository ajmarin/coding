#include <cstdio>
#include <map>
#include <string>

using namespace std;

#define IN getc( stdin )

map < string , string > m;

char w1[128], w2[128];
int main(void){
	m.clear();
	register char c;
	while((c = IN) != '\n'){
		register char *p = w1;
		while(c != 32){
			*p++ = c;
			c = IN;
		}
		*p = 0;	p = w2; c = IN;
		while(c != 10){
			*p++ = c;
			c = IN;
		}
		*p = 0;
		m[string(w2)] = string(w1);
	}
	while(scanf("%s", &w1) == 1){
		map < string, string >:: iterator it = m.find(string(w1));
		if(it != m.end()) puts((*it).second.c_str());
		else puts("eh");
	}
	return 0;
}

