#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>

int ans;
char f[2][1200];
int add(bool a, bool b){ 
	int i, d, c=0; 
	int l1 = strlen(f[a]); 
	int l2= strlen(f[b]); 
	for(i = l1; i < l2; ++i) f[a][i] = '0'; 
	for(i = l2; i < l1; ++i) f[b][i] = '0'; 
	for(i = 0; i < l1|| i < l2; ++i){ 
		c= (f[a][i] - '0') + (f[b][i] - '0') + c; 
		f[a][i] = c % 10 + '0';
		c /= 10;
	} 
	while(c){ 
		f[a][i++]= '0' + (c%10); 
		c /= 10;
	} 
	f[a][i]='\0'; 
	f[b][l2]='\0'; 
	return i;
}
int main(void){
	clock_t ini = clock();
	strcpy(f[0], "1"); strcpy(f[1], "1");
	for(int i = 3; ; ++i) {
		int len = add(i & 1, !(i & 1));
		if(len > 999){ ans = i; break; }
	}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}

