#include <cstdio>
#include <cstring>

#define OUT(x) putc(x, stdout)
#define IN getc( stdin )
char orig[5096], out[5096];
char d[128], l[128], r[128], u[128];
int T, len;
void DOIT(char a, char b, char c, char d, char *x){
	strcpy(out, orig);
	bool FUKITOL = 0;
	for(int i = len-1; !FUKITOL && i > -1; --i){
		out[i] = *(x + orig[i]);
		FUKITOL |= (orig[i] == a || orig[i] == b);
	}
	if(FUKITOL) printf("%s",out);
	else printf("<none>");
}

int main(void){
	d['p'] = l['r'] = r['r'] = u['p'] = 's';
	d['q'] = l['s'] = r['s'] = u['q'] = 'r';
	d['r'] = l['p'] = r['p'] = u['r'] = 'q';
	d['s'] = l['q'] = r['q'] = u['s'] = 'p';
	scanf("%d\n",&T);
	while(T--){
		register char c, *p = orig;
		while((c = IN) != '\n') *p++ = c; *p = 0;
		len = p - orig;
		DOIT('s','r','p','q',u); OUT(' ');
		DOIT('p','q','r','s',d); OUT(' ');
		DOIT('q','r','p','s',l); OUT(' ');
		DOIT('p','s','q','r',r); OUT(10);
	}
	return 0;
}
