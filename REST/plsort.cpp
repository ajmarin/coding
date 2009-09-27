#include <cstdio>
#include <cstring>
#include <algorithm>
struct sinfo{
	char a[50], t[100], d[160];
	bool operator<(const sinfo b) const{
		int x = strcmp(a,b.a);
		return ((x<0) || (!x && strcmp(t,b.t)<0));
	}
} s[1000];
int main(void){
	int i = 0, j, len, l, n;
	for(i = 0; i < 1000 && gets(s[i].d); i++); 
	for(n = i, i = 0; i < n; i++){
		for(j = 0; s[i].d[j]; j++)
			if(s[i].d[j] == '/') l = j;
		len = j;
		for(j = l+1, l = 0; s[i].d[j] != '-' || s[i].d[j+1] != ' '; j++)
			s[i].a[l++] = s[i].d[j];
		s[i].a[--l] = 0;
		for(j = j+2, l = 0; j < len - 3; j++)
			s[i].t[l++] = s[i].d[j];
		s[i].t[--l] = 0;

	}
	std::sort(s,s+n);
	for(i = 0; i < n; i++) printf("%s\n",s[i].d);
	return 0;
}

