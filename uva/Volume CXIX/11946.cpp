#include <cstdio>

char map[128];
int main(void){
	int t; scanf("%d\n", &t);
	for(unsigned c = 0; c < 128; ++c) map[c] = c;
	map['0'] = 'O'; map['1'] = 'I'; map['2'] = 'Z';
	map['3'] = 'E'; map['4'] = 'A'; map['5'] = 'S';
	map['6'] = 'G'; map['7'] = 'T'; map['8'] = 'B';
	map['9'] = 'P';
	for(char c; (c = getchar()) != EOF; putc(*(map + c), stdout));
	return 0;
}

