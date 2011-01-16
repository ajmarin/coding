/////////////////////////////////
// 00156 - Ananagrams
/////////////////////////////////
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char line[90],*ptr,words[1000][22],aux[22];
int i,j,c = 0;
bool ananagram[1000];
void b_sort(){
int result;
	for(i = 0; i < c-1; i++)
		for(j = 0; j < c-1-i; j++){
			result = strcmp(words[j],words[j+1]);
		if(result > 0){
			strcpy(aux, words[j+1]);
			strcpy(words[j+1],words[j]);
			strcpy(words[j],aux);
		}
	}
}
bool anagram(char *a, char *b){
	int lena = strlen(a),lenb = strlen(b);
	if(lena != lenb) return 0;
	int i,j;
	int match = 0;
	int sa[lena], sb[lenb], used[lena];
	for(i = 0; i < lena; i++){
		used[i] = 0;
		if(a[i] < 97) sa[i] = a[i]+32;
		else sa[i] = a[i];
		if(b[i] < 97) sb[i] = b[i]+32;
		else sb[i] = b[i];
	}      
	for(i = 0; i < lena; i++){
		for(j = 0; j < lenb; j++){                              
			if(used[j]) continue;
			if(sa[i] == sb[j]) {                                    
				used[j] = 1;
				match++;
				break;
			}
		}
		if(match != (i+1)) return 0;
	}
	return 1;
}
void check(){
	for(i = 0; i < c-1; i++){
		if(!ananagram[i]) continue;
		for(j = i+1; j < c; j++){
			if(anagram(words[i],words[j])){
				ananagram[i] = false;
				ananagram[j] = false;
			}
		}
	}
	for(i = 0; i < c; i++)
		if(ananagram[i]) printf("%s\n",words[i]);      
}

int main(void){
	for(i = 0; i < 1000; ananagram[i] = 1, i++);
	while(gets(line)){
		if(line[0] == '#') break;
		ptr = strtok(line," ");
		while(ptr!=NULL){
			strcpy(words[c++], ptr);
			ptr = strtok(NULL," ");
		}
	}
	b_sort();
	check();
	return 0;
}