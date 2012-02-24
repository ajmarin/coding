#include <cstdio>
#include <cstring>

const int N = 128, P = 1048576;
bool busy[P];
int l[N], r[N];
int b[N], d[N], p[N];
int m, n;

int conflict(){
	memset(busy, false, P);
	int begin, end;
	for(int i = 0; i < n; ++i)
		for(int j = l[i]; j < r[i]; ++j){
			if(busy[j]) return true;
			busy[j] = true;
		}
	for(int i = 0; i < m; ++i)
		for(int j = 0; b[i] + j * p[i] < P; ++j){
			begin = b[i] + j * p[i];
			end = begin + d[i];
			for(int k = begin; k < P && k < end; ++k){
				if(busy[k]) return true;
				busy[k] = true;
			}
		}
	return false;
				
}
int main(void){
	while(scanf("%d %d", &n, &m) == 2 && (m | n)){
		for(int i = 0; i < n; ++i) scanf("%d %d", l + i, r + i);
		for(int i = 0; i < m; ++i){
			scanf("%d %d %d", b + i, d + i, p + i);
			d[i] -= b[i];
		}
		puts("NO CONFLICT" + 3 * conflict());
	}
	return 0;
}

