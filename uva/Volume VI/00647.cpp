#include <cstdio>

int chute[128], die[1024], ladder[128], square[8];
bool miss_next[128], play_again[128];
bool lose_next[8];

int main(void){
	for(int i = 0; scanf("%d", die + i) == 1 && die[i]; ++i);
	for(int players; scanf("%d", &players) == 1 && players; ){
		/* Initialize game state */
		for(int i = 0; i < players; ++i){
			square[i] = 0;
			lose_next[i] = false;
		}
		for(int i = 0; i < 128; ++i){
			chute[i] = ladder[i] = 0;
			miss_next[i] = play_again[i] = false;
		}
		/* Read chutes and ladders */
		for(int from, to; scanf("%d %d", &from, &to) == 2 && (from || to); ){
			if(from < to) ladder[from] = to;
			else chute[from] = to;
		}
		/* Read miss_turn and play_again squares */
		for(int z; scanf("%d", &z) == 1 && z; ){
			if(z > 0) play_again[z] = true;
			else miss_next[-z] = true;
		}
		/* Simulate the game */
		int p; // Currently player number
		for(int i = p = 0; ; ++i){
			if(lose_next[p]){
				lose_next[p] = false;
				--i;
			} else if(square[p] + die[i] <= 100){
				square[p] = square[p] + die[i];
				while(true){
					if(ladder[square[p]]) square[p] = ladder[square[p]];
					else if(chute[square[p]]) square[p] = chute[square[p]];
					else break;
				}
				if(square[p] == 100) break;
				if(play_again[square[p]]) p = (p + 5) % players;
				if(miss_next[square[p]]) lose_next[p] = true;
			}
			p = (p + 1) % players;
		}
		printf("%d\n", p + 1);
	}

	return 0;
}

