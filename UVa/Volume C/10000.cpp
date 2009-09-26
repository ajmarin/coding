/////////////////////////////////
// 10000 - Longest Paths
/////////////////////////////////
#include<cstdio>
#include<cstring>
char d[101], max, q[101];
bool adj[101][101];
unsigned int a, b, cnum, end, head, i, n, start, t, tail;
int main(void){
	while(scanf("%u",&n) && n){		
		scanf("%u",&t); n++; cnum++; head = tail = 0;
		memset(adj,0,sizeof(adj));
		memset(d,0,sizeof(d));
		while(scanf("%u %u",&a,&b) && (a||b)) adj[a][b] = 1;
		start = t;
		q[tail++] = start;
		while(head != tail){
			t = q[head++];			
			for(i = 1; i < n; i++)
				if(adj[t][i]){
					if(d[i] < d[t]+1) d[i] = d[t]+1, q[tail++] = i;
				}
		}
		for(max = 0, i = 1; i < n; i++)
			if(d[i] > max) max = d[i], end = i;
		if(max == 0) end = start;
		printf("Case %u: The longest path from %u has length %u, finishing at %u.\n\n",cnum,start,max,end);
	}
	return 0;
}

