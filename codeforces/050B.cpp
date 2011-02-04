#include <cstdio>
#include <iostream>
long long cnt[128];
int main(void){
	long long ans = 0;
	for(int i = 0; i < 128; ++i) cnt[i] = 0;
	for(char c = getc(stdin); c != EOF; c = getc(stdin)) ++cnt[c];
	for(char c = '0'; c <= '9'; ++c) ans += cnt[c]*cnt[c];
	for(char c = 'a'; c <= 'z'; ++c) ans += cnt[c]*cnt[c];
	std::cout << ans << std::endl;
	return 0;
}
	