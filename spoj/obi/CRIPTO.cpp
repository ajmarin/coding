#include <cstdio>
#include <algorithm>
struct charoc{
	char c;
	int n;
	bool operator()(charoc a, charoc b){
		return (a.n > b.n || (a.n == b.n && a.c < b.c));
	}
} oc[32];
char o[32], T[10050], map[32];
int main(void){
	int i, n, orig;
	for(int t = 1; scanf("%d%d\n",&n,&orig) && n; t++){
		for(i = 0; i < 32; i++)
			oc[i].c = i+'a', oc[i].n = 0;
		gets(o);		
		gets(T);
		for(i = 0; i < n; i++)
			if(T[i] != ' ') oc[T[i]-'a'].n++;
		std::sort(oc,oc+32,charoc());
		for(i = 0; oc[i].n; i++) map[oc[i].c-'a'] = o[i];
		for(i = 0; i < n; i++)
			if(T[i] != ' ') T[i] = map[T[i]-'a'];
		printf("Teste %d\n%s\n\n",t,T);
	}
	return 0;
}
