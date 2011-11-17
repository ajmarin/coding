#include <cstdio>

const int NN = 1 << 16;
int d[NN], mask[128], q[NN];
int head, tail;

void push(int x, int l){
	d[x] = l;
	q[tail++] = x;
}

int main(void){
	for(int m, n; scanf("%d %d", &m, &n) == 2 && m; ){
		for(int i = 0; i < NN; ++i) d[i] = 0;
		for(int i = 0, t, z; i < m; ++i){
			mask[i] = 0;
			scanf("%d", &t);
			while(t--){
				scanf("%d", &z);
				mask[i] |= 1 << (z - 1);
			}
		}
		head = tail = 0;
		push(0, 0);
		while(head != tail){
			int at = q[head++], level = d[at];
			int new_mask;
			for(int i = 0; i < m; ++i){
				new_mask = at | mask[i];
				if(!d[new_mask]) push(new_mask, level + 1);
			}
		}
		for(int i = 0, t, z; i < n; ++i){
			mask[m] = 0;
			scanf("%d", &t);
			while(t--){
				scanf("%d", &z);
				mask[m] |= 1 << (z - 1);
			}
			printf("%d%c", d[mask[m]], i == n - 1 ? 10 : 32);
		}
	}
	return 0;
}

