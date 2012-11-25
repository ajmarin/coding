#include <cstdio>

const int NN = 100048;

int v[NN];
int neg[NN], zero[NN];

int read(int *tree, int idx){
	int sum = 0;
	for(int i = idx; i; i -= (i & -i)) sum += tree[i];
	return sum;
}

void update(int *tree, int idx, int val){
	for(int i = idx; i < NN; i += (i & -i)) tree[i] += val;
}

int main(void){
	for(int n, q; scanf("%d %d", &n, &q) == 2; ){
		for(int i = 0; i <= n; ++i) neg[i] = zero[i] = 0;
		for(int i = 1; i <= n; ++i){
			scanf("%d", v + i);
			if(v[i] < 0) update(neg, i, 1);
			else if(!v[i]) update(zero, i, 1);
		}
		char op;
		int a, b;
		for(int i = 0; i < q; ++i){
			scanf(" %c %d %d", &op, &a, &b);
			if(op == 'C'){
				if(v[a] < 0) update(neg, a, -1);
				else if(!v[a]) update(zero, a, -1);
				v[a] = b;
				if(v[a] < 0) update(neg, a, 1);
				else if(!v[a]) update(zero, a, 1);
			} else {
				int nn, zz;
				zz = read(zero, b) - read(zero, a - 1);
				nn = read(neg, b) - read(neg, a - 1);
				putc(zz ? '0' : nn & 1 ? '-' : '+', stdout);
			}
		}
		puts("");
	}
	return 0;
}

