#include <cstdio>
const int MAX = 10000;
int cnt[MAX];
int main(void){
	for(int i = 0; i < MAX; ++i) cnt[i] = 0;
	for(int i = 0, z; i < 10; ++i){
		scanf("%d", &z);
		while(!(z & 1)) ++cnt[2], z >>= 1;
		for(int j = 3; z != 1 && j * j <= z; j += 2)
			while(!(z % j)) ++cnt[j], z /= j;
		if(z != 1) ++cnt[z];
	}
	int r = (cnt[2] + 1) % 10;
	for(int i = 3; i < MAX; i += 2)
		if(cnt[i]) r = (r * (cnt[i] + 1)) % 10;
	printf("%d\n", r);
	return 0;
}

