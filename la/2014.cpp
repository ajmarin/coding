#include <cstdio>
#include <cstdlib>
#include <cstring>

int abs(int a){ return a < 0 ? -a : a; }
int main(void){
	int cookie;
	for(bool first(true); scanf("%d", &cookie) == 1 && cookie != 5280; first = false){
		int at, ppos = 0;
		if(!first) puts("");
		while(scanf("%*[^-0-9\n]%d", &at) == 1){
			printf("Moving from %d to %d: ", ppos, at);
			if(at == cookie) puts("found it!");
			else if(abs(at - cookie) < abs(ppos - cookie)) puts("warmer.");
			else if(abs(at - cookie) > abs(ppos - cookie)) puts("colder.");
			else puts("same.");
			ppos = at;
		}
	}
	return 0;
}

