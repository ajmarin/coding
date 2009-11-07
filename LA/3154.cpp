#include <cstdio>
char map[127];
char seq[19] = {'1','2','3','4','5','6','7','8','9',
				'T','J','Q','K','1','2','3','4','5','6'};
int ww[3];
int getv(char value, char suit){
	return 13*map[suit] + map[value];
}
bool dbg = 0;
int main(void){
	int i, n, shift;
	char base, v, s, suit;
	map['H'] = 1; map['C'] = 2; map['D'] = 3; map['S'] = 4;
	for(i = '1'; i <= '9'; i++) map[i] = i-'0';
	map['T'] = 10; map['J'] = 11; map['Q'] = 12; map['K'] = 13;
	scanf("%d\n",&n);
	while(n--){
		scanf("%c%c",&base,&suit);
		for(i = 0; i < 3; i++){
			scanf(" %c%c",&v,&s);
			ww[i] = getv(v,s);
		}
		getchar();
		if(ww[0] < ww[1]){
			if(ww[1] < ww[2]) shift = 1;
			else if(ww[2] > ww[0]) shift = 2;
			else shift = 4;
		} else {
			if(ww[0] < ww[2]) shift = 3;
			else if(ww[1] < ww[2]) shift = 5;
			else shift = 6;
		}
		printf("%c%c\n",seq[map[base]+shift-1],suit);
	}
	return 0;
}

