/////////////////////////////////
// 10295 - Hay Points
/////////////////////////////////
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
struct hayword {
	char w[18];
	unsigned int v;
	bool operator()(hayword a, hayword b){
		return(strcmp(a.w,b.w)<0);
	}
}words[1000];
unsigned int haypoint,i,m,n,s,u,v;
char *word,*value, line[1000000];
int search(const char *s){
	int c,cmp; bool found = 0;
	for(u = 0, v = m; u < v; ){
		c = (u+v)/2;
		cmp = strcmp(words[c].w,s);
		if(cmp<0) u = c+1; 
		else if(cmp>0)v = c;
		else { found = true; break; }
	}
	if(found) return c;
	else return -1;
}
int main(void){
	scanf("%u %u\n",&m,&n);
	for(i = 0; i < m; i++){
		gets(line);
		word = strtok(line," ");
		strcpy(words[i].w,word);
		value = strtok(NULL," ");
		words[i].v = atoi(value);		
	}
	sort(words,words+m,hayword());
	while(n--){
		haypoint = 0;
		while(gets(line) && line[0] != '.'){
			word = strtok(line," ");
			while(word!=NULL){
				s = search(word);
				if(s!=-1) haypoint += words[s].v;
				word = strtok(NULL," ");
			}
			
		}
		printf("%u\n",haypoint);
	}
}
