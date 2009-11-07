#include <cstdio>
#define NMAX 5000
bool p[NMAX][NMAX];
char w[NMAX+2];
int i, j, k, min, mp[NMAX], n;
int main(void){
	for(int t = 1; scanf("%d\n",&n) && n; t++){
		gets(w);
		for(i = 0; i < n; i++) p[i][i] = 1;
		for(i = 0; i < (n-1); i++) p[i][i+1] = w[i]==w[i+1];
		for(i = 2; i < n; i++)
			for(j = 0, k = j+i; k < n; j++,k++)
				p[j][k] = p[j+1][k-1] & w[j]==w[k];
		for(i = 0; i < n; i++){
			if(p[0][i]){ mp[i] = 1; continue; }
			min = 5001;
			for(k = 0; k < i; k++)
				mp[i] = (min = ((p[k+1][i]&&mp[k]<min)?mp[k]:min))+1;
		}
		printf("Teste %d\n%d\n\n",t,mp[n-1]);
	}
	return 0;
}

