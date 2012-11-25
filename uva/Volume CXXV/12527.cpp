#include <cstdio>

bool safe(int x){
	for(int mask = 0; x; mask |= (1 << (x % 10)), x /= 10)
		if(mask & (1 << (x % 10))) return false;
	return true;
}

int s[5001];

int main(void){
	s[0] = 1;
	for(int i = 1; i <= 5000; ++i) s[i] = s[i - 1] + safe(i);
	for(int a, b; scanf("%d %d", &a, &b) == 2; printf("%d\n", s[b] - s[a - 1]));
	return 0;
}

