#include <algorithm>
#include <iostream>
using namespace std;
long long p[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
int cnt[10], fc = 0;
void add_factor(int &x, int f){ while(!(x % f)) cnt[fc++] = f, x /= f; }
void factor(int x){
	if(!(x&1)) add_factor(x, 2);
	for(int i = 3; ; i += 2){ if(!(x%i)) add_factor(x, i); if(i*i > x) break; }
	if(x != 1) add_factor(x, x);
}
int main(void){
	int n; cin >> n;
	factor(n);
	sort(cnt, cnt + fc);
	long long ans = 1;
	for(int x = fc, i = 0; x--; ++i){
		if(x){
			int pwr = cnt[x] * (cnt[x - 1] - 1);
			if((p[i] == 2 && (1 << pwr) < p[fc-1]) || (p[i] == 3 && pwr < 3 && 9 < p[fc-1])){
				cnt[x - 1] *= cnt[x];
				fc--; i--;
				continue;
			}
		}
		for(int j = 1; j < cnt[x]; ++j) ans *= p[i];
	}
	cout << ans << endl;
}

