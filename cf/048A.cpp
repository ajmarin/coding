#include <cstdio>
char a, b, c;
char play[16];
bool beat(char x, char y){	
	if(x == 'p' && y == 'r') return true;
	if(x == 'r' && y == 's') return true;
	if(x == 's' && y == 'p') return true;
	return false;
}
int main(void){
	scanf("%s", play); a = *play;
	scanf("%s", play); b = *play;
	scanf("%s", play); c = *play;
	if(beat(a,b) && beat(a,c)) puts("F");
	else if(beat(b,a) && beat(b,c)) puts("M");
	else if(beat(c,a) && beat(c,b)) puts("S");
	else puts("?");
	return 0;
}	
	