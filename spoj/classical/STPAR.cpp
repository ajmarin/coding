#include <cstdio>
 
int main(void){
        int stack[1024];
        for(int n; scanf("%d", &n) && n; ){
                int top = 0, want = 1, z;
                bool ok = true;
                for(int i = 0; i < n; ++i){
                        scanf("%d", &z);
                        if(z != want){
                                while(top && stack[top - 1] == want) ++want, --top;
                                if(!top || stack[top - 1] > z) stack[top++] = z;
                                else ok = false;
                        } else ++want;
                }
                puts(ok ? "yes" : "no");
        }
        return 0;
} 

