/////////////////////////////////
// 10222 - Decode the Mad man
/////////////////////////////////
#include<cstdio>
char subs[128],line[5000];
int i;
int main(void){
	for(i = 0; i < 128; i++) subs[i] = i;
	subs['e']='q';subs['r']='w';subs['t']='e';subs['y']='r';
	subs['u']='t';subs['i']='y';subs['o']='u';subs['p']='i';
	subs['[']='o';subs[']']='p';subs['\\']='[';subs['2']='`';
	subs['3']='1';subs['4']='2';subs['5']='3';subs['6']='4';
	subs['7']='5';subs['8']='6';subs['9']='7';subs['0']='8';
	subs['-']='9';subs['=']='0';subs['=']='0';subs['d']='a';
	subs['f']='s';subs['g']='d';subs['h']='f';subs['j']='g';
	subs['k']='h'; subs['l']='j';subs[';']='k';subs['\'']='l';
	subs['\\']=';';subs['c']='z';subs['v']='x';subs['b']='c';
	subs['n']='v';subs['m']='b';subs[',']='n';subs['.']='m';subs['/']=',';
	while(gets(line)){
		for(i = 0; line[i]!='\0'; i++) (line[i] > 64 && line[i] < 91? putchar(subs[line[i]+32]):putchar(subs[line[i]]));
		putchar('\n');
	}
	
	return 0;
}
