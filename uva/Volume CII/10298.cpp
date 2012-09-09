#include <cstdio>
#include <cstring>

bool hp(char *s, int L, int x){
	if(L % x) return false;
	int z = L / x;
	for(int i = 0; i < z; ++i) for(int j = i + z; j < L; j += z) if(s[i] != s[j]) return false;
	return true;
}

int find(char *s, int L){
	if(hp(s, L, 2)) return 2 * find(s, L / 2);
	if(hp(s, L, 3)) return 3 * find(s, L / 3);
	int i1, i2;
	for(int i = 6; ; i += 6){
		i1 = i - 1; i2 = i + 1;
		if(hp(s, L, i1)) return (i1) * find(s, L / i1);
		if(hp(s, L, i2)) return (i2) * find(s, L / i2);
		if(i2 * i2 >= L) break;
	}
	return 1;
}
int main(void){
	for(char s[1048576]; scanf("%s", s) == 1 && *s != '.'; printf("%d\n", find(s, strlen(s))));
	return 0;
}

