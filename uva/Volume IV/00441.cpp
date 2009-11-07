/////////////////////////////////
// 00441 - Lotto
/////////////////////////////////
#include<cstdio>
#include<algorithm>
unsigned int a,b,c,d,e,f,k,n;
unsigned int Z[13];
int main(void){
	for(k = 0; (scanf("%u",&n) && n); k++){
		if(k) putchar('\n');
		for(a = 0; a < n; scanf("%u",&Z[a++]));
		std::sort(Z,Z+a);
		for(a = 0; a < n-5; a++)
		for(b = a+1; b < n-4; b++)
		for(c = b+1; c < n-3; c++)
		for(d = c+1; d < n-2; d++)
		for(e = d+1; e < n-1; e++)
		for(f = e+1; f < n; f++)
			printf("%u %u %u %u %u %u\n",Z[a],Z[b],Z[c],Z[d],Z[e],Z[f]);
	}
	return 0;
}	
