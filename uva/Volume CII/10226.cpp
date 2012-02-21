#include <cstdio>
#include <map>
#include <string>
using namespace std;

map< string, int > m;
char name[32];
int main(void){
	for(int t(0); t || scanf("%d\n", &t) == 1; --t){
		int total_trees = 0;
		m.clear();
		while(gets(name) && *name){
			++total_trees;
			++m[name];
		}
		for(map<string, int>::iterator it = m.begin(); it != m.end(); ++it)
			printf("%s %.4lf\n", it->first.c_str(), (100.0 * it -> second) / total_trees);
		if(t > 1) puts("");
	}
	return 0;
}

