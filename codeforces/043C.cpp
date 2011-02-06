#include <cstdio>
int mod[3];
int main(void){	
	int n, t; scanf("%d", &n);
	mod[0] = mod[1] = mod[2] = 0;
	while(n--){	scanf("%d", &t); ++mod[t % 3]; }
	printf("%d\n", (mod[0] >> 1)+ (mod[1] < mod[2] ? mod[1] : mod[2]));
	return 0;
}
