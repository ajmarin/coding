#include <cstdio>
#include <queue>
using namespace std;
int p[4];
struct SLIDE {
	int x1, x2, y1, y2;
	SLIDE(): x1(p[0]),x2(p[1]),y1(p[2]),y2(p[3]) {}
} s[32];
int a[32][2], d[32][2], N; /* adj+deg slides(0) nums(1) */
char m[32];
bool married[32][2];
queue < pair < int, bool > > q;
/* is point (x,y) inside slide? */
bool pis(int x, int y, SLIDE ss){
	return(x > ss.x1 && x < ss.x2 && y > ss.y1 && y < ss.y2);
}
int log2(int x){
  int pos = 0;
  if (x >= 1<<16) { x >>= 16; pos += 16; }
  if (x >= 1<< 8) { x >>=  8; pos +=  8; }
  if (x >= 1<< 4) { x >>=  4; pos +=  4; }
  if (x >= 1<< 2) { x >>=  2; pos +=  2; }
  if (x >= 1<< 1) {           pos +=  1; }
  return pos;
}
void remove(int k, bool num){
	a[k][num] = d[k][num] = 0;
	int MASK = 1<<k; bool op = !num;
	for(int b = 0; b < N; b++)
		if(a[b][op] & MASK) a[b][op] -= MASK, d[b][op]--;
}
int main(void){
	int i, j, x, y;
	bool progress, p1, p2, success;
	for(int hn = 1; scanf("%d",&N) && N; hn++){
		for(i = 0; i < N; i++){
			a[i][0] = a[i][1] = d[i][0] = d[i][1] = 
				married[i][0] = married[i][1] = 0;
			m[i] = -1;
			scanf("%d%d%d%d",&p[0],&p[1],&p[2],&p[3]);
			s[i] = SLIDE();
		}
		for(i = 0; i < N; i++){
			scanf("%d%d",&x,&y);
			for(j = 0; j < N; j++)
				if(pis(x,y,s[j])){
					a[j][0] |= (1<<i); d[j][0]++;
					a[i][1] |= (1<<j); d[i][1]++;
				}
		}
		progress = 1; success = 0;
		while(progress){
			/* Adiciona os casais ja determinados a uma fila */
			for(i = 0; i < N; i++){
				if(d[i][0] == 1) q.push(pair<int, bool>(i,0));
				if(d[i][1] == 1) q.push(pair<int, bool>(i,1));
			}
			p1 = !q.empty();
			while(!q.empty()){
				success = 1;
				int k = q.front().first; bool num = q.front().second;
				q.pop();
				int NMB, NNN, SLD, SSS;
				if(num) SLD = log2(a[k][1]), NMB = k;
				else	SLD = k, NMB = log2(a[k][0]);
				a[SLD][0] = a[NMB][1] = d[SLD][0] = d[NMB][1] = 0;
				if(married[SLD][0] || married[NMB][1]) continue;
				married[SLD][0] = married[NMB][1] = 1;
				m[SLD] = NMB; /* casa a letra com o numero */
				/* elimina as adjacencias correspondentes */
				NNN = (1<<NMB); SSS = (1<<SLD);
				for(i = 0; i < N; i++){
					if(a[i][0] & NNN){
						a[i][0] -= NNN;
						if(--d[i][0] == 1) q.push(make_pair(i,0));
					}
					if(a[i][1] & SSS){
						a[i][1] -= SSS;
						if(--d[i][1] == 1) q.push(make_pair(i,1));
					}
				}
			}
			/* elimina grupos fechados O(n^2) */
			for(p2 = i = 0; i < N; i++){
				int NP = d[i][0], SP = d[i][1];
				int NC = 1, SC = 1, NQ[N], SQ[N], list[30], ls;
				NQ[0] = i, SQ[0] = i;
				if(NP > 1){ 
					for(j = i+1; j < N; j++)
						if(a[i][0] == a[j][0]) NQ[NC++] = j;
					if(NC == NP){
						p2 = 1;
						for(j = ls = 0; ls < NC; j++, a[i][0]>>=1)
							if(a[i][0]&1){
								list[ls++] = j;
							}
						for(j = 0; j < NC; j++){
							remove(list[j],1);
							remove(NQ[j],0);
						}
					}
				}
				if(SP > 1 && a[i][1]){ 
					for(j = i+1; j < N; j++)
						if(a[i][1] == a[j][1]) SQ[SC++] = j;
					if(SC == SP){
						p2 = 1;
						for(j = ls = 0; ls < SC; j++, a[i][1]>>=1)
							if(a[i][1]&1) list[ls++] = j;
						for(j = 0; j < SC; j++){
							remove(list[j],0);
							remove(SQ[j],1);
						}
					}
				}
			}
			progress = p1|p2;
		}
		/* OUTPUT */
		printf("Heap %d\n",hn);
		if(success){
			for(i = 0; i < N; i++)
				if(married[i][0]){
					if(!success) putc(' ',stdout);
					success = 0;
					printf("(%c,%d)",i+'A',m[i]+1);
				}
			putc(10,stdout); putc(10,stdout);
		}
		else printf("none\n\n");

	}
	return 0;
}

