#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define MIN(a,b) ((a)<(b)?(a):(b))
#define NN 22501
using namespace std;
int PC[100];
int list[NN], newp[NN];
long long mask[NN];
bool oc[NN];
int main(void){
	int i, j, ls, np, s, v, HALF, N, T, VALUE;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(i = s = 0; i < N; s+=PC[i++]) scanf("%d",&PC[i]);
		if(N == 1){ 
			printf("0 %d\n",PC[0]);
			if(T) putc(10,stdout);
			continue;
		}
		sort(PC,PC+N);
		VALUE = s>>1;
		HALF = (N>>1);
		memset(oc,0,sizeof(oc));
		memset(mask,0,sizeof(mask));
		ls = 0;
		for(i = 0; i < N; i++){
			if(PC[i] > VALUE) continue;
			np = 0;
			if(!oc[PC[i]]){
				newp[0] = PC[i];
				np = oc[PC[i]] = 1;
			}
			for(j = ls; j--; ){
				v = PC[i] + list[j];
				if(v > VALUE) continue; 
				mask[v] |= mask[list[j]]<<1;
				if(oc[v]) continue;
				oc[v] = 1;
				newp[np++] = v;
			}
			mask[PC[i]] |= 1;
			while(np--) list[ls++] = newp[np];
		}
		long long MSK = (1LL<<(HALF-1));
		if(N&1) MSK |= (1LL<<HALF);
		for(i = VALUE; ; i--) if(oc[i] && (mask[i] & MSK)) break;
		printf("%d %d\n",i,s-i);
		if(T) putc(10,stdout);
	}
	return 0;
}

