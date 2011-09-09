#include <cstdio>
#include <cstring>
#include <queue>
#include <string>
using namespace std;
char game[16];
const char * rl = "ABCD";
int r[4][4] = { { 0, 1, 4, 3 }, { 1, 2, 5, 4 }, { 3, 4, 7, 6 }, { 4, 5, 8, 7 }};
int fact[9] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320};
void rcw(char &a, char &b, char &c, char &d){
	char temp = d;
	d = c; c = b; b = a; a = temp;
}
void rccw(char &a, char &b, char &c, char &d){
	char temp = a;
	a = b; b = c; c = d; d = temp;
}
int pn(string s){
	int expected = 1, permutation_number = 0;
	bool used[9] = {false, false, false, false, false, false, false, false, false};
	for(int i = 0, z = 8; i < 9; ++i, --z){
		if(s[i] != expected){
			int cnt_b4 = 0;
			for(int j = expected; j < s[i] - '0'; ++j)
				cnt_b4 += !used[j];
			permutation_number += cnt_b4 * fact[z];
		}
		used[s[i] - '0'] = true;
		while(used[expected]) expected++;
	}
	return permutation_number;
}
int v[363000];
int main(void){
	for(int i = 0; i < 363000; ++i) v[i] = 0;
	for(int cnum = 1; scanf("%s", game) == 1 && strcmp(game, "0000000000"); cnum++){
		int m = game[0] - '0';
		queue < string > q;
		v[pn(game+1)] = (cnum << 4);
		q.push(game+1);
		while((v[0] >> 4) != cnum){
			string game_state = q.front();
			int depth = v[pn(game_state)] & 0xF;
			if(depth > m) break;
			q.pop();
			for(int rot = 0; rot < 4; ++rot){
				int idx, w = r[rot][0], x = r[rot][1], y = r[rot][2], z = r[rot][3];
				rcw(game_state[w], game_state[x], game_state[y], game_state[z]);
				idx = pn(game_state);
				if((v[idx] >> 4) != cnum){
					v[idx] = (cnum << 4) | (depth + 1);
					q.push(game_state);
				}
				rccw(game_state[w], game_state[x], game_state[y], game_state[z]);
				rccw(game_state[w], game_state[x], game_state[y], game_state[z]);
				idx = pn(game_state);
				if((v[idx] >> 4) != cnum){
					v[idx] = (cnum << 4) | (depth + 1);
					q.push(game_state);
				}
				rcw(game_state[w], game_state[x], game_state[y], game_state[z]);
			}
		}
		printf("%d. %d\n", cnum, (v[0]>>4) == cnum && (v[0]&0xF) <= m ? v[0]&0xF : -1);
	}
	return 0;
}

