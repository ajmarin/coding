#include <cstdio>

#define MAX(a,b) ((a)>(b)?(a):(b))

const int NN = 100032;
struct node { 
	int h, l, p, r;
	bool ISL, ISR;
} t[NN];

node *root;
int dfs(node *x){
	int h1, h2;
	h1 = h2 = 0;
	if(x->l != -1) h1 = dfs(&t[x->l]);
	if(x->r != -1) h2 = dfs(&t[x->r]);
	h1 = MAX(h1,h2);
	x->h = 1+h1;
	return x->h;
}
int main(void){
	int N;
	while(scanf("%d",&N) && N){
		for(int i = 0; i < N; i++){
			t[i].l = t[i].r = t[i].p = -1;
			t[i].ISL = t[i].ISR = 0;
		}
		for(int a, b, i = 0; i < N; i++){
			scanf("%d %d",&a, &b);
			--a, --b;
			t[i].l = a;
			t[i].r = b;
			if(a != -1) t[a].p = i, t[a].ISL = 1;
			if(b != -1) t[b].p = i, t[b].ISR = 1;
		}
		for(int i = 0; i < N; i++)
			if(t[i].p == -1) root = &(t[i]);
		dfs(root);
		for(int i = 0; i < N; i++){
			int ARG1, ARG2, ARG3;
			node *x = &t[i];
			ARG1 = ARG2 = ARG3 = 0;
			if(x == root) printf("%d\n",root->h);
			else {
				if(x->ISL){
					if(x->l != -1) ARG1 = t[x->l].h;
					if(x->r != -1) ARG2 = t[x->r].h;
					if(t[x->p].r != -1) ARG3 = t[t[x->p].r].h;
				} else {
					if(x->r != -1) ARG1 = t[x->r].h;
					if(x->l != -1) ARG2 = t[x->l].h;
					if(t[x->p].l != -1) ARG3 = t[t[x->p].l].h;
				}
				//printf("ARG = (%d,%d,%d)\n",ARG1,ARG2,ARG3);
				printf("%d\n", root->h - t[x->p].h + 1 + MAX(ARG1, 1 + MAX(ARG2,ARG3)));
			}

		}
	}
	return 0;
}

