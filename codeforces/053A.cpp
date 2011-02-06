#include <cstdio>
#include <string>
using namespace std;
#define SZ(x) ((int)(x.size()))
int main(void){
	string ans = "", page, prefix;
	char w[1024];
	int n; scanf("%s %d", w, &n);
	prefix = w;
	for(int i = 0; i < n; ++i){
		scanf("%s", w);
		page = w;
		if(SZ(page) >= SZ(prefix) && prefix == page.substr(0, SZ(prefix)))
		if(ans == "" || page < ans) ans = page;
	}
	if(SZ(ans)) printf("%s\n", ans.c_str());
	else printf("%s\n", prefix.c_str());
	return 0;
}
