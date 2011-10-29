#include <algorithm>
#include <cstdio>

#define FORI(i,s,n) for(int i = s; i < n; ++i)

int ans[21], cnt[128], L[128], ls, test[21];
bool must[21], valid[21];
char desc[128];
int count_in_sol, len, marked_wins, min_card, needed;

void put(int x, int dd, int n){
	test[n] = x;
	for(int i = 0; i < ls && L[i] + x < len; ++i){
		marked_wins += !cnt[x + L[i]];
		cnt[x + L[i]] += dd;
		marked_wins -= !cnt[x + L[i]];
	}
}

void bt(int n, int idx){
	if(marked_wins == needed && n < min_card){
		min_card = n;
		FORI(i, 0, n) ans[i] = test[i];
		return;
	}
	if(count_in_sol >= min_card) return;
	FORI(i, idx, 21) if(valid[i]){
		put(i, 1, n);
		bt(n + 1, i + 1);
		put(i, -1, n);
	}
}

int main(void){
	int j, t; scanf("%d", &t);
	for(int cnum = 1; t--; ++cnum){
		desc[0] = 'L';
		ls = 0;
		min_card = 21;
		scanf("%s", desc+1);
		for(len = 0; desc[len]; ++len){
			if(desc[len] == 'L') L[ls++] = len;
			cnt[len] = 0;
		}
		needed = len - ls;
		// Mark which numbers are valid
		FORI(i, 1, 21){
			must[i] = 0;
			valid[i] = i < len;
			for(j = 0; valid[i] && j < ls && L[j] + i < len; ++j)
				valid[i] &= desc[i + L[j]] == 'W';
			if(valid[i]) put(i, 1, 0);
		}
		// Find which numbers must be in the set
		FORI(i, 1, 21) if(valid[i]) for(j = 0; j < ls && L[j] + i < len; ++j)
			must[i] |= cnt[i + L[j]] == 1;
		FORI(i, 0, len) cnt[i] = 0;
		count_in_sol = marked_wins = 0;
		// Insert numbers that must be in the set
		FORI(i, 1, 21) if(must[i]) put(i, 1, count_in_sol++), valid[i] = false;
		// Backtrack to find the remaining ones
		bt(count_in_sol, 1);
		// Show answer
		printf("Case %d:", cnum);
		if(needed == 0) ans[0] = len, min_card = 1;
		std::sort(ans, ans + min_card);
		FORI(i, 0, min_card) printf(" %d", ans[i]);
		puts("");
	}
	return 0;
}

