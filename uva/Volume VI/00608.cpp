#include <cstdio>

#define FOR(i,n) for(int i = 0; i < n; ++i)
char c1[3][8], c2[3][8], pos[3][8];
bool cf[16], seen[16];

int main(void){
	int k, t; scanf("%d", &t);
	while(t--){
		FOR(i, 16) cf[i] = true, seen[i] = false;
		FOR(i, 3){
			scanf("%s %s %s", c1[i], c2[i], pos[i]);
			for(k = 0; c1[i][k]; ++k) seen[c1[i][k] - 'A'] = true;
			for(k = 0; c2[i][k]; ++k) seen[c2[i][k] - 'A'] = true;
		}
		FOR(i, 12){ 
			if(!seen[i]) continue;
			// Assume coin i is the counterfeit coin
			char coin = 'A' + i;
			bool valid = true;
			char left = 0, right = 0;
			FOR(j, 3){
				if(pos[j][0] == 'e'){ // cant find coin here
					for(k = 0; c1[j][k]; ++k) valid &= c1[j][k] != coin;
					for(k = 0; c2[j][k]; ++k) valid &= c2[j][k] != coin;
				} else { // must find it in this balance
					bool found = false;
					for(k = 0; c1[j][k]; ++k){
						found |= c1[j][k] == coin;
						if(c1[j][k] == coin){
							if(!left && !right) left = pos[j][0];
							else if(left) valid &= pos[j][0] == left;
							else valid &= pos[j][0] != right;
						}
					}
					for(k = 0; c2[j][k]; ++k){
						found |= c2[j][k] == coin;
						if(c2[j][k] == coin){
							if(!left && !right) right = pos[j][0];
							else if(left) valid &= pos[j][0] != left;
							else valid &= pos[j][0] == right;
						}
					}
					valid &= found;
				}
			}
			if(valid){
				if(!right) right = left == 'd' ? 'u' : 'd';
				printf("%c is the counterfeit coin and it is %s.\n", coin, right == 'u' ? "light" : "heavy");
			}

		}
	}
	return 0;
}

