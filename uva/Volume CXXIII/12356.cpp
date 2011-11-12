#include <cstdio>

const int NN = 100048;
int left[NN], right[NN];
bool dead[NN];
int main(void){
	for(int b, s; scanf("%d %d", &s, &b) == 2 && s; ){
		for(int i = 0; i <= s + 1; ++i){
			left[i] = i - 1;
			right[i] = i + 1;
			dead[i] = false;
		}
		int new_left, new_right;
		for(int i = 0, y, z; i < b; ++i){
			scanf("%d %d", &y, &z);
			for(int j = y; j <= z; ++j)
				dead[j] = true;
			new_left = y;
			new_right = z;
			while(dead[new_left]) new_left = left[new_left];
			while(dead[new_right]) new_right = right[new_right];
			for(int j = y; j <= z; ++j){
				left[j] = new_left;
				right[j] = new_right;
			}
			if(new_left > 0 && new_right <= s) printf("%d %d\n", new_left, new_right);
			else if(new_left > 0) printf("%d *\n", new_left);
			else if(new_right <= s) printf("* %d\n", new_right);
			else puts("* *");
		}
		puts("-");
	}
	return 0;
}

