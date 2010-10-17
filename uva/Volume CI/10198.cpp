#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
char f[1024][1024];

void add(char *n, char *p){
	int c, i, l1, l2, ml;
	char *s = n, *t = p;
	for(l1 = l2 = 0; *s || *t; s++, t++){
		if(*s) ++l1; else *s = '0';
		if(*t) ++l2; else *t = '0';
	}
	ml = max(l1, l2);
	for(c = i = 0, s = n, t = p; i < ml; ++i, s++, t++){
		c += *s + *t - '0' - '0';
		*s = '0' + (c % 10);
		c /= 10;
	}
	if(c) *s++ = c + '0';
	*s = 0;
	p[l2] = 0;
}

int main(void){
	strcpy(f[0], "1");
	strcpy(f[1], "2");
	strcpy(f[2], "5");
	for(int i = 3; i < 1004; ++i){
		strcpy(f[i], f[i - 1]);
		add(f[i], f[i - 1]);
		add(f[i], f[i - 2]);
		add(f[i], f[i - 3]);
		reverse(f[i - 3], f[i - 3] + strlen(f[i - 3]));
	}

	for(int n; scanf("%d", &n) == 1; puts(f[n]));
	return 0;
}

