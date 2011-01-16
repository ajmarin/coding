/////////////////////////////////
// 00123 - Searching Quickly
/////////////////////////////////
#include<cstdio>
#include<cstring>
#include<string>
#include<set>
using namespace std;
set < string > s;
char ignore[100];
char title[1000];
char temp[1000];
char * part;
int i, idxnum;
struct KWIK {
	int n;
	char key[1000];
	char phrase[1000];
	bool operator()(KWIK a, KWIK b){
		int cmp = strcmp(a.key,b.key);
		return (cmp<0 || (cmp==0 && a.n < b.n));
	}
} idx[1000];
int main(void){
	idxnum = 0;
	gets(ignore);
	while(strcmp(ignore,"::")){
		for(i = 0; ignore[i]; i++) if(isupper(title[i])) ignore[i] += 32;
		s.insert(string(ignore));
		gets(ignore);
	}
	while(gets(title)){
		int t_len = 0, len_now;
		for(i = 0; title[i]; i++) if(isupper(title[i])) title[i] += 32;
		strcpy(temp,title);
		part = strtok(temp," ");		
		while(part!=NULL){
			len_now = strlen(part);			
			if(s.find(part) == s.end()){
				strcpy(idx[idxnum].key,part);
				strcpy(idx[idxnum].phrase,title);
				idx[idxnum].n =idxnum;
				for(i = t_len; i < t_len+len_now; i++) idx[idxnum].phrase[i] -= 32;
				idxnum++;
			}
			t_len += len_now+1;
			part = strtok(NULL," ");
		}
	}
	sort(idx,idx+idxnum,KWIK());
	for(i = 0; i < idxnum; i++)
		puts(idx[i].phrase);
	return 0;
}
