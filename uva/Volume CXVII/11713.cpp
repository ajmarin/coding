#include <cstdio>

const char *o[2] = {"No", "Yes"};
char a[32], b[32];
int na, nb;

bool vowel[128];
int main(void){
	int t;
	for(int i = 0; i < 128; ++i) vowel[i] = 0;
	vowel['a'] = vowel['e'] = vowel['i'] = vowel['o'] = vowel['u'] = 1;
	scanf("%d", &t);
	while(t--){
		scanf("%s%n", a, &na); scanf("%s%n", b, &nb);
		bool mutation = na == nb;
		for(char *p = a, *q = b; *p && mutation; ++p, ++q)
			mutation &= *p == *q || (vowel[*p] && vowel[*q]);
		puts(o[mutation]);
	}
	return 0;
}

