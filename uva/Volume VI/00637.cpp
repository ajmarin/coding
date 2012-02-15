#include <cstdio>

int n;
void show(int &a, int &b, int i){
	if(i & 1){
		if(a > n) printf("Blank,");
		else printf("%d,", a);
		--a;
		printf(" %d\n", b++);
	} else {
		printf("%d,", b++);
		if(a > n) puts(" Blank");
		else printf(" %d\n", a);
		--a;
	}
}
int main(void){
	while(scanf("%d", &n) == 1 && n){
		int a = ((n + 3) >> 2) << 2, b = 1;
		printf("Printing order for %d pages:\n", n);
		for(int i = 1; i <= ((n + 3) >> 2); ++i){
			if(a <= n || b <= n){
				printf("Sheet %d, front: ", i);
				show(a, b, (i<<1) + 1);
			}
			if(a <= n || b <= n){
				printf("Sheet %d, back : ", i);
				show(a, b, (i<<1));
			}
		}
	}
	return 0;
}

