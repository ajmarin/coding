#include <cstdio>
#include <map>
#include <string>
using namespace std;
map < string, int > m;
char line[64];
int main(void){
	int n, t;
	for(scanf("%d", &t); t--; ){
		m.clear();
		for(scanf("%d\n", &n); n--; ){
			fgets(line, 64, stdin);
			line[32] = 0;
			++m[line];
		}
		map < string, int >::iterator it;
		for(it = m.begin(); it != m.end(); it++)
			printf("%s%d\n", it->first.c_str(), it->second);
		if(t) puts("");
	}
	return 0;
}

