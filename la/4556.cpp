#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
char number[128];
int main(void){
	int z; scanf("%d", &z);
	for(int c; scanf("%d %s", &c, number) == 2; ){
		if(next_permutation(number, number + strlen(number))) 
			printf("%d %s\n", c, number);
		else printf("%d BIGGEST\n", c);
	}
	return 0;
}

