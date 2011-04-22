#include <cmath>
#include <cstdio>
#include <stack>
using namespace std;
stack < double > s;
int main(void){
        for(long long n; scanf("%lld", &n) == 1; s.push(sqrt((double)n)));
        while(!s.empty()){
                printf("%.4lf\n", s.top());
                s.pop();
        }
        return 0;
}

