#include <cstdio>

int main(void){
	int e, f, c, T;
	int drank, empty, more;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&e,&f,&c);
		drank = 0;
		empty = f+e;
		while(empty >= c){
			more = empty/c;
			empty = empty%c;
			drank += more;
			empty += more;
		}
		printf("%d\n",drank);
	}
	return 0;
}

