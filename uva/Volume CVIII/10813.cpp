#include <cstdio>

#define FOR(i,n) for(int i = 0; i < n; ++i)
int card[5][5];
bool marked[5][5];

void mark(int k){
	FOR(i, 5) FOR(j, 5) if(card[i][j] == k){
		marked[i][j] = true;
		return;
	}
}

int check_win(){
	int sum;
	FOR(i, 5){
		/* Check line i */
		sum = 0;
		FOR(j, 5) sum += marked[i][j];
		if(sum == 5) return true;
		sum = 0;
		/* Check column i */
		FOR(j, 5) sum += marked[j][i];
		if(sum == 5) return true;
	}
	/* Check diag */
	sum = 0;
	FOR(i, 5) sum += marked[i][i];
	if(sum == 5) return true;
	/* Check other diag */
	sum = 0;
	FOR(i, 5) sum += marked[i][4 - i];
	if(sum == 5) return true;
	return false;
}
int main(void){
	int t; scanf("%d", &t);
	marked[2][2] = true;
	card[2][2] = -1;
	while(t--){
		int turns = -1, z;
		FOR(i, 25){
			if(i == 12) continue;
			scanf("%d", &z);
			card[i / 5][i % 5] = z;
			marked[i / 5][i % 5] = false;
		}
		FOR(i, 75){
			scanf("%d", &z);
			mark(z);
			if(turns == -1 && check_win()) turns = i + 1;
		}
		printf("BINGO after %d numbers announced\n", turns);
	}
	return 0;
}

