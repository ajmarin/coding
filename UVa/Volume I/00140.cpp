/////////////////////////////////
// 00140 - Bandwidth
/////////////////////////////////
#include<cstdio>
#include<cstdlib>
#include<cstring>
int a[8], app[30], pos[8];
int mindist, n;
char ans[9], L[8], in[1000], possans[9], src, dest;
bool adj[8][8], used[8], show = 0;
void bt(int k){
	int c[8], cnum = 0, i, j, jump = 0;
	if(k == n){
		int maxdist = 0, temp;
		for(int x = 0; x < n; x++){
			for(int y = 0; y < n; y++){
				if(!adj[x][y]) continue;
				temp = abs(pos[x] - pos[y]);
				if(temp > maxdist) maxdist = temp;				
			}
			if(maxdist > mindist) return;			
		}		
		if(maxdist <= mindist){				
			for(int x = 0; x < n; x++)
				possans[x] = L[a[x]];
			if(maxdist < mindist || strcmp(possans,ans) < 0) strcpy(ans,possans);
			mindist = maxdist;
		}
		return;
	}
	for(i = 0; i < n; i++)
		if(!used[i]) c[cnum++] = i;
	for(i = 0; i < cnum; i++){
		a[k] = c[i];
		pos[c[i]] = k;
		for(jump = j = 0; j < k; j++)
			if(adj[a[j]][a[k]] && (k - j) > mindist) {jump = 1; break;}
		if(jump) continue;
		used[c[i]] = 1;
		bt(k+1);
		used[c[i]] = 0;
	}
}
int main(void){
	int a, b, i, j, l;
	ans[8] = possans[8] = 0;
	while(gets(in) && in[0] != '#'){
		mindist = 9;
		for(i = 0; i < 8; i++)
			for(j = 0; j < 8; j++)
				adj[i][j] = 0;
		for(i = 0; i < 27; i++) app[i] = -1;
		for(n = i = 0; i < 8; i++) used[i] = 0, ans[i] = 'Z';
		l = strlen(in);
		for(i = 0; i < l; i++){
			src = in[i]-'A';
			i += 2;			
			if(app[src] == -1) app[src] = n, L[n++] = src+'A';
			a = app[src];
			while(in[i] && in[i] != ';'){
				dest = in[i++]-'A';
				if(app[dest] == -1) app[dest] = n, L[n++] = dest+'A';
				b = app[dest];
				adj[a][b] = 1;
				adj[b][a] = 1;
			}
		}
		bt(0);
		for(i = 0; i < n; i++) putchar(ans[i]), putchar(' ');
		printf("-> %d\n",mindist);
		
	}
	return 0;
}