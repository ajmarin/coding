#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <string>
using namespace std;
class BigInt {
    public:
    string n;
    BigInt(long long num = 0){
        n = num ? "" : "0";
        while(num) n += num % 10 + '0', num /= 10;
    }
    BigInt operator +(BigInt b){
        BigInt r;
        r.n = n;
        int c, i, l1 = r.n.size(), l2 = b.n.size();
        for(i = l1; i < l2; ++i) r.n += '0';
        for(i = l2; i < l1; ++i) b.n += '0';
        for(c = i = 0; i < l1 || i < l2; ++i){
            r.n[i] = ((c = r.n[i] - '0' + b.n[i] - '0' + c) % 10) + '0';
            c /= 10;
        }
        if(c) r.n += c + '0', ++i;
        b.n = b.n.substr(0, l2);
        return r;
    }
};
BigInt fact[110], r;
int main(void){
    int n, t; scanf("%d", &n);
    fact[0] = fact[1] = 1;
    for(int i = 2; i < 110; ++i){
        fact[i] = 0;
        r = fact[i - 1];
        for(int j = i; j; j >>= 1){
            if(j & 1) fact[i] = fact[i] + r;
            r = r + r;
        }
        string &s = fact[i - 1].n;
        reverse(s.begin(), s.end());
    }
    for(int i = 0; i < n; ++i){
        scanf("%d", &t);
        printf("%s\n", fact[t].n.c_str());
    }
    return 0;
}
