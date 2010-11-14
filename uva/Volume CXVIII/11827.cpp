#include <cstdio>
#include <cstdlib>
#include <cstring>
int v[1024];
char line[100096];
int gcd(int a, int b) { 
	if(a % b == 0) return b;
	return gcd(b, a % b);
} 
int max(int a, int b){ return a > b ? a : b; }
int main(void){
	int t; scanf("%d\n", &t);
	while(t--){
		int i = 0, j, maxgcd = 0, z;
		char *p;
		fgets(line, 100096, stdin);
		for(i = 0, p = strtok(line, " "); p != NULL; ++i, p = strtok(NULL, " ")){
			z = atoi(p);
			if(z > maxgcd) for(j = 0; j < i; ++j) maxgcd = max(maxgcd, gcd(v[j], z));
			v[i] = z;
		}
		printf("%d\n", maxgcd);
	}
	return 0;
}

