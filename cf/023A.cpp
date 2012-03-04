#include <cstdio>

char s[128];
bool eq(int a, int b, int x, int y){
	for(int i = 0; a + i < b; ++i)
		if(s[a + i] != s[x + i]) return false;
	return true;
}
int main(void){
	scanf("%s", s);
	int i, j, k, l, m = 0;
	for(l = 0; s[l]; ++l);
	for(i = l; !m && i > 0; --i)
		for(j = 0; !m && j + i <= l; ++j)
			for(k = j+1; !m && k + i <= l; ++k)
				if(eq(j, j + i, k, k + i)) m = i;
	printf("%d\n", m);
	return 0;
}
