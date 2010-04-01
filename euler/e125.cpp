#include <cmath>
#include <cstdio>
#include <ctime>
#include <set>

using namespace std;

#define SUM_LIM 100000000
#define LIM 10000
unsigned int ans, sq[LIM];
set < int > s;
bool palindrome(int k){
	int s[12], h, t = 0;
	while(k){
		s[t++] = k % 10;
		k /= 10;
	}
	h = t >> 1;
	for(int i = 0; i < h; ++i) if(s[i] != s[t - i - 1]) return 0;
	return 1;
}
void r(int depth, int sum){
	if(sum > SUM_LIM) return;
	if(palindrome(sum) && s.find(sum) == s.end()) ans += sum, s.insert(sum);
	if(depth < LIM) r(depth + 1, sum + sq[depth]);
}

int main(void){
	clock_t ini = clock();
	for(int i = 1; i < LIM; ++i) sq[i - 1] = i * i;
	ans = 0;
	for(int i = 0; i < LIM; ++i) r(i + 2, sq[i] + sq[i + 1]);
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %u\n", ans);
	return 0;
}

