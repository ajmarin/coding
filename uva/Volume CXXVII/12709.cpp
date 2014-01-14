#include <cstdio>

int main(void){
	for(int n; scanf("%d", &n) == 1 && n; ){
		int maxHeight = 0, volume = 0;
		for(int i = 0, h, l, v, w; i < n; ++i){
			scanf("%d %d %d", &l, &w, &h);
			v = l * w * h;
			if(h > maxHeight){
				maxHeight = h;
				volume = v;
			} else if(h == maxHeight && v > volume)
				volume = v;
		}
		printf("%d\n", volume);
	}
}
		
