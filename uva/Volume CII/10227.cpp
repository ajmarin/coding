#include <cstdio>
const int NN = 128;
int adj[NN][NN];
int T, P;
char line[1024];
bool same_opinion(int a, int b){
	for(int i = 0; i < T; ++i)
		if(adj[a][i] != adj[b][i]) return false;
	return true;
}
int main(void){
	int cases; scanf("%d", &cases);
	while(cases--){
		scanf("%d %d\n", &P, &T);
		for(int i = 0; i < P; ++i)
			for(int j = 0; j < T; ++j)
				adj[i][j] = 0;
		for(int person, tree; fgets(line, 1024, stdin) && sscanf(line, "%d %d", &person, &tree) == 2; )
			adj[--person][--tree] = 1;
		int opinions = 0;
		for(int i = 0; i < P; ++i){
			bool new_opinion = true;
			for(int j = 0; j < i && new_opinion; ++j)
				new_opinion &= !same_opinion(i, j);
			opinions += new_opinion;
		}
		printf("%d\n", opinions);
		if(cases) puts("");
	}
	return 0;
}

