#include <cstdio>
#include <cstring>
#define T(x) strtok(x, " \n\r\t")
char line[32768];
int main(void){
        int t; scanf("%d\n", &t);
        while(t--){
                fgets(line, 32768, stdin);
                int cnt = 1, len, maxcnt = 0, plen = -1;
                for(char *p = T(line); p != NULL; p = T(NULL)){
                        len = strlen(p);
                        if(len == plen) ++cnt;
                        else cnt = 1;
                        if(cnt > maxcnt) maxcnt = cnt;
                        plen = len;
                }
                printf("%d\n", maxcnt);
        }
        return 0;
}

