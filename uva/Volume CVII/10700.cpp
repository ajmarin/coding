#include <cctype>
#include <cstdio>
char line[4096];
int main(void){
	int t; scanf("%d\n", &t);
	long long maxv, minv, n, nb, r;
	while(fgets(line, 4096, stdin)){
		n = 1; r = nb = 0;
		for(char *p = line; *p; ++p){
			if(isdigit(*p)) nb = nb * 10 + *p - '0';
			else {
				if(*p == '+' || *p == '\n') r += n * nb, n = 1;
				else if(*p == '*') n *= nb;
				nb = 0;
			}
		}
		minv = r;
		r = 1; n = nb = 0;
		for(char *p = line; *p; ++p){
			if(isdigit(*p)) nb = nb * 10 + *p - '0';
			else {
				if(*p == '*' || *p == '\n') r *= (n + nb), n = 0;
				else if(*p == '+') n += nb;
				nb = 0;
			}
		}
		maxv = r;
		printf("The maximum and minimum are %lld and %lld.\n", maxv, minv);
	}
	return 0;
}

