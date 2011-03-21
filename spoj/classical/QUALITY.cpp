#include <cstdio>
 
int main(void){
        int a, b, c, d, e, f, tc = 1;
        int mask[2] = {0xFFFFFFFF, 0};
        while(scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f) == 6){
                int total = 0;
                total += mask[!a] & (a + 1200 * (d - 1));
                total += mask[!b] & (b + 1200 * (e - 1));
                total += mask[!c] & (c + 1200 * (f - 1));
                printf("team %d: %d, %d\n", tc++, (!!a)+(!!b)+(!!c), total);
        }
        return 0;
}

