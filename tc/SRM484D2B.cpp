#include <cstdio>
#include <string>

using namespace std;
typedef int ret;
int digitsum(long long x){
	int sum = 0;
	while(x){
		sum += x % 10;
		x = x / 10;
	}
	return sum;
}
class RabbitNumber {
	public:
		ret theCount(int, int);
};
ret RabbitNumber::theCount(int low, int high){
	ret r = 0;
	int seed[3] = {1, 2, 3};
	long long q[1000000], h = 0, t = 0;
	long long newlow = low, newhigh = high;
	for(int i = 0; i < 3; ++i){
		h = t = 0;
		q[t++] = seed[i];
		int vt = t;
		while(1){
			while(h < t){
				long long z = q[h++];
				if(z > 1000000000LL) continue;
				if(z >= newlow && z <= newhigh){
					int ds = digitsum(z), ds2 = digitsum(z * z);
					if(ds * ds == ds2){
						r++;
					}
				}
				for(int k = 0; k < 4; ++k){
					long long x = 10 * z + k;
					if(x <= newhigh){
						q[vt++] = x;
					}
				}
			}
			if(t == vt || vt >= 100000) break;
			t = vt;
		}
	}
	return r;
}

