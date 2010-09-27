#include <algorithm>
#include <cstdio>
using namespace std;
struct segment {
	int x1, x2, y1, y2;
	segment(int _x1 = 0, int _y1 = 0, int _x2 = 0, int _y2 = 0){
		x1 = _x1; y1 = _y1;
		x2 = _x2; y2 = _y2;
		if(x1 > x2){ swap(x1, x2); swap(y1, y2); }
	};
} s[1000];

int main(void){
	int ns, o, ox, oy, sc, t, x1, x2, y1, y2;
	for(scanf("%d", &t); t--; ){
		scanf("%d", &sc);
		for(int i = 0; i < sc; ++i){
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			s[i] = segment(x1, y1, x2, y2);
		}
		for(scanf("%d", &ns); ns--; ){
			scanf("%d %d", &ox, &oy);
			double cy = oy;
			while(1){
				int idx = -1;
				double cmaxy = 0.0;
				for(int j = 0; j < sc; ++j)
					if(ox > s[j].x1 && ox < s[j].x2){
						double v = s[j].y1 + (ox - s[j].x1) / (double) (s[j].x2 - s[j].x1) * (s[j].y2 - s[j].y1);
						if(v < cy && v > cmaxy) cmaxy = v, idx = j;
					}
				if(idx == -1){ printf("%d\n", ox); break; }
				else {
					if(s[idx].y1 > s[idx].y2) ox = s[idx].x2, cy = (double)s[idx].y2;
					else ox = s[idx].x1, cy = (double)s[idx].y1;
				}
			}
		}
		if(t) putc(10, stdout);
	}
	return 0;
}

