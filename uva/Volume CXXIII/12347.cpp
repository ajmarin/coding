#include <cstdio>
const int NN = 10048;

struct node {
	node *l, *r;
	node *p;
	int smv, v;
} n[NN];

void post_order(node *n){
	if(n -> l != NULL) post_order(n -> l);
	if(n -> r != NULL) post_order(n -> r);
	printf("%d\n", n -> v);
}
int main(void){
	node *c = NULL;
	for(int i = 0, z; scanf("%d", &z) == 1; ++i){
		n[i].v = z;
		n[i].l = n[i].r = n[i].p = NULL;
		n[i].smv = 1 << 20;
		if(c == NULL) c = n + i;
		else if(z < c -> v){
			n[i].p = c;
			n[i].smv = c ->v - 1;
			c = c -> l = n + i;
		} else {
			while(c -> smv < z) c = c -> p;
			n[i].p = c;
			n[i].smv = c -> smv;
			c = c -> r = n + i;
		}
	}
	post_order(n);
	return 0;
}

