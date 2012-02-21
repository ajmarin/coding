#include <cstdio>
#include <string>
#include <tr1/unordered_map>
using namespace std;
using namespace tr1;

unordered_map< string, int > m;

int cmp(int a, int b){ return (a > b) - (a < b); }
int main(void){
	for(int g, p; scanf("%d %d", &p, &g) == 2; ){
		char comp[32], word[32];
		m.clear();
		for(int v1, v2; p-- && scanf("%s %d.%d", word, &v1, &v2) == 3; ) m[word] = v1*10 + v2;
		for(int gn = 0, v; gn++ < g; ){
			int correct, sum = 0;
			while(true){
				scanf("%s %s", word, comp);
				sum += m[word];
				if(*comp == '+') continue;
				scanf("%d", &v);
				v *= 10;
				if(*comp == '<'){
					if(*(comp + 1) == '=') correct = sum <= v;
					else correct = sum < v;
				} else if(*comp == '>'){
					if(*(comp + 1) == '=') correct = sum >= v;
					else correct = sum > v;
				} else correct = sum == v;
				printf("Guess #%d was %s.\n", gn, correct ? "correct" : "incorrect");
				sum = 0;
				break;
			}
		}
	}
	return 0;
}

