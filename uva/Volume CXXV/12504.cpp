#include <cstdio>
#include <cstring>
#include <map>
#include <string>
using namespace std;

map < string, string > s, t;
char key[128], value[128];

void populate(map< string, string >& z, char *c){
	c[strlen(c) - 1] = 0;
	z.clear();
	for(char *p = strtok(c, ","); p != NULL; p = strtok(NULL, ",")){
		sscanf(p, "%[^:]:%s", key, value);
		z[key] = value;
	}
}

int main(void){
	scanf("%*d");
	for(char text[128]; scanf(" {%s", text) == 1; ){
		populate(s, text);
		scanf(" {%s", text);
		populate(t, text);
		int added = 0;
		map< string, string >::iterator it, f;
		for(it = t.begin(); it != t.end(); ++it){
			f = s.find(it -> first);
			if(f == s.end())
				printf("%c%s", added++ ? ',' : '+', it->first.c_str());
		}
		if(added) puts("");
		int removed = 0;
		for(it = s.begin(); it != s.end(); ++it){
			f = t.find(it -> first);
			if(f == t.end())
				printf("%c%s", removed++ ? ',' : '-', it->first.c_str());
		}
		if(removed) puts("");
		int changed = 0;
		for(it = s.begin(); it != s.end(); ++it){
			f = t.find(it -> first);
			if(f != t.end() && it -> second != f -> second)
				printf("%c%s", changed++ ? ',' : '*', it->first.c_str());
		}
		if(changed) puts("");
		if(!(added | removed | changed)) puts("No changes");
		puts("");
	}
	return 0;
}

