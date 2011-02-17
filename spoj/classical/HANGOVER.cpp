#include <cstdio>
 
float p[512];
int main(void){
        p[0] = 0;
        for(int i = 1; i < 512; ++i) p[i] = p[i - 1] + 1. / (i + 1);
        for(float x; scanf("%f", &x) && x; ){
                int i; for(i = 0; p[i] < x; ++i);
                printf("%d card(s)\n", i);
        }
        return 0;
}

