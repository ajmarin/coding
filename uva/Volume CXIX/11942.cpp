#include <cstdio>

int main(void){
	int t; scanf("%d", &t);
	puts("Lumberjacks:");
	for(int c, p; t--; ){
		scanf("%d", &p);
		bool asc = true, desc = true;
		for(int i = 1; i < 10; ++i){
			scanf("%d", &c);
			asc &= c > p;
			desc &= c < p;
			p = c;
		}
		puts(asc || desc ? "Ordered" : "Unordered");
	}
	return 0;
}

