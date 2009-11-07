/////////////////////////////////
// 00117 - The Postal Worker Rings Once
/////////////////////////////////
#include<cstring>
#include<cstdio>
#define MM 200
#define INF (1<<28)
const char *de = "deadend";
char road[50000];
int node_num[200];
int adj[200][200];
int deg[200];
int n;
int dijkstra(int s, int t) {
	int in[MM], d[MM];
	int i, u;
	for(i = 0; i < n; i++)
		d[i] = adj[s][i], in[i] = 0;
	while(!in[t]) {
		int best = INF;
		for(i = 0; i < n; i++)
			if(!in[i] && best > d[i])
				best = d[u = i];
		if(best == INF) break;
		in[u] = 1;

		for(i = 0; i < n; i++)
			if(!in[i] && adj[u][i] != -1 && d[i] > d[u] + adj[u][i])
				d[i] = d[u] + adj[u][i];
	}
	return d[t];
}
int main(void){
	int answer, i, j, len;
	while(gets(road)){
		/* clear everything */
		memset(node_num,-1,sizeof(node_num));
		for(i = 0; i < 200; i++)
			for(j = 0; j < 200; j++)
				adj[i][j] = INF;
		memset(deg,0,sizeof(deg));
		n = answer = 0;
		/* INPUT */
		while(strcmp(road,de)){
			len = strlen(road);
			if(node_num[road[0]] != -1) i = node_num[road[0]];
			else i = node_num[road[0]] = n++;//, printf("%c mapped to %d\n",road[0],i);
			if(node_num[road[len-1]] != -1) j = node_num[road[len-1]];
			else j = node_num[road[len-1]] = n++;//, printf("%c mapped to %d\n",road[len-1],j);
			adj[i][j] = adj[j][i] = len;
			deg[i]++; deg[j]++;
			answer += len;
			gets(road);
		}
		/* Check if graph has odd degree nodes (SOURCE) */
		int s , t;
		for(s = t = i = 0; i < n; i++)
			if(s == 0 && deg[i]&1)  s = i;
			else if(deg[i]&1) { t = i; break; }
		/* OUTPUT */
		if(s) printf("%d\n",answer + dijkstra(s,t));
		else printf("%d\n",answer);
	}
	return 0;
}
