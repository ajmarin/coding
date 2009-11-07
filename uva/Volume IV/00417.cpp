#include <cstdio>
#include <cstring>
#define L(k,i) for((k) = (i); (k) <= 'z'; (k)++)
struct W{
	char w[6], l;
	int operator<(const W x){
		char ldiff = l - x.l;
		return (ldiff? ldiff: strcmp(w,x.w));
	}
} dict[83682], word;
int bin_search(){
	int cval, c, u, v;
	for(u = 1, v = 83682; u < v; ){
		c = (u+v)>>1;
		cval = word<dict[c];
		if(cval){
			if(cval < 0) v = c;
			else u = c+1;
		} else return c;
	}
}
bool valid(){
	char *k = &word.w[0];
	while(*(++k)) if(*k <= *(k-1)) return 0;
	word.l = k - &word.w[0];
	return 1;
}
int main(void){
	char a, b, c, d, e;
	int n = 1;
	L(a,'a') {
		dict[n].w[0] = a, dict[n].w[1] = 0, dict[n++].l = 1;
	}
	L(a,'a') L(b,a+1){
		dict[n].w[0] = a; dict[n].w[1] = b;
		dict[n].w[2] = 0; dict[n++].l = 2;
	}
	L(a,'a') L(b,a+1) L(c,b+1){
		dict[n].w[0] = a; dict[n].w[1] = b;
		dict[n].w[2] = c; dict[n].w[3] = 0; dict[n++].l = 3;
	}
	L(a,'a') L(b,a+1) L(c,b+1) L(d,c+1){
		dict[n].w[0] = a; dict[n].w[1] = b;
		dict[n].w[2] = c; dict[n].w[3] = d;
		dict[n].w[4] = 0; dict[n++].l = 4;
	}
	L(a,'a') L(b,a+1) L(c,b+1) L(d,c+1) L(e,d+1){
		dict[n].w[0] = a; dict[n].w[1] = b;
		dict[n].w[2] = c; dict[n].w[3] = d;
		dict[n].w[4] = e; dict[n].w[5] = 0; dict[n++].l = 5;
	}
	while(gets(word.w))
		printf("%d\n",(valid()? bin_search(): 0));
	return 0;
}
