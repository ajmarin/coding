#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 100048, ROOT = 317;

char s[512];
bool p[MAX];

int get_num(int l, int r){
	int z = 0;
	for(int i = l; i < r; ++i) z = (z * 10) + s[i] - '0';
	return z;
}

int main(void){
	p[0] = p[1] = false;
	p[2] = true;
	for(int i = 3; i < MAX; ++i) p[i] = i & 1;
	for(int i = 3; i < ROOT; i += 2) if(p[i])
		for(int j = i * i, k = i << 1; j < MAX; j += k)
			p[j] = false;
	
	while(scanf("%s", s) == 1 && strcmp(s, "0")){
		int ans = -1, L = strlen(s), z;
		for(int i = 7; --i; ){
			for(int j = 0; j + i <= L; ++j){
				z = get_num(j, j + i);
				if(z <= 100000 && p[z]) ans = max(ans, z);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

