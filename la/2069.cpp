#include <cstdio>
#include <cstring>
#include <string>
#include <map>

using namespace std;

int oc[1000];
map < string, int > msi;
map < string, int > :: iterator it;
char line[10000];

struct player {
	double s;
	int is;
	char n[25];
	string word[25];
	int wc;
} p[15];

int main(void){
	int N, nn, rn = 0;
	while(scanf("%d\n", &N) && N){
		nn = 0;
		msi.clear();
		for(int i = 0; i < 1000; ++i) oc[i] = 0;
		for(int i = 0; i < N; ++i){
			p[i].s = p[i].wc = 0;
			fgets(line, 10000, stdin);
			line[strlen(line) - 1] = 0;
			char *ptr = strtok(line, " ");
			strcpy(p[i].n, ptr);
			ptr = strtok(NULL, " ");
			while(ptr != NULL){
				int x;
				string w = string(ptr);
				p[i].word[p[i].wc++] = w;
				if(msi.find(w) == msi.end()) msi[w] = nn++;
				x = msi[w];
				oc[x]++;
				ptr = strtok(NULL, " ");
			}
		}
		int max_s = 0;
		for(int i = 0; i < N; ++i){
			for(int j = 0; j < p[i].wc; ++j){
				int k = msi[p[i].word[j]];
				p[i].s += p[i].word[j].length()/(double)oc[k];
			}
			p[i].is = (int) (p[i].s * 1000);
			if(p[i].is > max_s) max_s = p[i].is;
			//printf("%s score = %.3lf\n", p[i].n, p[i].s);
		}
		bool f = 1;
		printf("Round %d\n", ++rn);
		for(int i = 0; i < N; ++i)
			if(p[i].is == max_s){
				if(!f) putc(' ', stdout);
				printf("%s", p[i].n);
				f = 0;
			}
		putc(10, stdout);

	}

	return 0;
}

