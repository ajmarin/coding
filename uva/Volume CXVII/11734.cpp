#include <cstdio>

char k[32], l[32];
int main(void){
	int t;
	char *p, *q;
	scanf("%d\n", &t);
	for(int cnum = 0; cnum < t; ){
		fgets(l, 32, stdin);
		fgets(k, 32, stdin);
		for(p = k, q = l; *p && *q; ++p, ++q){
			while(*p == ' ') ++p;
			while(*q == ' ') ++q;
			if(!*p || !*q) break;
			if(*p != *q) break;
		}
		if(*p != *q) 
			printf("Case %d: Wrong Answer\n", ++cnum);
		else if(p - k != q - l)
			printf("Case %d: Output Format Error\n", ++cnum);
		else printf("Case %d: Yes\n", ++cnum);
	}
	return 0;
}

