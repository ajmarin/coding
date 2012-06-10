#include <cstdio>
#include <set>
using namespace std;

multiset < int > s;
int y[1 << 15], z[1 << 15];
int main(void){
	int t; scanf("%d", &t);
	while(t--){
		int a, b; scanf("%d %d", &a, &b);
		for(int i = 0; i < a; ++i) scanf("%d", y + i);
		for(int i = 0; i < b; ++i) scanf("%d", z + i);
		multiset < int > s;
		s.insert(y[0]);
		multiset < int >::iterator it = s.end();
		for(int i = 1, j = 0; j < b; ++j){
			while(i < z[j]){
				s.insert(y[i]);
				if(it != s.end() && y[i] < *it) --it;
				++i;
			}
			if(it == s.end()) printf("%d\n", *(it = s.begin()));
			else printf("%d\n", *++it);
		}
		if(t) puts("");
	}
	return 0;
}

