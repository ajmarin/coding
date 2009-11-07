/////////////////////////////////
// 00344 - Roman Digititis
/////////////////////////////////
#include<cstdio>
#include<cstring>
unsigned char n,i[100],v[100],x[100],l[100],c[100];
void comp(void){
	unsigned char d2 = n%10,d1 = n-d2;
	i[n] = i[d2];
	v[n] = v[d2];
	x[n] = x[d2]+x[d1];
	l[n] = l[d1];
	c[n] = c[d1];
}
int main(void){
	memset(i,0,sizeof(i));
	memset(x,0,sizeof(x));
	memset(l,0,sizeof(l));
	memset(c,0,sizeof(c));
	i[1] = 1; x[10] = 1;
	i[2] = 2; x[20] = 2;
	i[3] = 3; x[30] = 3;
	i[4] = v[4] = 1; x[40] = 1; l[40] = 1;
	v[5] = 1; l[50] = 1;
	i[6] = v[6] = x[60] = l[60] = 1;
	i[7] = 2; v[7] = 1; l[70] = 1; x[70] = 2;
	i[8] = 3; v[8] = 1; l[80] = 1; x[80] = 3;
	i[9] = 1; x[9] = 1; x[90] = 1; c[90] = 1;
	for(n = 11; n < 100; n++){
		if(n%10) comp();
	}
	for(n = 2; n < 100; n++){
		i[n] += i[n-1];
		v[n] += v[n-1];
		x[n] += x[n-1];
		l[n] += l[n-1];
		c[n] += c[n-1];
	}
	while(scanf("%u",&n) && n) printf("%u: %u i, %u v, %u x, %u l, %u c\n",n,i[n],v[n],x[n],l[n],c[n]);
}
	
