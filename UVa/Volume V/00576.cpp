/////////////////////////////////
// 00576 - Haiku Review
/////////////////////////////////
#include<cstdio>
#include<cstring>
const char *end = "e/o/i", *y = "Y";
char *line[3], *word;
char haiku[220], syl[] = {5,7,5};
unsigned int csyl,i,j,len,line_num;
bool vowel[128],is_a_haiku;
int main(void){
	memset(vowel,0,sizeof(vowel));
	vowel['a'] = vowel['e'] = vowel['i'] =
	vowel['o'] = vowel['u'] = vowel['y'] = 1;
	while(gets(haiku) && strcmp(haiku,end)){
		is_a_haiku = 1;
		line[0] = strtok(haiku,"/");
		line[1] = strtok(NULL,"/");
		line[2] = strtok(NULL,"/");
		for(i = 0; i < 3; i++){
			csyl = 0;
			word = strtok(line[i]," ");
			while(word!=NULL){
				len = strlen(word);
				for(j = 0; j < len;)
					if(vowel[*(word+j)]){
						csyl++;
						while(j < len && vowel[*(word+j)])
							j++;
					}
					else j++;
				word = strtok(NULL," ");
			}
			if(csyl!=syl[i]){
				printf("%u\n",i+1);
				is_a_haiku = 0;
				break;
			}
		}
		if(is_a_haiku) puts(y);
	}
	return 0;
}

