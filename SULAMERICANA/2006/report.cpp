#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>

#define MIN(a,b) ((a)<(b)?(a):(b))
#define IN getc( stdin )
#define OUT(x) putc(x, stdout)
#define OUT2(x,y) OUT(x), OUT(y)
#define OUT3(x,y,z) OUT2(x,y), OUT(z)

char rep[256], dig[8][32], name[8][25],*c_pos[8];
int dL[8], sL[8], sC[8], tC[8];
int pnum, td[8], tl, ts[8], tsl[8];
bool s;
int n[8][8];
void bt(int L, int i){
	if(s) return;
	if(i == 0){
		c_pos[L] = dig[L];
		n[L][pnum] = atoi(dig[L] + td[L] - ts[L]);
		dL[L] = td[L] - ts[L];
	}
	int max_ltd = MIN(dL[L] - (pnum - i), 5), k;
	if(i == pnum){
		if(sL[L] == n[L][pnum]){
			if(L == tl-1) for(k = 0; k <= pnum; ++k) tC[k] = n[L][k]; 
			bool ok = 1;
			if(L != tl-1)
				for(k = 0; k <= pnum; ++k)
					sC[k] += n[L][k], ok &= (sC[k] <= tC[k]);
			if(ok){
				int b = L-1;
				if(b >= 0) for(ts[b] = 1; ts[b] < 6; ++ts[b]) bt(b, 0);
				else for(b = 0, s = 1; s && b <= pnum; ++b) s &= (sC[b] == tC[b]);		
			}
			if(L != tl-1) for(k = 0; k <= pnum; k++) sC[k] -= n[L][k];

		}
		return;
	}
	if(s) return;
	int ltdl = 5;
	if(i == pnum-1 && dL[L] > 4) return;
	if(dL[L] <= 0) return;
	for(int ltd = MIN(4, dL[L]); ltd > 0; --ltd){
		if(s) return;
		n[L][i] = 0;
		if(ltd > 1 && *(c_pos[L]) == '0') continue;
		for(k = 0; *(c_pos[L]+k) && k < ltd; ++k) n[L][i] = (n[L][i]*10) + (*(c_pos[L]+k) - '0');		
		sL[L] += n[L][i]; c_pos[L] += ltd; dL[L] -= ltd;
		if(sL[L] <= n[L][pnum]) bt(L, i+1);
		sL[L] -= n[L][i]; c_pos[L] -= ltd; dL[L] += ltd;
		ltd -= (i == pnum-1)*dL[L];
	}
}
		
int main(void){
	int T, i;
	scanf("%d\n", &T);
	while(T--){
		register char c;
		pnum = s = 0;
		while((c = IN) != 'T') OUT3(c, IN, ' '), pnum++; OUT(c);
		while((c = IN) != '\n') OUT(c); OUT(10);
		for(i = 0; rep[0] != 'T' || rep[1] != 'P'; ++i){
			fgets(rep, 200, stdin);
			int l = strlen(rep) - 1;
			rep[l--] = 0;
			char *p;
			for(p = rep; !isdigit(*p); ++p); 
			strcpy(dig[i], p);
			*p = 0;
			strcpy(name[i], rep);
			td[i] =  l - (p - rep) + 1;
		}
		tl = i--;
		for(ts[i] = 1; ts[i] < 6; ++ts[i]) bt(i, 0);
		for(i = 0; i < tl; ++i){
			printf("%s",name[i]);
			for(char j = 0; j <= pnum; ++j)
				printf(" %d",n[i][j]);
			OUT(10);
		}
		memset(sC, 0, sizeof(sC));
		memset(sL, 0, sizeof(sL));
		rep[0] = rep[1] = 'a';
	}
	return 0;
}
