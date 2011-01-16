/////////////////////////////////
// 10062 - Tell me the frequencies!
/////////////////////////////////
#include<cstdio>
#include<algorithm>
struct occ {
	unsigned short n,a;
	bool operator()(occ o1, occ o2){
		if(o1.a < o2.a) return 1;
		if(o1.a == o2.a) return o1.n > o2.n;
		return 0;
	}
} o[128];
char line[1050];
unsigned short int i;
int main(void){
	bool first = 1;
	while(gets(line)){
		if(!first) putchar('\n');
		else first = 0;
		for(i = 0; i < 128; i++) o[i].n = i,o[i].a = 0;
		for(i = 0; line[i]; i++) o[line[i]].a++;
		std::sort(o,o+128,occ());
		for(i = 127; o[i].a; i--);
		for(i = i+1; i < 128; i++) printf("%u %u\n",o[i].n,o[i].a);
	}
	return 0;
}
	
