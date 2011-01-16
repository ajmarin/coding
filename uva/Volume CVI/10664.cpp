/////////////////////////////////
// 10664 - Luggage
/////////////////////////////////
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
unsigned int cnum, n, sum;
const char *yes = "YES", *no = "NO";
char line[10000],*ptr;
vector<unsigned int> w,p;
vector<unsigned int>::iterator wit, pit;
set<unsigned int> poss;
set<unsigned int>::iterator sit;
bool possible;
int main(void){
	scanf("%u\n",&cnum);
	while(cnum--){
		w.clear(); poss.clear(); possible = sum = 0; gets(line);
		ptr = strtok(line," ");
		while(ptr != NULL){
			n = atoi(ptr);
			sum += n;
			w.push_back(n);
			ptr = strtok(NULL," ");
		}
		if(sum&1) puts(no);
		else {
			for(wit = w.begin(); wit != w.end(); wit++){
				p.clear();
				for(sit = poss.begin(); sit != poss.end(); sit++)
					p.push_back((*sit)+(*wit));
				for(pit = p.begin(); pit != p.end(); pit++)
					poss.insert(*pit);
				poss.insert(*wit);
				if(poss.find(sum>>1)!=poss.end()){ possible = 1; break;}
			}
			if(possible) puts(yes);
			else puts(no);
		}
	}
	return 0;
}

