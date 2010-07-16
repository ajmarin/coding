#include <cstdio>
#include <cctype>
const char *r[2] = {"NO", "YES"};
char s[1024];
int c, l, ok;
int main(void){
	while(scanf("%s", s) == 1){
		c = 0; ok = 1;
		for(l = 0; s[l]; ++l);
		while(ok && l--){
			if(s[l] == 'N')	ok &= c > 0;
			else if(islower(s[l])) c++;
			else ok &= c-- > 1;
		}
		ok &= c == 1;
		puts(r[ok]);
	}
	return 0;
}
