#include <cstdio>
#include <vector>
using namespace std;

int s[32];
int main(void){
	for(int n, sn = 0, x; scanf("%d %d", &n, &x) == 2; ){
		vector<int> alive(n);
		int cnt = n, pos;
		for(int i = 0; i < n; ++i) alive[i] = i+1;
		for(int i = 0, z; i < 20; ++i){
			scanf("%d", &z);
			pos = z - 1;
			while(cnt > x && pos < cnt){
				alive.erase(alive.begin() + pos);
				pos += z - 1;
				cnt--;
			}
		}
		printf("Selection #%d\n", ++sn);
		for(int i = 0; i < cnt; ++i) printf("%d%c", alive[i], i == cnt - 1 ? 10 : 32);
		puts("");
	}
	return 0;
}

