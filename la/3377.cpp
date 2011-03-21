#include <cstdio>
typedef unsigned uint;
struct rect {
	int x1, x2, y1, y2;
	int h, w;
	rect(int _x1=0, int _y1=0, int _x2=0, int _y2=0):
		x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}
} r[1024];
uint sqsum(int x){
	long long t = x;
	return (t * (t + 1) * (2*t + 1))/ 6;
}
int abs(int a){ return a < 0 ? -a : a; }
int min(int a, int b){ return a < b ? a : b; }
int max(int a, int b){ return a > b ? a : b; }
int main(void){
	uint cnt, curr = 0;
	for(int cnum = 0, n; scanf("%d", &n) && n; ){
		cnt = 0;
		int h, m, w, x1, x2, y1, y2;
		for(int i = 0; i < n; ++i){
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			if(x1 > x2) m = x1, x1 = x2, x2 = m;
			if(y1 > y2) m = y1, y1 = y2, y2 = m;
			r[i] = rect(x1, y1, x2, y2);
			h = r[i].h = y2 - y1;
			w = r[i].w = x2 - x1;
			m = min(r[i].h, r[i].w);
			curr = m * (h*w) - ((m*(m-1))>>1) * (h + w) + sqsum(m-1); 
			cnt += curr;
			for(int j = 0; j < i; ++j){
				int gap;
				if(r[i].x1 == r[j].x2 || r[i].x2 == r[j].x1){
					/* VERTICAL GAP */
					gap = min(r[i].y2, r[j].y2) - max(r[i].y1, r[j].y1) - 2;
					if(gap < 2) continue;
					int space = r[i].w + r[j].w;
					for(int a = 2, b = gap - 1; a <= gap && a <= space; ++a, --b)
						cnt += b * (min(a-1,r[i].w)+min(a-1,r[j].w) - a + 1);
				} 
				if(r[i].y1 == r[j].y2 || r[i].y2 == r[j].y1){
					/* HORIZONTAL GAP */
					gap = min(r[i].x2, r[j].x2) - max(r[i].x1, r[j].x1) - 2;
					if(gap < 2) continue;
					int space = r[i].h + r[j].h;
					for(int a = 2, b = gap - 1; a <= gap && a <= space; ++a, --b)
						cnt += b * (min(a-1,r[i].h)+min(a-1,r[j].h) - a + 1);
				}
			}
		}
		printf("Case %d: %u\n", ++cnum, cnt);
	}
	return 0;
}

