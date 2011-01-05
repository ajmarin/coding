#include <cstdio>

char c[128], m[128], name[32];
int main(void){
	for(char x = 'A'; x <= 'Z'; ++x) m[x] = -1;
	m['B'] = m['P'] = m['F'] = m['V'] = '1';
	m['C'] = m['S'] = m['K'] = m['G'] = m['J'] = m['Q'] = m['X'] = m['Z'] = '2';
	m['D'] = m['T'] = '3';
	m['L'] = '4';
	m['M'] = m['N'] = '5';
	m['R'] = '6';
	puts("         NAME                     SOUNDEX CODE");
	while(scanf("%s", name) == 1){
		c[0] = name[0];
		char *p, cnt;
		for(p = name + 1, cnt = 1; *p && cnt < 4; p++)
			if(m[*p] != -1 && m[*p] != m[*(p - 1)]) c[cnt++] = m[*p];
		while(cnt < 4) c[cnt++] = '0';
		printf("         %-24s %s\n", name, c);
	}
	puts("                   END OF OUTPUT");
	return 0;
}

