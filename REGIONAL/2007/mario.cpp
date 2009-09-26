#include<cstdio>
int A, gaps, i, j, L, min_gaps, N;
int v[100001];
int main(void){
	while(scanf("%d%d",&N,&L) && N){
		min_gaps = 1<<29;
		for(i = 0; i < L; i++) scanf("%d",&v[i]);
		for(i = 0; min_gaps && i < L; i++){
			gaps = 0;
			for(j = i+1; j < L; j++){
				gaps += v[j]-v[j-1]-1;
				if(gaps+j+1-i >= N){
					if(v[j]-v[i] < N) A = j-i+1;
					else A = j-i;
					gaps = N - A;
					if(gaps < min_gaps)
						min_gaps = gaps;
					break;
				}
			}
		}
		if(min_gaps > N) printf("%d\n",N-1);
		else printf("%d\n",min_gaps);
	}
	return 0;
}
