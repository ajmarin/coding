#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 1000000
#define M10 100000
#define SQMAX 1001
#define PMAX 80000
#define L(a,i,f,inc) for(a = i; a < f; a+=inc)
bool s[MAX];
char d[4] = {2,4,2,2};
int f[PMAX], p[PMAX], r[PMAX];

int revbig(int k){
	int o = k, r = 0;
	while(k){
		r = (r<<3)+(r<<1)+k%10;
		k /= 10;
	}
	while(r < M10) r *= 10;
	return r;
}
int bin_search(int k, int n){
	int c, u, v;
	k = k/10;
	for(u = 0, v = n; u < v; ){
		c = (u + v) >> 1;
		if(r[c] == k) return c;
		if(r[c] > k) v = c; else u = c+1;
	}
}
int main(void){
	int add, c, i, j, k, sum;
	char o;
	memset(s, 1, MAX);
	memset(f, 0, PMAX<<2);
	L(i, 4, MAX, 2) s[i] = 0;
	L(i, 3, SQMAX, 2) if(s[i])
		L(j, i*i, MAX, i) s[j] = 0;
	p[0] = 2; p[1] = 3; p[2] = 5; p[3] = 7;
	L(i, 0, 4, 1) r[i] = revbig(p[i]);	
	for(c = 4, i = 11; i < MAX; ){
		for(j = 0; j < 4; i+=d[j], j++)
			if(s[i]){
				p[c] = i;
				r[c] = revbig(p[c++]);
			}
	}
	sort(r,r+c);
	for(i = 0; i < c; i++){
		k = r[i];
		for(j = 0; !s[k]; j++)
			while(!(k%p[j])){
				k /= p[j];
				f[i]++;
			}
		f[i] = f[i]+2+(k!=1);
		if(i) f[i] += f[i-1];
	}
	memset(s, 0, c);
	while(scanf("%c %d\n", &o, &k) != EOF){
		if(o == 'q'){
			for(add = i = sum = 0; add <= k; i++)
				if(!s[i]) sum += f[i], add++;
			printf("%d\n",sum);
		} else s[bin_search(k,c)] = 1;
	}
	return 0;
}
