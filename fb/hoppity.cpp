#include <cstdio>

int main(int argc, char *args[]){
	int a;
	if(argc != 2) return 1;
	freopen(args[1], "r", stdin);
	scanf("%d", &a);
	for(int i = 1; i <= a; ++i)
		if(!(i % 3) && !(i % 5)) puts("Hop");
		else if(!(i % 3)) puts("Hoppity");
		else if(!(i % 5)) puts("Hophop");
	return 0;
}
	
