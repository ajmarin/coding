#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

#define FOR(i,n)	for(int i = 0; i < n; ++i)
#define FORI(i,s,n)	for(int i = s; i < n; ++i)
#define FORD(i, n)	for(int i = n; i > -1; --i)
#define IN(x)		(x = getc(stdin))
#define MAX(a,b)	((a) > (b) ? (a) : (b))
#define MIN(a,b)	((a) < (b) ? (a) : (b))
#define OUT(x)		putc(x, stdout)

int next[4] = {1, 2, 3, 0};
int b[1000][2];
int main(void){
	int i, j, v[4];
	scanf("%d %d %d %d", &v[0], &v[1], &v[2], &v[3]);
	for(i = 0; i < 1000; ++i){
		if(v[0] + v[1] + v[2] + v[3] == 4) break;
		for(j = 0; j < 4; ++j){
			int n = next[j];
			if(!(v[j] & 1) && !(v[n] & 1)){
				v[j] >>= 1;
				v[n] >>= 1;
				b[i][0] = 0;
				b[i][1] = j + 1;
				break;
			}
		}
		if(j < 4) continue;
		for(j = 0; j < 4; ++j){
			int n = next[j];
			if(v[j] & 1 && v[n] > 1 && v[n] & 1){
				v[j]++;
				v[n]++;
				b[i][0] = 1;
				b[i][1] = j + 1;
				break;
			} else if(v[j] & 1 && !(v[n] & 1) && v[next[n]] & 1){
				v[j]++; v[n]+= 2; v[next[n]]++;
				b[i][0] = 1;
				b[i][1] = j + 1;
				++i;
				b[i][0] = 1;
				b[i][1] = n + 1;
				break;
			}
		}
	}
	if(i >= 1000) puts("-1");
	else for(j = 0; j < i; ++j){
		if(b[j][0] == 0) printf("/%d\n", b[j][1]);
		else printf("+%d\n", b[j][1]);
	}
	return 0;
}

