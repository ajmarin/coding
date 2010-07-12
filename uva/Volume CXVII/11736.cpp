#include <cstdio>
#include <map>
#include <string>

using namespace std;

const int VMAX = 200;

map < string, int > m;
int b, bits[VMAX], v, y;
unsigned long long x[VMAX];
char nome[VMAX], z[VMAX];
int b10(char *k){
	int v = 0;
	for(char *p = k; *p; ++p)
		v = (v << 1) + (*p - '0');
	return v;
}
int main(void){
	while(scanf("%d %d", &b, &v) == 2){
		m.clear();
		for(int i = 0; i < v; ++i){
			scanf("%s %d", nome, &bits[i]);
			m[string(nome)] = i + 1;
		}
		for(int i = 0; i < v; ++i){
			x[i] = 0;
			for(int j = 0; j < bits[i]; ++j){
				scanf("%s", z);
				y = b10(z);
				x[i] = (x[i] << b) + y;
			}
		}
		scanf("%d", &y);
		for(int i = 0; i < y; ++i){
			scanf("%s", nome);
			int idx = m[string(nome)];
			printf("%s=", nome);
			if(idx) printf("%llu", x[idx - 1]);
			putc(10, stdout);
		}		
	}
	return 0;
}
