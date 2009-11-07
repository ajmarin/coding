#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX 100001
#define MAXY MAX<<1
struct P{
	int n, x, y, adj;
	P(int a, int b, int c): x(a),y(b),n(c) {}
	P(){}
}pt[MAX];
int nb[MAX], tree[MAXY+1], maxy;
bool ord(P a, P b){
	return ((a.x < b.x) || (a.x == b.x && a.y < b.y));
}
void fastint( register int *n ){
	register char c;
	*n = 0;
	while( ( c = getc( stdin ) )){
		switch( c ){
			case ' ': case '\n': return;
			default: (*n) *= 10; (*n) += ( c - '0' ); break;
		}
	}
}
void update(int idx ,int val){
	while (idx <= maxy){
		tree[idx] += val;
		idx += (idx & -idx);
	}
}
int read(int idx){
	int sum = 0;
	if(idx > maxy) idx = maxy;
	while(idx > 0){
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}
int main(void){
	int cnum, D, i, N, x, y;
	int back, p, front;
	scanf("%d",&cnum);
	while(cnum--){
		memset(tree,0,sizeof(tree));
		scanf("%d%d\n",&N,&D);
		maxy = 0;
		for(i = 0; i < N; i++){
			fastint(&x); fastint(&y);
			pt[i] = P(x-y+MAX,x+y+1,i);
			if(pt[i].y > maxy) maxy = pt[i].y;
		}
		std::sort(pt,pt+N,ord);
		for(back = p = front = 0; p < N; p++){
			int sup_lim = pt[p].x + D + 1;
			int inf_lim = pt[p].x - D;
			while(front < N && pt[front].x < sup_lim){
				update(pt[front].y, 1);
				front++;
			} while(back < N && pt[back].x < inf_lim){
				update(pt[back].y, -1);
				back++;
			}
			nb[pt[p].n] = read(pt[p].y+D) - read(pt[p].y-D-1) - 1;
		}
		for(i = 0; i < N; i++) printf("%d ",nb[i]);
		putchar('\n');

	}
	return 0;
}

