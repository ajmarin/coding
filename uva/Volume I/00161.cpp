#include <algorithm>
#include <cstdio>
using namespace std;

int v[128];
int main(void){
	for(int n; scanf("%d", &v[0]) == 1 && (v[0] <<= 1); ){
		int h, m, s = -1;
		for(n = 1; scanf("%d", v + n) == 1 && v[n]; ++n) v[n] <<= 1;
		sort(v, v + n);
		for(int sec = v[0]; sec < 18001; ++sec){
			bool all_green = true;
			for(int i = n; all_green && i--; ){
				all_green &= (sec % v[i]) < (v[i] >> 1) - 5;
			}
			if(all_green){
				h = sec / 3600;
				m = (sec -= h * 3600) / 60;
				s = sec % 60;
				break;
			}
		}
		if(s != -1) printf("%02d:%02d:%02d\n", h, m, s);
		else puts("Signals fail to synchronise in 5 hours");
	}
	return 0;
}

