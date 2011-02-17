#include <cstdio>
 
int main(void){
        int t; scanf("%d", &t);
        while(t--){
                int a, b, r = 1; scanf("%d %d", &a, &b); a %= 10;
                while(b){
                        if(b & 1) r = (r * a) % 10;
                        a = (a * a) % 10;
                        b >>= 1;
                }
                printf("%d\n", r);
        }
        return 0;
}

