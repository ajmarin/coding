#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>

using namespace std;

#define N 5163
int s[128] = {0};
struct name {
	char s[20];
	bool operator<(const name x) const{
		return strcmp(s, x.s) < 0;
	}
} n[N];
int main(void){
	clock_t ini = clock();
	int ans = 0;
	for(int i = 'A'; i <= 'Z'; ++i) s[i] = 1 + (i - 'A');
	for(int i = 0; i < N; ++i) scanf("%s", n[i].s);
	sort(n, n + N);
	for(int i = 0; i < N; ++i){
		int score = 0;
		for(int j = 0; n[i].s[j]; ++j) score += s[n[i].s[j]];
		ans = ans + score * (i + 1);
	}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}

