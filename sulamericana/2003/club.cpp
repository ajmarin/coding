#include<cstdio>
#include<algorithm>
#define EPS 1e-3
using namespace std;
int set[120][120];
int oc[120];
int ans, i, j, ign, K;
double R;
int main(void){
	while(scanf("%d%lf",&K,&R) && K){
		ans = 1;
		for(i = 0; i < K; i++)
			scanf("%d%d",&set[0][i],&ign),
			oc[i] = 0;
		oc[0] = K;
		sort(set[0],set[0]+K);
		int lim = K-1;
		for(i = 0; i < lim; i++)
			if(R*set[0][i] < set[0][lim])
				for(j = 1; ; j++)
					if(oc[j] == 0 || !(R*set[j][0]+EPS < set[0][i])){
						if(oc[j] == 0) ans++;
						set[j][oc[j]++] = set[0][i];
						break;
					}
		printf("%d\n",ans);
	}
	return 0;
}