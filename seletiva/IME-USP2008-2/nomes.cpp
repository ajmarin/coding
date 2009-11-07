#include<cstdio>
#include<map>
#include<set>
#include<string>
using namespace std;
int p_f[350][350], p_m[350][350],idx[350];
int married_f[350];
int i, j, n, t;
char tname[350][20], name[50];
map < string , int > m;
set < int > s;
int main(void){
	scanf("%d",&t);
	while(t--){
		m.clear();
		s.clear();		
		scanf("%d",&n);
		/* INPUT */
		for(i = 1; i <= n; i++){
			idx[i] = 1;
			s.insert(i);
			scanf("%s",&tname[i]);
			m[string(tname[i])] = i;
			for(j = 1; j <= n; j++) scanf("%d",&p_m[i][j]);//, printf(" %d",p_m[i][j]);
			//putchar('\n');
		}
		//putchar('\n');
		for(i = 1; i <= n; i++){
			//putchar('\n');
			married_f[i] = 0;
			for(j = 1; j <= n; j++)
				scanf("%s",&name),
				p_f[i][j] = m[string(name)];
				//printf(" %d",p_f[i][j]);
		}
		/* ALGORITHM */
		while(s.begin() != s.end()){
			int x = *s.begin();
			int wants = p_m[x][idx[x]];
			//printf("Homem : %d, quer %d\n",x,wants);
			if(married_f[wants] == 0){
				married_f[wants] = x;
				s.erase(s.begin());
				//printf("%d is married to %d\n",x,wants);
			}
			else {
				int mto = married_f[wants];
				//printf("%d ALREADY married to %d\n",mto,wants);
				for(i = 1; p_f[wants][i] != x && p_f[wants][i] != mto; i++);
				if(p_f[wants][i] == x){
					married_f[wants] = x;
					s.erase(s.begin());
					s.insert(mto);					
					//printf("%d is married to %d\n",x,wants);
				}
				else idx[x]++;
			}
		}
		for(i = 1; i <= n; i++) puts(tname[married_f[i]]);
		putchar('\n');
		/*for(typeof(s.begin())it=s.begin(); it != s.end(); it++)
			printf(" Homem %d, prefere %d\n",*(it),p_m[*(it)][idx[*(it)]]);*/
	}
	return 0;
}
