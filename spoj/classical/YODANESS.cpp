#include <cstdio>
#include <map>
#include <string>
using namespace std;
const int MAXV = 30048;
int f[MAXV];
map < string, int > m;
int read(int x){
	int sum = 0;
	for(; x; x -= (x & -x)) sum += f[x];
	return sum;
}
void update(int x){
	for(; x < MAXV; x += (x & -x)) ++f[x];
}
int main(void){
	int ans, n, t, x; char word[32];
	for(scanf("%d", &t); t--;){
		m.clear(); ans = 0;
		scanf("%d", &n);
		for(int i = n+1; --i; ){
			scanf("%s", word);
			m[word] = i;
			f[i] = 0;
		}
		for(int i = 1; i <= n; ++i){
			scanf("%s", word);
			update(x = m[word]);
			ans += read(x - 1);
		}
		printf("%d\n", ans);
	}
	return 0;
}

