#include <cstdio>
#include <cstdlib>

char n[1024], *p, what[16];
int base, r, v;
int main(void){
	while(scanf("%[a-z]-", what) && what[0] != 'e'){
		scanf("%d", &base);
		if(what[0] == 't'){
			bool end = 0;
			scanf("%d\n", &v);
			for(p = n; v; p++){
				int t = v;
				if(t < 0) t -= base * t;
				*p = t % base;
				if(*p > 0){
					if((p - n) & 1) v += base - *p, *p = base - *p + '0';
					else v -= *p, *p = *p + '0';
				} else *p = '0';
				v /= base;
			}
			if(p == n) putc('0', stdout);
			while(p-- != n) putc(*p, stdout);
			putc(10, stdout);
		} else {
			scanf("%s\n", n);
			v = 0, r = 1;
			for(p = n; *p; ++p);
			for( ; p-- != n; r *= -base) v += (*p - '0') * r;
			printf("%d\n", v);
		}
	}
	return 0;
}

