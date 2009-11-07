#include <cstdio>
int i, j, max, n, v[100];
int main(void){
	register char c;
	while(scanf("%d\n",&n) && n){
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++){
				c = getchar();
				getchar();
				if(c == '1') v[j]++;
			}
		for(max = i = 0; i < n; v[i] = 0, i++)
			if(v[i] > max) max = v[i], j = i;
		printf("%d\n",max);
	}
	return 0;
}
