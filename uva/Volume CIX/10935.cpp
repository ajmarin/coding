#include <cstdio>

struct card {
	int n;
	card *next;
} c[52];
card *top, *bottom;
int main(void){
	for(int n; scanf("%d", &n) == 1 && n; ){
		for(int i = 0; i < n; ++i){
			c[i].n = i + 1;
			c[i].next = c + i + 1;
		}
		c[n-1].next = NULL;
		top = c;
		bottom = c + n - 1;
		printf("Discarded cards:");
		for(bool first = true; top != bottom; first = false){
			if(!first) putc(',', stdout);
			printf(" %d", top -> n);			
			top = top -> next;
			bottom -> next = top;
			top = top -> next;
			bottom = bottom -> next;
		}
		printf("\nRemaining card: %d\n", top -> n);
	}
	return 0;
}

