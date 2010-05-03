#include <cstdio>

#define N 1001
int f[1001][16], fc[1001];
int mp[101][1001];

void factor(int k){
	int a = k;
	fc[a] = 0;
	for(int i = 2; ; i++){
		if(i * i > k) break;
		if(!(k % i)){
			f[a][fc[a]++] = i;
			while(!(k % i)) k /= i;
		}
	}
	if(k > 1 && fc[a]) f[a][fc[a]++] = k;
}

void explode(int begin, int now){
	for(int i = fc[now]; i--; ){
		int temp = now + f[now][i], sc;
		if(temp >= N) continue;
		sc = 1 + mp[begin][now];
		if(mp[begin][temp] == -1 || sc < mp[begin][temp]){
			mp[begin][temp] = sc;
			explode(begin, temp);
		}
	}
}


int main(void){
	for(int i = 1; i < N; ++i) factor(i);
	for(int i = 1; i < 101; ++i) 
		for(int j = 1; j < N; ++j) 
			mp[i][j] = (i == j) - 1;
	for(int i = 1; i < 101; ++i) explode(i, i);
	for(int cnum = 1, s, t; scanf("%d %d", &s, &t) && s; cnum++)
		printf("Case %d: %d\n", cnum, mp[s][t]);
	return 0;
}

