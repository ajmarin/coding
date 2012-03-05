#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

string path[1 << 16];
int top;
void show_path(){
	printf("/");
	for(int i = 0; i < top; ++i)
		printf("%s/", path[i].c_str());
	puts("");
}
int main(void){
	char cmd[16], arg[1024];
	for(int n; scanf("%d", &n) == 1; ){
		top = 0;
		while(n--){
			scanf("%s", cmd);
			if(*cmd == 'p') show_path();
			else {
				scanf("%s", arg);
				if(*arg == '/') top = 0;
				for(char *p = strtok(arg, "/"); p != NULL; p = strtok(NULL, "/")){
					if(*p == '.' && *(p + 1) == '.') --top;
					else path[top++] = p;
				}
			}
		}
	}
	return 0;
}

