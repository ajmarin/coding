#include <cstdio>

int cnt[5];
int main(void){
	for(int n; scanf("%d", &n) == 1; ){
		cnt[0] = cnt[1] = cnt[2] = cnt[3] = cnt[4] = 0;
		for(int z; n--; ){
			scanf("%d", &z);
			++cnt[z];
		}
		int cars = cnt[4];
		int threeone = cnt[3] < cnt[1] ? cnt[3] : cnt[1];
		cnt[3] -= threeone;
		cnt[1] -= threeone;
		cars += threeone;
		cars += cnt[3];
		cars += (2 * cnt[2] + cnt[1] + 3) / 4;
		printf("%d\n", cars);
	}

	return 0;
}

