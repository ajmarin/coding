#include <cstdio>
#include <map>
#include <string>
using namespace std;
int win[3][3];
map < string, int > ml, mg[9];
/*
** 0 = Paper
** 1 = Scissor
** 2 = Rock
*/
char line[2048];
char p1n[32], p1p[32], p2n[32], p2p[32], l1[4], l2[4];
const char *name[3] = {"Paper", "Scissors", "Rock"};
int main(void){
	/* Game situations */
	win[0][0] = win[1][1] = win[2][2] = -1;
	win[0][1] = win[1][2] = win[2][0] = 1;
	win[1][0] = win[2][1] = win[0][2] = 0;
	/* Languages */
	ml[string("cs")] = 0; ml[string("en")] = 1; ml[string("fr")] = 2;
	ml[string("de")] = 3; ml[string("hu")] = 4; ml[string("it")] = 5;
	ml[string("jp")] = 6; ml[string("pl")] = 7; ml[string("es")] = 8;
	/* Rock */
	mg[0][string("Kamen")] = mg[1][string("Rock")] = mg[2][string("Pierre")] = 2;
	mg[3][string("Stein")] = mg[4][string("Ko")] = mg[4][string("Koe")] = mg[5][string("Sasso")] = 2;
	mg[5][string("Roccia")] = mg[6][string("Guu")] = mg[7][string("Kamien")] = mg[8][string("Piedra")] = 2;
	/* Scissors */
	mg[0][string("Nuzky")] = mg[1][string("Scissors")] = mg[2][string("Ciseaux")] = mg[3][string("Schere")] = 1;
	mg[4][string("Ollo")] = mg[4][string("Olloo")] = mg[5][string("Forbice")] = mg[6][string("Choki")] = 1;
	mg[7][string("Nozyce")] = mg[8][string("Tijera")] = 1;
	/* Paper */
	mg[0][string("Papir")] = mg[1][string("Paper")] = mg[2][string("Feuille")] = mg[3][string("Papier")] = 0;
	mg[4][string("Papir")] = mg[5][string("Carta")] = mg[5][string("Rete")] = mg[6][string("Paa")] = 0;
	mg[7][string("Papier")] = mg[8][string("Papel")] = 0;
	fgets(line, 1024, stdin);
	for(int i = 0; line[0] != '.'; ){
		int p1l, p2l, p1s = 0, p2s = 0;
		sscanf(line, "%s %s", l1, p1n);
		fgets(line, 1024, stdin);
		sscanf(line, "%s %s", l2, p2n);
		p1l = ml[string(l1)]; p2l = ml[string(l2)];
		while(fgets(line, 1024, stdin) && line[0] != '-' && line[0] != '.'){
			sscanf(line, "%s %s", p1p, p2p);
			int a = mg[p1l][string(p1p)], b = mg[p2l][string(p2p)];
			p1s += win[a][b] == 0;
			p2s += win[a][b] == 1;
		}
		printf("Game #%d:\n", ++i);
		printf("%s: %d point", p1n, p1s);
		if(p1s != 1) putc('s', stdout);
		putc(10, stdout);
		printf("%s: %d point", p2n, p2s);
		if(p2s != 1) putc('s', stdout);
		putc(10, stdout);
		if(p1s > p2s) printf("WINNER: %s\n", p1n);
		else if(p1s < p2s) printf("WINNER: %s\n", p2n);
		else printf("TIED GAME\n");
		putc(10, stdout);
		fgets(line, 1024, stdin);
	}
	return 0;
}

