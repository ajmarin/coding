#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct num { char n[1024]; } z[64];

char temp1[2048], temp2[2048];

bool swap_worth(const char *x, const char *y){
	int lx = strlen(x), ly = strlen(y);
	strcpy(temp1, x);
	strcpy(temp1 + lx, y);
	strcpy(temp2, y);
	strcpy(temp2 + ly, x);
	return strcmp(temp2, temp1) > 0;
}
	
int main(void){
	for(int n; scanf("%d", &n) == 1 && n; ){
		for(int i = 0; i < n; ++i) scanf("%s", z[i].n);
		for(int i = 0; i < n; ++i)
			for(int j = 1; j < n; ++j)
				if(swap_worth(z[j - 1].n, z[j].n))
					swap(z[j - 1], z[j]);
		for(int i = 0; i < n; ++i)
			for(int j = 0; z[i].n[j]; ++j)
				putc(z[i].n[j], stdout);
		puts("");
	}
	return 0;
}
