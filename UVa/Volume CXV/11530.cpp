/////////////////////////////////
// 11530 - SMS Typing
/////////////////////////////////
#include<cstdio>
#include<cctype>
char p[128];
char line[110];
int cs,i,n,price;
int main(void){
	for(i = 0; i < 128; i++) p[i] = 0;
	p['a'] = p['d'] = p['g'] = p['j'] = p['m'] = p['p'] = p['t'] = p['w'] = p[' '] = 1;
	p['b'] = p['e'] = p['h'] = p['k'] = p['n'] = p['q'] = p['u'] = p['x'] = 2;
	p['c'] = p['f'] = p['i'] = p['l'] = p['o'] = p['r'] = p['v'] = p['y'] = 3;
	p['s'] = p['z'] = 4;
	scanf("%d",&n);
	getchar();
	cs = 0;
	while(n--){
		cs++;
		gets(line);
		for(price = i = 0; line[i]; i++) price+=p[line[i]];
		printf("Case #%d: %d\n",cs,price);
	}
	return 0;
}
	
