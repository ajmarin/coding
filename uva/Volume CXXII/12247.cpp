#include <algorithm>
#include <cstdio>
using namespace std;

int a[3], b[2];
bool busy[64], used[3];
int main(void){
	while(scanf("%d %d %d %d %d", &a[0], &a[1], &a[2], &b[0], &b[1]) == 5){
		if(!(a[0] || a[1] || a[2] || b[0] || b[1])) break;
		int s = 1, win = 0;
		sort(a, a + 3);
		if(b[0] > b[1]) swap(b[0], b[1]);
		for(int i = 0; i < 64; ++i) busy[i] = 0;
		busy[a[0]] = busy[a[1]] = busy[a[2]] = busy[b[0]] = busy[b[1]] = 1;
		used[0] = used[1] = used[2] = 0;
		for(int i = 0; i < 2; ++i){
			int x = b[i], y = -1, idx = -1;
			for(int j = 0; j < 3; ++j)
				if(!used[j] && a[j] > x){ y = a[j], idx = j; break; }
			if(idx == -1)
				for(int j = 0; j < 3; ++j)
					if(!used[j]){ y = a[j], idx = j; break; }
			used[idx] = 1;
			if(x > y) ++win;
		}
		if(win){
			if(win == 1) for(int j = 0; j < 3; ++j) if(!used[j]) s = a[j] + 1;
			while(busy[s]) ++s;
		}
		if(!win || s > 52) puts("-1");
		else printf("%d\n", s);

	}
	return 0;
}

