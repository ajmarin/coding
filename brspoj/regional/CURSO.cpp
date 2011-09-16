#include <cstdio>
#include <string>
#include <map>
#include <set>
 
using namespace std;
 
#define NN 256
 
int n, m, c, s;
map<string, int> discip;
string nomes[NN];
set<int> prereq[NN];
bool cursada[NN];
int num_cursadas;
int grade[NN][NN];
int ns[NN];
 
int insereDisc(string d) {
	if(discip.find(d) == discip.end()) return discip[d] = c++;
	return discip[d];
}
 
int main(void) {
	int i, j;
	char a[16], b[16];
	 
	while(scanf("%d %d", &n, &m) && (n || m)) {
		/* init */
		discip.clear();
		for(i = 0; i < NN; i++) {
			cursada[i] = false;
			prereq[i].clear();
			ns[i] = 0;
		}
		c = 0;
		 
		/* input */
		for(i = 0; i < n; i++) {
			int idA, idB;
			scanf("%s %d", a, &j);
			idA = insereDisc(string(a));
			nomes[idA] = a;
			while(j--) {
				scanf("%s", b);
				idB = insereDisc(string(b));
				nomes[idB] = b;
				prereq[idA].insert(idB);
			}
		}
		 
		/* processa */
		num_cursadas = 0;
		for(s = 0; num_cursadas < c; s++) {
			for(i = 0; i < c && ns[s] < m; i++) {
				if(cursada[i]) continue;
				if(prereq[i].empty()) {
					/* podemos cursar i */
					grade[s][ns[s]++] = i;
					cursada[i] = true;
					num_cursadas++;
				}
			}
			for(i = 0; i < ns[s]; i++) {
				/* retirar grade[s][i] dos prereqs */
				for(j = 0; j < c; j++)
					prereq[j].erase(grade[s][i]);
			}
		}
		 
		/* output */
		printf("Formatura em %d semestres\n", s);
		for(i = 0; i < s; i++) {
			set<string> di;
			printf("Semestre %d :", i + 1);
			for(j = 0; j < ns[i]; j++) di.insert(nomes[grade[i][j]]);
			for(set<string>::iterator it = di.begin(); it != di.end(); it++)
				printf(" %s", (*it).c_str());
			putc(10, stdout);
		}
	}
	return 0;
}

