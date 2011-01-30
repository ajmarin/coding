#include <cstdio>

char line[1024], t[1024], *p;
int T, r, c;

void printcol(int c) {
        if(!c) return;
        printcol((c - 1)/26);
        putchar(((c - 1)% 26) + 'A');
}

int main(void) {
        scanf("%d", &T);
        while(T--) {
                scanf("%s", line);
                if(sscanf(line,"R%dC%d", &r, &c) == 2) {
                        printcol(c);
                        printf("%d\n", r);
                } else {
                        sscanf(line, "%[A-Z]%d", t, &r);
                        for(p = t, c = 0; *p; p++) c = c * 26, c += *p - 'A' + 1;
                        printf("R%dC%d\n", r, c);
                }
        }
        return 0;
}
