#include <cstdio>
#include <set>
using namespace std;

int v[512];
bool seen[1000000];
int main(void){
	int T; scanf("%d", &T);
	while(T--){
		int n; scanf("%d", &n);
		for(int i = 0; i < n; ++i) scanf("%d", &v[i]);
		bool found = false;
		for(int i = 1; !found; ++i){
			found = true;
			for(int j = 0; j < i; ++j) seen[j] = 0;
			for(int j = 0; found && j < n; ++j){
				int mod = v[j] % i;
				found &= !seen[mod];
				seen[mod] = true;
			}
			if(found) printf("%d\n", i);
		}
	}
	return 0;
}

