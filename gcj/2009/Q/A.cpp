#include <cstdio>
#include <set>
#include <algorithm>
#include <cstring>
using namespace std;

struct word {
	char w[20];
	word(char *cc){
		strcpy(w,cc);
	}
	bool operator<(const word k) const{
		return strcmp(w,k.w) < 0;
	}
	word(){}
}dict[6000];
char poss[20][30], test[20];
bool oc[15][27];
bool dbg = 0;
int L, D, N, p;
int main(void){
	char *ptr, wwx[20], m[1000];
	int i, j, k, l, p_num, poss_pos;
	bool match;
	scanf("%d%d%d",&L,&D,&N);
	if(dbg) printf("L(%d)D(%d)N(%d)\n",L,D,N);
	memset(oc,0,sizeof(oc));
	for(i = 0; i < D; i++){
		scanf("%s",&wwx);
		dict[i] = word(wwx);
		for(j = 0; dict[i].w[j]; j++)
			oc[j][dict[i].w[j]-'a'] = 1;
		if(dbg) printf("%s ",dict[i].w);
	}
	getchar();
	for(i = 1; i <= N; i++){
		p = p_num = 0;
		fgets(m,1000,stdin);
		m[strlen(m)-1] = 0;
		if(dbg) printf("m = [%s]\n",m);
		for(j = p_num = 0; m[j]; j++, p_num++){
			poss_pos = 0;
			if(m[j] == '('){
				for(poss_pos = 0, k = j+1; m[k] != ')'; k++)
					if(oc[p_num][m[k]-'a']) poss[p_num][poss_pos++] = m[k];
				poss[p_num][poss_pos++] = 0;
				j = k;
			}
			else if(oc[p_num][m[j]-'a']){
				poss[p_num][0] = m[j];
				poss[p_num][1] = 0;
				poss_pos = 2;
			}
			if(dbg) printf("\t%s\n",poss[p_num]);
			if(poss_pos == 0) break; 
		}			
		if(poss_pos) {
			p = 0;
			for(j = 0; j < D; j++){
				for(k = 0; k < L; k++){
					for(match = l = 0; !match && poss[k][l]; l++)
						match = (poss[k][l] == dict[j].w[k]);
					if(!match) break;
				}
				if(k == L) p++;
			}
		}

		printf("Case #%d: %d\n",i,p);
		if(dbg) printf("-------\n");
	}
	return 0;
}

