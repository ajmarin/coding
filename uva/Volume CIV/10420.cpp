/////////////////////////////////
// 10420 - List of Conquests
/////////////////////////////////
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
unsigned int cnum,i,j,n;
char *cname, *wn, line[400];
struct country{
	char name[100];
	unsigned int count;
	bool operator()(country a, country b){
		return (strcmp(a.name,b.name)<0);
	}
}c[2000];
int main(void){
	scanf("%u\n",&n);
	cnum = 0;
	while(n--){
		gets(line);
		cname = strtok(line," ");		
		for(i = 0; i != cnum; i++) 
			if(strcmp(cname,c[i].name)==0) break;
		if(i != cnum){
			c[i].count++;
		} else {
			strcpy(c[i].name,cname);
			c[cnum++].count = 1;
		}
	}
	sort(c,c+cnum,country());
	for(i = 0; i != cnum; i++)
		printf("%s %u\n",c[i].name,c[i].count);
	return 0;
}
	
