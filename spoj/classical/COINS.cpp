#include <cstdio>
#include <map>
std::map < unsigned, unsigned > m;
unsigned exchange(unsigned n){
	unsigned &r = m[n];
	if(r) return r;
	unsigned sum = (n/2) + (n/3) + (n/4);
	if(sum > n) return r = exchange(n/2) + exchange(n/3) + exchange(n/4);
	return r = n;
}
int main(void){
	for(int n; scanf("%d", &n) == 1; ) printf("%u\n", exchange(n));
	return 0;
}
