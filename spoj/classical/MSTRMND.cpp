#include <cstdio>
int main(void){
        int a[4] = {1, 1, 1, 1}, b[4], sum;
        while(sum != 4){
                for(int i = 0; i < 4; ++i) printf("%d%c", a[i], i == 3 ? 10 : 32);
                fflush(stdout); sum = 0;
                for(int i = 0; i < 4; ++i){
                        scanf("%d", b + i);
                        if(b[i] != 1) ++a[i];
                        sum += b[i];
                }
        }
        return 0;       
}

