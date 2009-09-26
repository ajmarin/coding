#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
int PC[100];
int list[10000], newp[10000];
bool oc[20000];
int main(void){
	int closest, i, j, list_size, np = 0, v, N, K, VALUE;
	char c[10];
	while(scanf("%d%d",&N,&K) && N){
		for(i = 0; i < N; i++){
			scanf("%s",c);
			PC[i] = 0;
			for(j = 0; c[j]; j++){
				if(c[j] == '.') continue;
				PC[i] = PC[i]*10+c[j]-'0';
			}
		}
		swap(PC[K-1], PC[0]);
		VALUE = 5001 - PC[0];
		if(VALUE > 0 && PC[0]){
			memset(oc,0,sizeof(oc));
			list_size = 0;
			closest = 10000;
			for(i = 1; i < N; i++){
				np = 0;
				if(PC[i] >= VALUE && PC[i] < closest){
					closest = PC[i];
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
					else closest = MIN(v,closest);
				}
				while(np--) list[list_size++] = newp[np];
			}
			i = closest;
			double ans = 100.0*(double)PC[0]/(double)(i+PC[0]);
			printf("%.2lf\n", round(100.0*ans)/100.0);
		} else if(PC[0]) printf("100.00\n");
		else printf("0.00\n");
	}
	return 0;
}


