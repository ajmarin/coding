#include <cstdio>

#define MAXN 20000000
#define SQMN 4473
bool p[MAXN];
int pps = 0;

struct pp {
	int a, b;
} pp[100000];

int main(void){
	p[0] = p[1] = 0;
	for(int i = 3; i < MAXN; i += 2) p[i] = 1;
	for(int i = 3; i < SQMN; i += 2)
		if(p[i]){
			if(p[i-2]){
				pp[pps].a = i - 2;
				pp[pps].b = i;
				++pps;
			}
			for(int j = i * i; j < MAXN; j += i) p[j] = 0;
		}
	for(int i = SQMN; i < MAXN; i += 2)
		if(p[i] && p[i - 2]){
			pp[pps].a = i - 2;
			pp[pps].b = i;
			if(++pps == 100000) break;
		}
	while(scanf("%d",&pps) == 1) printf("(%d, %d)\n",pp[pps-1].a,pp[pps-1].b);
	return 0;
}
							
