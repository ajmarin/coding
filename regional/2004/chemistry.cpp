#include <cstdio>
#include <map>
#include <string>

using namespace std;

map<string, int> m;
int x[10000], count, n;
char str1[16], str2[16], str3[16];
string a, b, c;

int main(void) {
	while(scanf("%d", &n)) {
		if(n == 0) break;
		
		m.clear();
		count = 0;
		
		for(int i = 0; i < n; i++) {
			scanf("%s + %s -> %s", &str1, &str2, &str3);
			a = str1; b = str2; c = str3;
			if(m.count(a) == 0) {
				m[a] = count;
				x[count] = 0;
				count++;
			}
			if(m.count(b) == 0) {
				m[b] = count;
				x[count] = 0;
				count++;
			}
			m[c] = count;
			x[count] = max(min(x[m[a]], x[m[b]]) + 1, max(x[m[a]], x[m[b]]));
			count++;
		}
		
		printf("%s requires %d containers\n", str3, x[count-1]);
	}

	return 0;
}
