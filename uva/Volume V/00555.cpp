#include <algorithm>
#include <cstdio>

using namespace std;

const char *cval = "23456789TJQKA";
const char *csuit = "CDSH";
const char *dir = "SWNE";

struct card {
	char suit, value;
	int __suit, __value;
	card() {}
	card(char s, char v): suit(s), value(v) { get_suit(); get_value(); }
	int get_value(){
		for(int i = 0; cval[i]; ++i) if(cval[i] == value){
			__value = i;
			break;
		}
	}
	int get_suit(){
		for(int i = 0; csuit[i]; ++i) if(csuit[i] == suit){
			__suit = i;
			break;
		}
	}
	bool operator<(const card &c) const {
		return __suit < c.__suit || (__suit == c.__suit && __value < c.__value);
	}
}c[4][13];

int main(void){
	char dealer[8], cards[128];
	while(scanf("%s", dealer) == 1 && dealer[0] != '#'){
		int cp = -1, i, j;
		for(i = 0; dir[i] != dealer[0]; ++i);
		cp = (i + 1) % 4;
		scanf("%s", cards);
		scanf("%s", cards + 52);
		for(i = j = 0; i < 52; ++i){
			c[(cp + i) % 4][i / 4] = card(cards[j], cards[j+1]);
			//printf("Card %c%c to %c\n", cards[j], cards[j + 1], dir[(cp + i) % 4]);
			j += 2;
		}
		for(i = 0; i < 4; ++i){
			sort(c[i], c[i] + 13);
			printf("%c:", dir[i]);
			for(j = 0; j < 13; ++j)
				printf(" %c%c", c[i][j].suit, c[i][j].value);
			puts("");
		}
	}
	return 0;
}