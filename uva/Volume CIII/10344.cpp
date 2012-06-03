#include <cstdio>

int z[8];
bool used[8];

bool bt(int r, int n){
	if(n == 5) return r == 23;
	bool x = false;
	for(int i = 0; !x && i < 5; ++i) if(!used[i]){
		used[i] = true;
		x |= bt(r + z[i], n + 1);
		x |= bt(r - z[i], n + 1);
		x |= bt(r * z[i], n + 1);
		used[i] = false;
	}
	return x;
}

int main(void){
	for(int s = 0; ; s = 0){
		bool possible = false;
		for(int i = 0; i < 5; ++i){
			used[i] = false;
			scanf("%d", z + i);
			s += z[i];
		}
		if(!s) break;
		for(int i = 0; !possible && i < 5; ++i){
			used[i] = true;
			possible |= bt(z[i], 1);
			used[i] = false;
		}
		puts("Impossible\0Possible" + (possible ? 11 : 0));
	}
	return 0;
}

