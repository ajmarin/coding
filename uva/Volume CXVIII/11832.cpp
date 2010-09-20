#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
bool r[2][80000];
char ans[2][80001][45], temp[45];
int list[2][80000], lf[2];
int v[64], pos[64];
void append(char *str, char c, int idx){
	str[idx] = c;
	str[idx + 1] = 0;
}
void merge(char *p, char *q, int x){
	for(int i = 0; i < x; ++i, ++p) if(*p != *q++) *p = '?';
}
bool cmp(int a, int b){
	return v[a] > v[b];
}
int main(void){
	int lp, n, F, sum;
	int cl, pl;
	while(scanf("%d %d", &n, &F) && n){
		sum = 0;
		F = 40000 + F;
		for(int i = 0; i < n; ++i){
			scanf("%d", &v[i]);
			pos[i] = i;
			sum += v[i];
		}
		for(int j = 0; j < 80001; ++j) 
			r[0][j] = r[1][j] = ans[0][j][0] = ans[1][j][0] = 0;
		sort(pos, pos + n, cmp);
		list[0][0] = 40000;
		lf[0] = 1;
		for(int i = 0; i < n; ++i){
			sum -= v[pos[i]];
			pl = i & 1;
			cl = !pl;
			lf[cl] = 0;
			for(int j = 0, z; j < lf[pl]; ++j){
				int x = list[pl][j];
				r[pl][x] = 0;
				z = x + v[pos[i]];
				if(abs(z - F) <= sum){
					if(r[cl][z]){
						append(ans[pl][x], '+', i);
						merge(ans[cl][z], ans[pl][x], i + 1);
						ans[pl][x][i] = 0;
					} else {
						r[cl][z] = 1;
						strcpy(ans[cl][z], ans[pl][x]);
						append(ans[cl][z], '+', i);
						list[cl][lf[cl]++] = z;
					}
				}
				z = x - v[pos[i]];
				if(abs(z - F) <= sum){
					if(r[cl][z]){
						append(ans[pl][x], '-', i);
						merge(ans[cl][z], ans[pl][x], i + 1);
						ans[pl][x][i] = 0;
					} else {
						r[cl][z] = 1;
						strcpy(ans[cl][z], ans[pl][x]);
						append(ans[cl][z], '-', i);
						list[cl][lf[cl]++] = z;
					}
				}
			}
		}
		if(r[cl][F]){
			for(int i = 0; i < n; ++i) temp[pos[i]] = ans[cl][F][i];
			temp[n] = 0;
			puts(temp);
		}	
		else puts("*");
	}
	return 0;
}

