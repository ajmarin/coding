#include <cstdio>
typedef long long LL;
const LL M = 1000000007;
int main(void){
        int t; scanf("%d", &t);
        while(t--){
                int n; scanf("%d", &n); --n;
                LL r = 1, mult = 2;
                while(n){
                        if(n & 1) r = (r * mult) % M;
                        mult = (mult * mult) % M;
                        n >>= 1;
                }
                printf("%lld\n", r);
        }               
        return 0;
}

