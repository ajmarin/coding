#include <cstdio>

int main(void){
	int t; scanf("%d\n", &t);
	while(t--){
		int y[3] = {0, 0, 0};
		int z[3] = {0, 0, 0};
		int idx = 0;
		for(char c; (c = getc(stdin)) != 10; )
			if((c == 'M' && idx == 0) || (c == 'E' && idx == 1)) ++idx;
			else if(c == '?') ++y[idx];
			else ++z[idx];
		puts(!(z[0] + z[1] + z[2]) && y[0] > 0 && y[1] > 0 && y[0] + y[1] == y[2] ?
				"theorem" : "no-theorem");
	}
	return 0;
}

