#include <cstdio>
int end[4] = {192, 442, 692, 942};
int main(void){
        int t; scanf("%d", &t);
        for(long long n; t-- && scanf("%lld", &n); ){
                int idx = --n & 3;
                if(n >>= 2) printf("%lld", n);
                printf("%d\n", end[idx]);
        }
        return 0;
}

