#include <cstdio>

int code_node;

struct node {
	int next[32];
	int has_next;
} n[1048576];

int push(int nn, int x){
	node &z = n[nn];
	if(!(z.has_next & (1 << x))){
		z.has_next |= (1 << x);
		z.next[x] = code_node;
		n[code_node++].has_next = 0;
	}
	return z.next[x];
}

char word[100048][128];
int main(void){
	for(int at, z; scanf("%d", &z) == 1; ){
		code_node = 1;
		n[0].has_next = 0;
		for(int i = 0; i < z; ++i){
			at = 0;
			scanf("%s", word[i]);
			for(int j = 0; word[i][j]; ++j)
				at = push(at, word[i][j] - 'a');
			push(at, '{' - 'a');
		}
		int ans = z;
		for(int i = 0, x; i < z; ++i){
			at = n[0].next[word[i][0] - 'a'];
			for(int j = 1; word[i][j]; ++j){
				x = n[at].has_next;
				ans += !!(x & (x - 1));
				at = n[at].next[word[i][j] - 'a'];
			}
		}
		printf("%.2lf\n", ans / double(z));
	}
	return 0;
}

