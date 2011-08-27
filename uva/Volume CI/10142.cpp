#include <cstdio>
#include <cstdlib>
#include <cstring>

//#define DBG
const int MAXC = 32, MAXV = 1024;
int opt[MAXV][MAXC], pos[MAXV];
int votes[MAXC];
char names[MAXC][128];
bool invalid[MAXC];
char line[10048];
int main(void){
	int T; scanf("%d", &T);
	while(T--){
		int N; scanf("%d\n", &N);
		int voters = 0;
		for(int i = 0; i < N; ++i){
			fgets(names[i], 128, stdin);
			for(int j = 0; names[i][j]; ++j)
				if(names[i][j] == '\n') names[i][j] = 0;
			votes[i] = 0;
			invalid[i] = 0;
		}
		int z;
		for(voters = 0; fgets(line, 10048, stdin) && sscanf(line, "%d", &z) == 1; ++voters){
			char *num = strtok(line, " \t");
			pos[voters] = -1;
			for(int j = 0; j < N; ++j){
				opt[voters][j] = atoi(num) - 1;
				num = strtok(NULL, " \t");
			}
		}
		int min_votes, max_votes, candidates = N, winner = -1;
		for(; candidates > 0;){
			for(int i = 0; i < voters; ++i){
				if(pos[i] > -1 && !invalid[opt[i][pos[i]]]) continue;
				pos[i] += pos[i] == -1;
				while(invalid[opt[i][pos[i]]] && pos[i] < N) ++pos[i];
				++votes[opt[i][pos[i]]];
			}
			/* find min_votes and max_votes */
			max_votes = 0;
			min_votes = MAXV;
			for(int i = 0; i < N; ++i){
				if(invalid[i]) continue;
				if(votes[i] < min_votes) min_votes = votes[i];
				if(votes[i] > max_votes) max_votes = votes[i];
				if(votes[i] > voters/2){
					winner = i;
					break;
				}
			}
			/* eliminate candidates */
			for(int i = 0; i < N; ++i)
				if(votes[i] == min_votes){
					invalid[i] = 1;
					candidates--;
				}
			if(winner != -1) break;
		}
		if(winner != -1) puts(names[winner]);
		else for(int i = 0; i < N; ++i)
			if(votes[i] == max_votes) puts(names[i]);
		if(T) puts("");
	}
	return 0;
}

