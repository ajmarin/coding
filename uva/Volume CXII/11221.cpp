#include <cstdio>
#include <cmath>

char line[10048], msg[10048];
int cnt;

bool is_square(int x){
	int root = int(floor(sqrt(x) + .5));
	return root * root == x;
}

bool magic(){
	int root = int(floor(sqrt(cnt) + .5));
	for(int i = 0; i < cnt; ++i){
		char wanted = msg[i];
		int a = cnt - i - 1, b = (i % root) * root + i / root, c = cnt - b - 1;
		if(msg[a] != wanted || msg[b] != wanted || msg[c] != wanted) return false;
	}
	return true;
}

int main(void){
	int t; scanf("%d\n", &t);
	for(int cn(0); t-- && fgets(line, 10048, stdin); ){
		cnt = 0; 
		for(int i = 0; line[i]; ++i)
			if(line[i] >= 'a' && line[i] <= 'z')
				msg[cnt++] = line[i];
		if(is_square(cnt) && magic())
			printf("Case #%d:\n%d\n", ++cn, int(sqrt(cnt) + .5));
		else printf("Case #%d:\nNo magic :(\n", ++cn);
	}
	return 0;
}

