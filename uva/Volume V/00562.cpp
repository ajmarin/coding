#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
int PC[100];
int list[25001], newp[25000];
bool oc[50001];
int main(void){
	int cdiff, i, j, list_size, np, s, v, N, T, VALUE;
	char c[10];
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(i = s = 0; i < N; s+=PC[i++]) scanf("%d",&PC[i]);
		VALUE = s>>1;
		memset(oc,0,sizeof(oc));
		list_size = 0;
		for(i = 0; i < N; i++){
			np = 0;
			if(PC[i] >= VALUE){
				oc[PC[i]] = 1;
				continue;
			}
			else if(!oc[PC[i]]){
				newp[0] = PC[i];
				np = oc[PC[i]] = 1;
			}
			for(j = 0; j < list_size; j++){
				v = PC[i] + list[j];
				if(oc[v]) continue;
				oc[v] = 1;
				if(v < VALUE) newp[np++] = v;
			}
			while(np--) list[list_size++] = newp[np];
		}
		int v1, v2;
		for(i = VALUE; !oc[i]; i--);
		v2 = s - i*2;
		for(i = VALUE+1; i < s && !oc[i]; i++);
		if(i < s) v1 = i*2 - s;
		else v1 = s;
		printf("%d\n",MIN(v1,v2));
	}
	return 0;
}


