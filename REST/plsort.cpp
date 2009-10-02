#include <cstdio>
#include <cstring>
#include <algorithm>
struct sinfo{
	char a[50], t[100], d[200];
	bool operator<(const sinfo b) const{
		int x = strcmp(a,b.a);
		return ((x<0) || (!x && strcmp(t,b.t)<0));
	}
} s[1000];
int main(void){
	int i = 0, j, len, n;
	register char *p, *q;
	for(i = 0; i < 1000 && fgets(s[i].d, 200, stdin); i++); 
	for(n = i, i = 0; i < n; i++){
		for(p = s[i].d; *p; p++)
			if(*p == '/') break;
		if(*p != '/') p = s[i].d;
		else p++;
		for(q = s[i].a; *p; q++){
			*q = *p++;
			if(*q == '-' && *p == ' ') break;
		}
		*--q = 0;
		for(++p, q = s[i].t; *p; ) *q++ = *p++;
		*(q-5) = 0;

	}
	std::sort(s,s+n);
	for(i = 0; i < n; i++) printf("%s",s[i].d);
	return 0;
}

