#include <algorithm>
#include <cmath>
#include <cstdio>
#include <ctime>

using namespace std;

#define FOR(a, b) for(int a = 0; a < b; ++a)
#define FORI(a,b,c) for(int a = b; a < c; ++a)
#define S(x) ((x) & 3)
#define V(x) ((x) >> 2)

char v[128];
struct hand {
	char c[5], s[5];
	int score;
} h[2];

int high_card(int p){
	return h[p].c[4];
}
int one_pair(int p){
	FOR(i, 4) if(h[p].c[i] == h[p].c[i+1]) return 1000 + h[p].c[i];
	return 0;
}
int two_pairs(int p){
	if( (h[p].c[0] == h[p].c[1] || h[p].c[1] == h[p].c[2]) && 
		(h[p].c[3] == h[p].c[4] || h[p].c[3] == h[p].c[2]))
			return 2000 + h[p].c[1] + h[p].c[3];
	return 0;
}
int three_of_a_kind(int p){
	FOR(i, 3) if(h[p].c[i] == h[p].c[i+1] && h[p].c[i+1] == h[p].c[i+2])
		return 3000 + h[p].c[2];
	return 0;
}
int straight(int p){
	FOR(i, 4) if(h[p].c[i] + 1 != h[p].c[i+1]) return 0;
	if(h[p].c[4] == 14 && h[p].c[0] == 2) return 4014;
	if(h[p].c[4] == h[p].c[3] + 1) return 4000 + h[p].c[4];
	return 0;
}
int flush(int p){
	FOR(i, 4) if(h[p].s[i] != h[p].s[i+1]) return 0;
	return 5000 + h[p].c[4];
}
int full_house(int p){
	if(h[p].c[0] == h[p].c[1]){
		if(h[p].c[1] == h[p].c[2] && h[p].c[3] == h[p].c[4])
			return 6000 + h[p].c[2];
		if(h[p].c[2] == h[p].c[3] && h[p].c[3] == h[p].c[4])
			return 6000 + h[p].c[2];
	}
	return 0;
}
int four_of_a_kind(int p){
	int k;
	for(k = 0; k < 3; ++k) if(h[p].c[k] != h[p].c[k+1]) break;
	if(k == 3) return 7000 + h[p].c[2];
	for(k = 1; k < 4; ++k) if(h[p].c[k] != h[p].c[k+1]) break;
	if(k == 4) return 7000 + h[p].c[2];
	return 0;
}
int straight_flush(int p){
	int a = flush(p), b = straight(p);
	return a ? 9000 + b % 100 : 0;
}

int (*f[10]) (int a) = { &straight_flush, &four_of_a_kind, &full_house,
						 &flush, &straight, &three_of_a_kind, &two_pairs,
						 &one_pair, &high_card };
int main(void){
	clock_t ini = clock();
	int ans = 0;
	char card[3];
	FORI(i, '2', '9' + 1) v[i] = i - '0';
	v['A'] = 14; v['T'] = 10; v['J'] = 11; v['Q'] = 12; v['K'] = 13;
	v['C'] = 1; v['D'] = 2; v['H'] = 3; v['S'] = 4;
	FOR(i, 1000){
		FOR(p, 2){
			h[p].score = 0;
			FOR(j, 5){
				scanf("%s", card);
				h[p].c[j] = v[card[0]];
				h[p].s[j] = v[card[1]];
			}
			sort(h[p].c, h[p].c + 5);
			for(int a = 0; !h[p].score; ++a) h[p].score = f[a](p);
		}
		for(int a = 4; h[0].score == h[1].score; --a){
			h[0].score += h[0].c[a];
			h[1].score += h[1].c[a];
		}
		ans += h[0].score > h[1].score;
	}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}
