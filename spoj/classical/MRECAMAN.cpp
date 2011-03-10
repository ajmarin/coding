#include <cstdio>
#include <set>
using namespace std;
int a[500001];
set < int > s;
int main(void){
        for(int i = 1, t; i < 500001; ++i){
                t = a[i] = a[i - 1] - i;
                a[i] += (t <= 0 || s.find(t) != s.end()) ? i << 1 : 0;
                s.insert(a[i]);
        }
        for(int n; scanf("%d", &n) == 1 && n != -1; )
                printf("%d\n", a[n]);
        return 0;
} 

