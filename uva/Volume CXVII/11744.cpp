#include <cstdio>
char d[2][32];
int main(void){
	int t; scanf("%d", &t);
	while(t--){
		scanf("%s %s", d[0], d[1]);
		printf("%s %s\n", d[0], d[1]);
		for(int i = 0; ; ++i){
			bool beq0 = 1, overflow = 0;
			for(int j = 0; j < 31; ++j){
				char ai = d[0][j] - '0', bi = d[1][j] - '0';
				d[0][j] = (ai != bi) + '0';
				beq0 &= ~(ai && bi);
				if(j) d[1][j - 1] = (ai && bi) + '0';
				else overflow = (ai && bi);
			}
			d[1][30] = '0';
			if(overflow){
				printf("%s overflow\n", d[0]);
				break;
			}
			printf("%s %s\n", d[0], d[1]);
			if(beq0) break;
		}
		if(t) putc(10, stdout);
	}
	return 0;
}
