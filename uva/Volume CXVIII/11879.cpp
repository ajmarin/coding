#include <cstdio>

char num[128];
int main(void){
	while(scanf("%s", num) == 1 && num[0] != '0'){
		int mod = 0;
		for(char *p = num; *p; ++p) mod = (10 * mod + *p - '0') % 17;
		printf("%d\n", !mod);
	}
	return 0;
}

