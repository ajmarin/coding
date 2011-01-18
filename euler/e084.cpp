#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
using namespace std;
bool CC[40], CH[40];
int idx[40], R[40], U[40];
float np[40], p[40], t[40][40];
/* BOARD: ->
** GO A1 CC1 A2 T1 R1 B1 CH1 B2 B3 JAIL
** H2                              C1
** T2                              U1
** H1                              C2
** CH3                             C3
** R4                              R2
** G3                              D1
** CC3                             CC2
** G2                              D2
** G1                              D3
** G2J F3 U2 F2 F1 R3 E3 E2 CH2 E1 FP
*/
bool ind_ord(int x, int y){
	return p[x] > p[y];
}
int main(void){
	clock_t ini = clock();
	int ans = 0;
	for(int i = 0; i < 40; ++i) {
		CC[i] = 0;		
		for(int j = 0; j < 40; ++j)	t[i][j] = 0.0;
		/* Initially, the probability of being on any cell except GO is 0 */
		p[i] = 0;
		idx[i] = i;
	}
	CC[2] = CC[17] = CC[33] = 1; // Community Chests	
	CH[7] = CH[22] = CH[36] = 1; // Chance
	R[7] = 15; R[22] = 25; R[36] = 5; // Next railway (from chance)
	U[7] = 12; U[22] = 28; U[36] = 12;// Next utility zany (from chance)
	p[0] = 1;
	for(int i = 0; i < 40; ++i){
		if(i != 30){
			float z = 1.0 - (1 / (float) 4096);
			if(CC[i]) z *= 7 / (float) 8;
			if(CH[i]) z *= 3 / (float) 8;
			t[i][(i + 2)%40] = t[i][(i + 8)%40] = z * 1 / (float) 16;
			t[i][(i + 3)%40] = t[i][(i + 7)%40] = z * 2 / (float) 16;
			t[i][(i + 4)%40] = t[i][(i + 6)%40] = z * 3 / (float) 16;
			t[i][(i + 5)%40] = 					  z * 4 / (float) 16;
			if(CH[i]){
				z = (1.0 - (1 / (float) 4096)) * (5 / (float) 8);
				t[i][0]			= z / (float) 10; 	// Advance to GO card
				t[i][10] 		= z / (float) 10; 	// Go to JAIL card
				t[i][11]		= z / (float) 10; 	// Go to C1 card
				t[i][24]		= z / (float) 10; 	// Go to E3 card
				t[i][39]		= z / (float) 10; 	// Go to H2 card
				t[i][5]			= z / (float) 10; 	// Go to R1 card
				t[i][R[i]]		= 2*z / (float) 10;	// Go to next R 2cards
				t[i][U[i]]		= z / (float) 10; 	// Go to next U card
				t[i][(i+37)%40]	= z / (float) 10;	// Go back 3 squares.
			}
			if(CC[i]){
				z = (1.0 - (1 / (float) 4096)) * (1 / (float) 8);
				t[i][0] 		= z / (float) 2; // Advance to GO card
				t[i][10]		= z / (float) 2; // Go to JAIL card
			}
		} else t[i][10] = 1.0;
	}
	int lc = 0;
	for(float maxdiff = 1e10, cnt = .1; maxdiff > 1e-5; ++lc){
		maxdiff = 0;
		for(int x = 0; x < 40; ++x) np[x] = 0;
		for(int x = 0; x < 40; ++x)
			for(int y = 0; y < 40; ++y)
				np[x] += p[y] * t[y][x];		
		for(int x = 0; x < 40; ++x)
			maxdiff = max(maxdiff, fabs(p[x] - np[x]));
		memcpy(p, np, sizeof(p));
	}
		
	sort(idx, idx + 40, ind_ord);
	ans = 10000 * idx[0] + 100 * idx[1] + idx[2];
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d, #%d loops on markov chain\n", ans, lc);
	return 0;
}
