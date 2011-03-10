#include <cstdio>
 
int main(void){
        for(int a, b, c; scanf("%d %d %d", &a, &b, &c) == 3; ){
                if(!(a || b || c)) break;
                if(c - b == b - a) printf("AP %d\n", (c<<1) - b);
                else printf("GP %d\n", (c * c) / b);
        }
        return 0;
}

