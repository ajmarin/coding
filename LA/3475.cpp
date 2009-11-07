#include <cstdio>
#include <algorithm>

const char *noway = "No solution", *z = "0";
int n[32], pos[32], s[256];
int main(void){
	int i, x, s_size, N;
	bool imp;
	while(scanf("%d",&N) && N){
		imp = 0;
		memset(n,-1,sizeof(n));
		for(i = 1; i <= N; i++){
			scanf("%d",&x);
			if(n[x] == -1) n[x] = i, pos[i] = x;
			else imp = 1;
		}
		if(!imp){
			s_size = 0;
			for(i = 1; i <= N; i++){
				while(pos[i] != i){
					while(pos[i] > i) {
						pos[n[pos[i]-1]]++;					
						std::swap(n[pos[i]-1],n[pos[i]]);						
						s[s_size++] = --pos[i];
					}
					while(pos[i] < i) {
						pos[n[pos[i]+1]]--;
						std::swap(n[pos[i]],n[pos[i]+1]);
						s[s_size++] = pos[i]++;
					}
				}
			}
			if(s_size){
				printf("%d",s_size);
				while(s_size--) printf(" %d",s[s_size]);
				putc(10,stdout);
			} else puts(z);
		}
		else puts(noway);
	}
	return 0;
}
