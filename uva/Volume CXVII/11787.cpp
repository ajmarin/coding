#include <cstdio>
int v[128];
char num[7] = {'B', 'U', 'S', 'P', 'F', 'T', 'M'}, oc[128], word[1024];
int main(void){
	int b, n, s, t; 
	bool e, inc, dec;
	scanf("%d", &t);
	b = 1;
	for(int i = 0; i < 7; ++i){
		v[num[i]] = b;
		b *= 10;
	}
	while(t--){
		for(int i = 0; i < 7; ++i) oc[num[i]] = 0;		
		e = inc = dec = 0;	
		scanf("%s", word);
		b = s = v[*word];
		oc[*word] = 1;
		for(char *p = word + 1; !e && *p; ++p){
			n = v[*p];
			inc |= n > b;
			dec |= n < b;
			s += n;
			e = (inc & dec) || (++oc[*p] > 9);			
			b = n;
		}
		if(e) puts("error");
		else printf("%d\n", s);
	}
	return 0;
}
