#include <cstdio>
#include <cstring>
#include <cstdlib>
char p[12];
char ans[15], kpp[10], line[1000];
bool dans = 0;
int main(void){
	int i, n;
	ans[11] = '\0';
	for(i = 0; i < 6; i++) ans[(i<<1) + 1] = ' ';
	for(int t = 1; scanf("%d\n",&n) && n; t++){
		for(i = 0; i < 6;  i++) ans[(i<<1)] = -1;
		for(i = 0; i < 12; i++) p[i] = -1;
		while(n--){
			gets(line);
			char * part = strtok(line," ");
			for(i = 0; i < 10; i++)
				kpp[i] = atoi(part), part = strtok(NULL," ");
			for(i = 0; i < 6; i++){
				char x = i<<1;
				char d = (*part)-'A';
				if(ans[x] == -1){
					char y = d<<1;
					int a = kpp[y], b = kpp[y+1];
					if(a > b) a ^= b ^= a ^= b;
					if(p[x] != -1){
						if(p[x] != a || p[x+1] != b)
							if(p[x] == a || p[x+1] == a) ans[x] = a + '0';
							else if(p[x] == b || p[x+1] == b) ans[x] = b + '0';
					} else p[x] = a, p[x+1] = b;				
				} 
				part = strtok(NULL," ");
			}
		}
		printf("Teste %d\n%s\n\n",t,ans);
	}
	return 0;
}
