#include <cstdio>

char ins[128];
int z[128];
int main(void){
	scanf("%*d");
	for(int n; scanf("%d", &n) == 1; ){
		int pos = 0;
		scanf(" ");
		for(int i = 0; i < n; ++i){
			fgets(ins, 128, stdin);
			if(*ins == 'L') z[i] = -1;
			else if(*ins == 'R') z[i] = 1;
			else {
				int x;
				sscanf(ins + 8, "%d", &x);
				z[i] = z[--x];
			}
			pos += z[i];
		}
		printf("%d\n", pos);
	}
	return 0;
}

