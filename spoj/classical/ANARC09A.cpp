#include <cstdio>
char input[2048];
int main(void){
	for(int cnum = 0; scanf("%s", input) && input[0] != '-'; ){
		int b = 0, c = 0;
		for(int i = 0; input[i]; ++i){
			b += (input[i] == '{') - (input[i] == '}');
			if(b < 0) b += 2, ++c;
		}
		printf("%d. %d\n", ++cnum, c + (b >> 1));
	}
	return 0;
}

